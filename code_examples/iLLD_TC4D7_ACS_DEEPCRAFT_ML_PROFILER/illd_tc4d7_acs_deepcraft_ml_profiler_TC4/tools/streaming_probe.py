#!/usr/bin/env python3
"""
streaming_probe.py - quick diagnostics for the AURIX DEEPCRAFT streaming firmware.

The firmware speaks the Imagimob/DEEPCRAFT streaming protocol (length-delimited
protobuf) over ASCLIN0 as a raw serial stream. It sends nothing until the host
asks, so this tool actively sends a BoardCapabilitiesRequest and reads the reply
to confirm the board is alive on a given port/baud - useful when the device does
not show up in DEEPCRAFT Studio.

Requires: pyserial  ->  pip install pyserial

Examples:
    python streaming_probe.py list
    python streaming_probe.py probe --port COM7 --baud 3000000
    python streaming_probe.py scan                       # every port, default baud
    python streaming_probe.py scan --baud 3000000,921600,115200
"""

import argparse
import socket
import sys
import time

try:
    import serial
    from serial.tools import list_ports
except ImportError:
    sys.exit("pyserial is required. Install it with:  pip install pyserial")


DEFAULT_BAUD = 3000000
DEFAULT_TCP_PORT = 14325


class TcpTransport:
    """Minimal pyserial-compatible wrapper over a TCP socket, so the existing
    varint/delimited read helpers and command flows work unchanged against the
    Ethernet (TCP) transport."""

    def __init__(self, host, port, timeout=0.05, write_timeout=2.0):
        self.sock = socket.create_connection((host, port), timeout=5.0)
        self.sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        self._timeout = timeout
        self.sock.settimeout(timeout)

    @property
    def timeout(self):
        return self._timeout

    @timeout.setter
    def timeout(self, value):
        self._timeout = value
        self.sock.settimeout(value)

    def read(self, size=1):
        try:
            return self.sock.recv(size)
        except (socket.timeout, TimeoutError):
            return b""
        except OSError:
            return b""

    def write(self, data):
        self.sock.sendall(data)
        return len(data)

    def flush(self):
        pass

    def reset_input_buffer(self):
        self.sock.setblocking(False)
        try:
            while self.sock.recv(65536):
                pass
        except (BlockingIOError, OSError):
            pass
        finally:
            self.sock.settimeout(self._timeout)

    def reset_output_buffer(self):
        pass

    def close(self):
        try:
            self.sock.close()
        except OSError:
            pass

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()


def open_transport(args, read_timeout=0.05, write_timeout=2.0):
    """Open a TCP transport (--tcp HOST[:PORT]) or a serial port, per args."""
    tcp = getattr(args, "tcp", None)
    if tcp:
        host, sep, port = tcp.partition(":")
        return TcpTransport(host, int(port) if sep and port else DEFAULT_TCP_PORT,
                            timeout=read_timeout, write_timeout=write_timeout)
    if not getattr(args, "port", None):
        raise ValueError("either --port (serial) or --tcp HOST[:PORT] is required")
    return serial.Serial(args.port, args.baud, timeout=read_timeout,
                         write_timeout=write_timeout)


def transport_label(args):
    tcp = getattr(args, "tcp", None)
    return tcp if tcp else f"{args.port} @ {args.baud}"


# --------------------------------------------------------------------------- #
# Minimal protobuf helpers (varint + the tiny messages we need)
# --------------------------------------------------------------------------- #
def encode_varint(value: int) -> bytes:
    out = bytearray()
    while True:
        b = value & 0x7F
        value >>= 7
        if value:
            out.append(b | 0x80)
        else:
            out.append(b)
            return bytes(out)


def zigzag(value: int) -> int:
    return (value << 1) ^ (value >> 31) if value < 0 else (value << 1)


def build_capabilities_request(device: int = -1) -> bytes:
    """
    Request{ capabilities = BoardCapabilitiesRequest{ device } } sent length-delimited.

    field 1 (device, sint32, varint) in BoardCapabilitiesRequest
    field 1 (capabilities, message) in Request
    """
    cap = bytes([0x08]) + encode_varint(zigzag(device))          # device = <n>
    request = bytes([0x0A]) + encode_varint(len(cap)) + cap      # capabilities = {...}
    return encode_varint(len(request)) + request                 # PB_ENCODE_DELIMITED


def read_varint(ser, deadline) -> int | None:
    """Read a base-128 varint, honouring an absolute deadline. None on timeout."""
    shift = 0
    result = 0
    while True:
        if time.monotonic() > deadline:
            return None
        chunk = ser.read(1)
        if not chunk:
            continue
        b = chunk[0]
        result |= (b & 0x7F) << shift
        if not (b & 0x80):
            return result
        shift += 7
        if shift > 63:
            return None  # malformed


def read_delimited(ser, timeout: float) -> bytes | None:
    """Read one length-delimited protobuf message. None if nothing arrives."""
    deadline = time.monotonic() + timeout
    length = read_varint(ser, deadline)
    if length is None or length == 0 or length > 1_000_000:
        return None
    data = bytearray()
    while len(data) < length:
        if time.monotonic() > deadline:
            break
        data.extend(ser.read(length - len(data)))
    return bytes(data) if len(data) == length else None


def extract_strings(data: bytes, min_len: int = 3):
    """Pull printable ASCII runs out of the raw response (board/device names)."""
    runs = []
    cur = bytearray()
    for b in data:
        if 0x20 <= b < 0x7F:
            cur.append(b)
        else:
            if len(cur) >= min_len:
                runs.append(cur.decode("ascii", "replace"))
            cur.clear()
    if len(cur) >= min_len:
        runs.append(cur.decode("ascii", "replace"))
    return runs


# --------------------------------------------------------------------------- #
# Commands
# --------------------------------------------------------------------------- #
def cmd_list(_args) -> int:
    ports = list(list_ports.comports())
    if not ports:
        print("No serial ports found.")
        return 1
    print(f"{'PORT':<12}{'VID:PID':<12}{'DESCRIPTION'}")
    print("-" * 60)
    for p in sorted(ports, key=lambda x: x.device):
        vidpid = f"{p.vid:04X}:{p.pid:04X}" if p.vid is not None else "-"
        print(f"{p.device:<12}{vidpid:<12}{p.description}")
    return 0


def probe_port(port: str, baud: int, timeout: float) -> bool:
    try:
        with serial.Serial(port, baud, timeout=0.05, write_timeout=2.0) as ser:
            ser.reset_input_buffer()
            ser.reset_output_buffer()
            ser.write(build_capabilities_request(device=-1))
            ser.flush()
            resp = read_delimited(ser, timeout)
    except serial.SerialException as exc:
        print(f"  {port} @ {baud}: cannot open ({exc})")
        return False

    if resp is None:
        print(f"  {port} @ {baud}: no response")
        return False

    strings = extract_strings(resp)
    print(f"  {port} @ {baud}: RESPONSE {len(resp)} bytes -> device is alive")
    if strings:
        print(f"      strings: {', '.join(strings)}")
    print(f"      hex: {resp[:64].hex(' ')}{' ...' if len(resp) > 64 else ''}")
    return True


def cmd_probe(args) -> int:
    try:
        ser = open_transport(args, read_timeout=0.05)
    except (OSError, ValueError, serial.SerialException) as exc:
        print(f"  {transport_label(args)}: cannot open ({exc})")
        return 2
    with ser:
        ser.reset_input_buffer()
        ser.reset_output_buffer()
        ser.write(build_capabilities_request(device=-1))
        ser.flush()
        resp = read_delimited(ser, args.timeout)
    if resp is None:
        print(f"  {transport_label(args)}: no response")
        return 2
    strings = extract_strings(resp)
    print(f"  {transport_label(args)}: RESPONSE {len(resp)} bytes -> device is alive")
    if strings:
        print(f"      strings: {', '.join(strings)}")
    print(f"      hex: {resp[:64].hex(' ')}{' ...' if len(resp) > 64 else ''}")
    return 0


def cmd_scan(args) -> int:
    bauds = [int(b) for b in str(args.baud).split(",") if b]
    ports = [p.device for p in list_ports.comports()]
    if not ports:
        print("No serial ports found.")
        return 1
    print(f"Scanning {len(ports)} port(s) at baud {bauds} ...")
    found = False
    for port in sorted(ports):
        for baud in bauds:
            if probe_port(port, baud, args.timeout):
                found = True
                break  # this port answered; move on
    if not found:
        print("\nNo streaming device answered. Things to check:")
        print("  - Is the board flashed and running (not halted in the debugger)?")
        print("  - Is this the ASCLIN0/P14 virtual COM port of the kit?")
        print("  - Does the USB-UART bridge support the baud (try 921600 / 115200)?")
        print("  - DEEPCRAFT Studio must use the SAME baud the firmware runs at.")
    return 0 if found else 2


# --------------------------------------------------------------------------- #
# infer: discover the model from capabilities, then run one inference
# --------------------------------------------------------------------------- #
DIR_INPUT = 1
DIR_OUTPUT = 2
DEVTYPE_MODEL = 3

# protocol DataType -> little-endian struct format char
DT_STRUCT = {
    1: "B", 2: "b", 3: "H", 4: "h", 5: "I", 6: "i", 7: "f", 8: "d",
    9: "b", 10: "h", 11: "i", 12: "b", 13: "h", 14: "i",
}
DT_IS_FLOAT = {7, 8}


def uvarint(buf, i):
    shift = result = 0
    while True:
        b = buf[i]
        i += 1
        result |= (b & 0x7F) << shift
        if not (b & 0x80):
            return result, i
        shift += 7


def parse_fields(data):
    """Generic protobuf decode -> {field_number: [(kind, value), ...]}."""
    i = 0
    out = {}
    n = len(data)
    while i < n:
        key, i = uvarint(data, i)
        field, wt = key >> 3, key & 7
        if wt == 0:
            val, i = uvarint(data, i)
            out.setdefault(field, []).append(("varint", val))
        elif wt == 2:
            ln, i = uvarint(data, i)
            out.setdefault(field, []).append(("len", data[i:i + ln]))
            i += ln
        elif wt == 5:
            out.setdefault(field, []).append(("i32", data[i:i + 4]))
            i += 4
        elif wt == 1:
            out.setdefault(field, []).append(("i64", data[i:i + 8]))
            i += 8
        else:
            break
    return out


def _first_varint(fields, num, default=0):
    v = fields.get(num)
    return v[0][1] if v else default


def _first_len(fields, num):
    v = fields.get(num)
    return v[0][1] if v else b""


def _drain_raw(ser, secs):
    """Read raw bytes for up to `secs`, extending while data keeps arriving."""
    end = time.monotonic() + secs
    buf = bytearray()
    while time.monotonic() < end:
        b = ser.read(8192)
        if b:
            buf.extend(b)
            end = time.monotonic() + 0.3
    return bytes(buf)


def _iter_messages(buf):
    """Yield decoded length-delimited messages from a raw byte stream."""
    p = 0
    while p < len(buf):
        try:
            mlen, j = uvarint(buf, p)
        except IndexError:
            break
        if mlen == 0:            # zero-length filler; skip
            p = j
            continue
        if j + mlen > len(buf):
            break
        yield parse_fields(buf[j:j + mlen])
        p = j + mlen


def discover_model(cap_response: bytes):
    """From a Response(BoardCapabilitiesResponse), return the MODEL device info:
    device_id and its input/output streams (id, datatype, element count)."""
    resp = parse_fields(cap_response)
    cap = parse_fields(_first_len(resp, 1))       # Response.capabilities
    board = parse_fields(_first_len(cap, 1))      # BoardCapabilitiesResponse.board
    for dev in board.get(6, []):                  # Board.devices (repeated Device)
        dv = parse_fields(dev[1])
        if _first_varint(dv, 4) != DEVTYPE_MODEL:  # Device.type
            continue
        device_id = _first_varint(dv, 1)
        inputs, outputs = [], []
        for idx, st in enumerate(dv.get(6, [])):   # Device.streams (repeated StreamConfig)
            sf = parse_fields(st[1])
            direction = _first_varint(sf, 2)
            datatype = _first_varint(sf, 3)
            count = 1
            for dim in sf.get(4, []):              # StreamConfig.shape (repeated Dimension)
                count *= _first_varint(parse_fields(dim[1]), 2, 1)  # Dimension.size
            name = _first_len(sf, 1).decode("ascii", "replace")
            entry = {"id": idx, "datatype": datatype, "count": count, "name": name}
            (inputs if direction == DIR_INPUT else outputs).append(entry)
        return {"device_id": device_id, "inputs": inputs, "outputs": outputs}
    return None


# --- request builders (all length-delimited) ------------------------------- #
def _tag(field, wt):
    return encode_varint((field << 3) | wt)


def _vfield(field, value):
    return _tag(field, 0) + encode_varint(value)


def _lfield(field, payload):
    return _tag(field, 2) + encode_varint(len(payload)) + payload


def _delimited(msg):
    return encode_varint(len(msg)) + msg


def build_config(device):
    return _delimited(_lfield(2, _vfield(1, device)))            # Request.config


def build_start(device):
    return _delimited(_lfield(3, _vfield(1, device)))            # Request.start


def build_stop(device):
    return _delimited(_lfield(4, _vfield(1, zigzag(device))))    # Request.stop (sint32)


def build_datachunk(device, stream, frame_count, frame_number, payload):
    dc = (_vfield(1, device) + _vfield(2, stream) + _vfield(3, frame_count)
          + _vfield(4, frame_number) + _lfield(5, payload))
    return _delimited(_lfield(6, dc))                            # Request.data


def load_input(source, count, is_float):
    if source in ("zeros", "ones", "random"):
        if source == "zeros":
            vals = [0.0] * count
        elif source == "ones":
            vals = [1.0] * count
        else:
            import random
            vals = [random.random() for _ in range(count)]
    elif source.lower().endswith(".npy"):
        import numpy as np
        vals = np.load(source).astype("float64").flatten().tolist()
    else:
        import re
        with open(source, "r", encoding="utf-8") as fh:
            vals = [float(x) for x in re.split(r"[,\s]+", fh.read().strip()) if x]
    if len(vals) != count:
        raise ValueError(f"input has {len(vals)} values, model expects {count}")
    return vals if is_float else [int(round(v)) for v in vals]


def cmd_infer(args) -> int:
    try:
        ser = open_transport(args, read_timeout=0.05, write_timeout=2.0)
    except (OSError, ValueError, serial.SerialException) as exc:
        print(f"Cannot open {transport_label(args)}: {exc}")
        return 2

    with ser:
        ser.reset_input_buffer()
        ser.reset_output_buffer()

        # 1. Discover the model device and its I/O from the board capabilities.
        ser.write(build_capabilities_request(device=-1))
        ser.flush()
        cap = read_delimited(ser, args.timeout)
        if cap is None:
            print("No capabilities response; is the device running at this baud?")
            return 2
        model = discover_model(cap)
        if not model or not model["inputs"] or not model["outputs"]:
            print("No MODEL device with input+output streams found.")
            return 2

        dev = model["device_id"]
        in_s = model["inputs"][0]
        out_s = model["outputs"][0]
        in_char = DT_STRUCT.get(in_s["datatype"])
        out_char = DT_STRUCT.get(out_s["datatype"])
        if in_char is None or out_char is None:
            print(f"Unsupported datatype (in={in_s['datatype']}, out={out_s['datatype']}).")
            return 2
        print(f"Model device {dev}: input '{in_s['name']}' x{in_s['count']} "
              f"(stream {in_s['id']}), output '{out_s['name']}' x{out_s['count']} "
              f"(stream {out_s['id']})")

        # 2. Build the input payload.
        try:
            values = load_input(args.input, in_s["count"], in_s["datatype"] in DT_IS_FLOAT)
        except Exception as exc:  # noqa: BLE001 - report any input problem
            print(f"Input error: {exc}")
            return 2
        import struct
        payload = struct.pack("<" + in_char * in_s["count"], *values)

        # 3. Configure + start.
        ser.write(build_config(dev))
        ser.flush()
        _drain_raw(ser, 0.4)                        # consume DeviceConfigurationResponse
        ser.write(build_start(dev))
        ser.flush()
        time.sleep(0.1)
        ser.reset_input_buffer()

        # 4. Send one input window, then push the bridge tail.
        ser.write(build_datachunk(dev, in_s["id"], 1, 0, payload))
        ser.flush()

        # The Infineon DAS virtual-COM bridge withholds the final partial USB
        # packet of a host->device transfer until enough further data arrives to
        # complete a packet, which would otherwise leave the DataChunk's tail
        # stuck in the bridge. Push it out with a run of zero bytes larger than a
        # USB packet (each decodes as a harmless zero-length request firmware-side).
        # Not needed (and harmful) over TCP: the extra bytes would be parsed as
        # bogus requests and drop the connection.
        if not getattr(args, "tcp", None):
            ser.write(b"\x00" * 2048)
            ser.flush()

        # 5. Collect and decode the reply.
        raw = _drain_raw(ser, max(args.timeout, 3.0))
        result = None
        for fields in _iter_messages(raw):
            if 4 in fields:                        # Response.data (DataChunk)
                dc = parse_fields(fields[4][0][1])
                if _first_varint(dc, 1) == dev:
                    result = _first_len(dc, 5)     # DataChunk.payload
                    break
            elif 3 in fields:                      # Response.error
                err = parse_fields(fields[3][0][1])
                print(f"Device returned error: code={_first_varint(err, 1)} "
                      f"msg={_first_len(err, 2).decode('ascii', 'replace')}")

        # 6. Stop the device.
        ser.write(build_stop(dev))
        ser.flush()

        if result is None:
            print("No output received.")
            return 2

        outs = list(struct.unpack("<" + out_char * out_s["count"], result[:out_s["count"] * struct.calcsize(out_char)]))
        print(f"\nOutput ({out_s['count']} values):")
        for i, v in enumerate(outs):
            print(f"  [{i:2}] {v}")
        if out_s["datatype"] in DT_IS_FLOAT:
            argmax = max(range(len(outs)), key=lambda i: outs[i])
            print(f"\nargmax = {argmax} (value {outs[argmax]})")
    return 0


def _read_model_output(ser, dev, timeout, prefix=b""):
    """Read/accumulate bytes until a Response.data (DataChunk) for `dev` decodes.
    Starts from any `prefix` left over from a previous read.
    Returns (payload_bytes, leftover_after) or (None, accumulated) on timeout."""
    buf = bytearray(prefix)
    deadline = time.perf_counter() + timeout
    while True:
        p = 0
        while p < len(buf):
            try:
                mlen, j = uvarint(buf, p)
            except IndexError:
                break
            if mlen == 0:
                p = j
                continue
            if j + mlen > len(buf):
                break
            f = parse_fields(buf[j:j + mlen])
            p = j + mlen
            if 4 in f:
                dc = parse_fields(f[4][0][1])
                if _first_varint(dc, 1) == dev:
                    return _first_len(dc, 5), bytes(buf[p:])
        if p:
            del buf[:p]
        if time.perf_counter() >= deadline:
            return None, bytes(buf)
        b = ser.read(4096)
        if b:
            buf.extend(b)


def cmd_bench(args) -> int:
    """Stress test: raw link write speed and inference round-trip throughput."""
    import struct
    try:
        ser = open_transport(args, read_timeout=0.05, write_timeout=5.0)
    except (OSError, ValueError, serial.SerialException) as exc:
        print(f"Cannot open {transport_label(args)}: {exc}")
        return 2
    # Over TCP the DAS bridge quirks don't apply, so no flush pad is needed.
    pad = 0 if getattr(args, "tcp", None) else args.pad

    with ser:
        ser.reset_input_buffer()
        ser.reset_output_buffer()

        ser.write(build_capabilities_request(-1))
        ser.flush()
        cap = read_delimited(ser, 1.5)
        if cap is None:
            print("No capabilities response; is the device running at this baud?")
            return 2
        model = discover_model(cap)
        if not model or not model["inputs"] or not model["outputs"]:
            print("No MODEL device with input+output streams found.")
            return 2
        dev = model["device_id"]
        in_s = model["inputs"][0]
        out_s = model["outputs"][0]
        in_char = DT_STRUCT.get(in_s["datatype"])
        in_bytes = in_s["count"] * struct.calcsize(in_char)
        out_bytes = out_s["count"] * struct.calcsize(DT_STRUCT.get(out_s["datatype"]))

        # 1. Raw host->device link throughput (zero-length requests, no replies).
        #    This is a DAS-bridge micro-benchmark: over TCP a blob of zeros would
        #    be parsed as bogus requests and drop the connection, and the measured
        #    rate would just be the local socket buffer, so skip it over TCP.
        if not getattr(args, "tcp", None):
            blob = b"\x00" * args.blob
            t0 = time.perf_counter()
            ser.write(blob)
            ser.flush()
            t1 = time.perf_counter()
            raw_bps = args.blob / (t1 - t0) if t1 > t0 else 0
            print(f"Link write (host->device): {args.blob} bytes in {(t1 - t0) * 1e3:.1f} ms "
                  f"=> {raw_bps / 1e6:.2f} MB/s ({raw_bps * 10 / 1e6:.2f} Mbit/s incl. framing)")
            time.sleep(0.2)
            ser.reset_input_buffer()

        # 2. Inference throughput (sequential request/response). The firmware
        #    processes one inference at a time (single input slot), so requests
        #    are sent one at a time. Each input carries a flush pad so the bridge
        #    delivers its final partial packet immediately; the small output is
        #    returned via the bridge's device->host flush.
        payload = struct.pack("<" + in_char * in_s["count"], *([0.0] * in_s["count"]))
        chunk = build_datachunk(dev, in_s["id"], 1, 0, payload) + b"\x00" * pad

        ser.write(build_config(dev)); ser.flush(); _drain_raw(ser, 0.4)
        ser.write(build_start(dev)); ser.flush(); time.sleep(0.1)
        ser.reset_input_buffer()

        n = args.count
        errors = 0
        lats = []
        pokes = 0
        leftover = b""
        t_start = time.perf_counter()
        for _ in range(n):
            ta = time.perf_counter()
            ser.write(chunk)
            ser.flush()
            # First try: the bridge often delivers the output on its own latency
            # flush within ~compute time.
            out, leftover = _read_model_output(ser, dev, 0.25, leftover)
            if out is None:
                # The output's final partial packet is stuck in the bridge. By now
                # the device has produced it, so a capabilities "poke" generates
                # device->host traffic that flushes the withheld output tail. The
                # poke itself is padded so it isn't withheld host->device.
                pokes += 1
                ser.write(build_capabilities_request(-1) + b"\x00" * pad)
                ser.flush()
                out, leftover = _read_model_output(ser, dev, args.timeout, leftover)
            tb = time.perf_counter()
            if out is None:
                errors += 1
                leftover = b""
            else:
                lats.append(tb - ta)
        t_total = time.perf_counter() - t_start

        ser.write(build_stop(dev)); ser.flush()

        ok = len(lats)
        print(f"\nInference (sequential): {ok}/{n} ok, {errors} timeout(s), "
              f"{pokes} bridge-flush poke(s)")
        if ok:
            lats.sort()
            med = lats[ok // 2]
            payload_per = in_bytes + out_bytes
            print(f"  latency min/median/max = {lats[0]*1e3:.1f} / {med*1e3:.1f} / "
                  f"{lats[-1]*1e3:.1f} ms")
            print(f"  rate               = {ok / t_total:.1f} inferences/s "
                  f"({1.0/med:.1f}/s at median latency)")
            print(f"  payload throughput = {payload_per / med / 1e3:.1f} KB/s "
                  f"(in {in_bytes} + out {out_bytes} B per inference)")
            print(f"  input up-link      = {in_bytes / med / 1e3:.1f} KB/s")
    return 0 if errors == 0 else 2


def cmd_monitor(args) -> int:
    """Dump raw bytes arriving on a port. Handy to confirm the port/bridge with a
    firmware that prints unsolicited output (e.g. the stock printf example)."""
    try:
        ser = open_transport(args, read_timeout=0.2)
    except (OSError, ValueError, serial.SerialException) as exc:
        print(f"Cannot open {transport_label(args)}: {exc}")
        return 2
    print(f"Listening on {transport_label(args)} (Ctrl+C to stop)...")
    total = 0
    try:
        while True:
            data = ser.read(256)
            if data:
                total += len(data)
                text = "".join(chr(b) if 0x20 <= b < 0x7F or b in (9, 10, 13) else "." for b in data)
                sys.stdout.write(text)
                sys.stdout.flush()
    except KeyboardInterrupt:
        print(f"\n[stopped; {total} bytes received]")
    finally:
        ser.close()
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest="command", required=True)

    sub.add_parser("list", help="list available serial ports").set_defaults(func=cmd_list)

    p_probe = sub.add_parser("probe", help="probe one port for the streaming device")
    p_probe.add_argument("--port", help="serial port, e.g. COM7 or /dev/ttyUSB0")
    p_probe.add_argument("--tcp", help="connect over TCP instead: HOST[:PORT] (default port 14325)")
    p_probe.add_argument("--baud", type=int, default=DEFAULT_BAUD, help=f"baud rate (default {DEFAULT_BAUD})")
    p_probe.add_argument("--timeout", type=float, default=1.0, help="response timeout in seconds")
    p_probe.set_defaults(func=cmd_probe)

    p_scan = sub.add_parser("scan", help="probe every serial port")
    p_scan.add_argument("--baud", default=str(DEFAULT_BAUD),
                        help="baud rate(s), comma-separated (default %(default)s)")
    p_scan.add_argument("--timeout", type=float, default=1.0, help="response timeout in seconds")
    p_scan.set_defaults(func=cmd_scan)

    p_infer = sub.add_parser("infer", help="configure+start the model, send one input window, print outputs")
    p_infer.add_argument("--port", help="serial port, e.g. COM7 or /dev/ttyUSB0")
    p_infer.add_argument("--tcp", help="connect over TCP instead: HOST[:PORT] (default port 14325)")
    p_infer.add_argument("--baud", type=int, default=DEFAULT_BAUD, help=f"baud rate (default {DEFAULT_BAUD})")
    p_infer.add_argument("--input", default="zeros",
                         help="'zeros' | 'ones' | 'random' | path to .npy or .csv/txt of numbers")
    p_infer.add_argument("--timeout", type=float, default=2.0, help="per-message timeout in seconds")
    p_infer.set_defaults(func=cmd_infer)

    p_bench = sub.add_parser("bench", help="stress test link + inference throughput")
    p_bench.add_argument("--port", help="serial port, e.g. COM7 or /dev/ttyUSB0")
    p_bench.add_argument("--tcp", help="connect over TCP instead: HOST[:PORT] (default port 14325)")
    p_bench.add_argument("--baud", type=int, default=DEFAULT_BAUD, help=f"baud rate (default {DEFAULT_BAUD})")
    p_bench.add_argument("--count", type=int, default=50, help="number of inferences to run")
    p_bench.add_argument("--blob", type=int, default=262144, help="bytes for the raw link-speed test")
    p_bench.add_argument("--pad", type=int, default=2048, help="per-input bridge-flush pad bytes (serial only)")
    p_bench.add_argument("--timeout", type=float, default=2.0, help="per-inference output timeout in seconds")
    p_bench.set_defaults(func=cmd_bench)

    p_mon = sub.add_parser("monitor", help="dump raw bytes received on a port")
    p_mon.add_argument("--port", help="serial port, e.g. COM7 or /dev/ttyUSB0")
    p_mon.add_argument("--tcp", help="connect over TCP instead: HOST[:PORT] (default port 14325)")
    p_mon.add_argument("--baud", type=int, default=DEFAULT_BAUD, help=f"baud rate (default {DEFAULT_BAUD})")
    p_mon.set_defaults(func=cmd_monitor)

    args = parser.parse_args()
    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
