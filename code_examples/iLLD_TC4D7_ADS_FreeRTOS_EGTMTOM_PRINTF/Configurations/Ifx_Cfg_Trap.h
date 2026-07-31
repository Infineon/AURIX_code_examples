#ifndef IFX_CFG_TRAP_H
#define IFX_CFG_TRAP_H

#define IFX_CFG_CPU_TRAP_SYSCALL_CPU0_HOOK(t) vPortSyscallHandler(t.tId)

extern int vPortSyscallHandler(unsigned char id);

#endif
