/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)
ENTRY(_START)

__TRICORE_DERIVATE_MEMORY_MAP__ = 0x330;

LCF_CSA0_SIZE = 8k;
LCF_USTACK0_SIZE = 2k;
LCF_ISTACK0_SIZE = 1k;

LCF_HEAP_SIZE = 4k;

LCF_DSPR0_START = 0x70000000;
LCF_DSPR0_SIZE = 192k;

LCF_CSA0_OFFSET =    (LCF_DSPR0_SIZE - 1k - LCF_CSA0_SIZE);
LCF_ISTACK0_OFFSET = (LCF_CSA0_OFFSET - 256 - LCF_ISTACK0_SIZE);
LCF_USTACK0_OFFSET = (LCF_ISTACK0_OFFSET - 256 - LCF_USTACK0_SIZE);

LCF_HEAP0_OFFSET =   (LCF_USTACK0_OFFSET - LCF_HEAP_SIZE);

LCF_INTVEC0_START = 0x801FE000;

__INTTAB_CPU0 = LCF_INTVEC0_START;

LCF_TRAPVEC0_START = 0x80000100;

LCF_STARTPTR_CPU0 = 0x80000000;

LCF_STARTPTR_NC_CPU0 = 0xA0000000;

RESET = LCF_STARTPTR_NC_CPU0;

MEMORY
{   
    dsram0_local (w!xp): org = 0xd0000000, len = 192K
    dsram0 (w!xp): org = 0x70000000, len = 192K
    psram0 (w!xp): org = 0x70100000, len = 8K
    
    psram_local (w!xp): org = 0xc0000000, len = 64K
    
    pfls0 (rx!p): org = 0x80000000, len = 2M
    pfls0_nc (rx!p): org = 0xa0000000, len = 2M
    
    dfls0 (rx!p): org = 0xaf000000, len = 256K
    
    ucb (rx!p): org = 0xaf400000, len = 24K
    
    cpu0_dlmu (w!xp): org = 0x90000000, len = 8K
    cpu0_dlmu_nc (w!xp): org = 0xb0000000, len = 8K
}

/* map local memory address to a global address */
REGION_MAP( CPU0 , ORIGIN(dsram0_local), LENGTH(dsram0_local), ORIGIN(dsram0))
/* map cached and non cached addresses */
REGION_MIRROR("pfls0", "pfls0_nc")
REGION_MIRROR("cpu0_dlmu", "cpu0_dlmu_nc")
/*Un comment one of the below statement groups to enable CpuX DMI RAM to hold global variables*/

REGION_ALIAS( default_ram , dsram0)
REGION_ALIAS( default_rom , pfls0)

/*Sections located at absolute fixed address*/
    /*Fixed memory Allocations for stack memory and CSA*/   
    CORE_ID = CPU0;
    SECTIONS
    {
        CORE_SEC(.ustack) (LCF_DSPR0_START + LCF_USTACK0_OFFSET):
        { PROVIDE(__USTACK0_END = .);    . = . + LCF_USTACK0_SIZE;    PROVIDE(__USTACK0 = .); }
        
        CORE_SEC(.istack) (LCF_DSPR0_START + LCF_ISTACK0_OFFSET):
        { PROVIDE(__ISTACK0_END = .);    . = . + LCF_ISTACK0_SIZE;    PROVIDE(__ISTACK0 = .); }
        
        CORE_SEC(.csa) (LCF_DSPR0_START + LCF_CSA0_OFFSET):
        { PROVIDE(__CSA0 = .);    . = . + LCF_CSA0_SIZE;    PROVIDE(__CSA0_END = .); }
    }
    
    /*Fixed memory Allocations for _START*/
    CORE_ID = GLOBAL ;
    SECTIONS
    {
        .start_tc0 (LCF_STARTPTR_NC_CPU0) : FLAGS(rxl) { KEEP (*(.start)); } > pfls0_nc
        .interface_const (0x80000020) : { __IF_CONST = .; KEEP (*(.interface_const)); } > pfls0
        PROVIDE(__START0 = LCF_STARTPTR_NC_CPU0);
        PROVIDE(__ENABLE_INDIVIDUAL_C_INIT_CPU0 = 0); /* Not used */
    }
    
    /*Fixed memory Allocations for Trap Vector Table*/
    CORE_ID = GLOBAL;
    SECTIONS
    {
        .traptab_tc0 (LCF_TRAPVEC0_START) : { PROVIDE(__TRAPTAB_CPU0 = .); KEEP (*(.traptab_cpu0)); } > pfls0
    }
       
    /*Fixed memory Allocations for Interrupt Vector Table*/
    SECTIONS
    {
        /*CPU0 Interrupt Vector Table*/
        .inttab_tc0_000 (__INTTAB_CPU0 + 0x0000) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_0  )); }
        .inttab_tc0_001 (__INTTAB_CPU0 + 0x0020) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_1  )); }
        .inttab_tc0_002 (__INTTAB_CPU0 + 0x0040) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_2  )); }
        .inttab_tc0_003 (__INTTAB_CPU0 + 0x0060) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_3  )); }
        .inttab_tc0_004 (__INTTAB_CPU0 + 0x0080) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_4  )); }
        .inttab_tc0_005 (__INTTAB_CPU0 + 0x00A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_5  )); }
        .inttab_tc0_006 (__INTTAB_CPU0 + 0x00C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_6  )); }
        .inttab_tc0_007 (__INTTAB_CPU0 + 0x00E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_7  )); }
        .inttab_tc0_008 (__INTTAB_CPU0 + 0x0100) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_8  )); }
        .inttab_tc0_009 (__INTTAB_CPU0 + 0x0120) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_9  )); }
        .inttab_tc0_00A (__INTTAB_CPU0 + 0x0140) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_10 )); }
        .inttab_tc0_00B (__INTTAB_CPU0 + 0x0160) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_11 )); }
        .inttab_tc0_00C (__INTTAB_CPU0 + 0x0180) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_12 )); }
        .inttab_tc0_00D (__INTTAB_CPU0 + 0x01A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_13 )); }
        .inttab_tc0_00E (__INTTAB_CPU0 + 0x01C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_14 )); }
        .inttab_tc0_00F (__INTTAB_CPU0 + 0x01E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_15 )); }
        .inttab_tc0_010 (__INTTAB_CPU0 + 0x0200) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_16 )); }
        .inttab_tc0_011 (__INTTAB_CPU0 + 0x0220) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_17 )); }
        .inttab_tc0_012 (__INTTAB_CPU0 + 0x0240) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_18 )); }
        .inttab_tc0_013 (__INTTAB_CPU0 + 0x0260) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_19 )); }
        .inttab_tc0_014 (__INTTAB_CPU0 + 0x0280) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_20 )); }
        .inttab_tc0_015 (__INTTAB_CPU0 + 0x02A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_21 )); }
        .inttab_tc0_016 (__INTTAB_CPU0 + 0x02C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_22 )); }
        .inttab_tc0_017 (__INTTAB_CPU0 + 0x02E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_23 )); }
        .inttab_tc0_018 (__INTTAB_CPU0 + 0x0300) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_24 )); }
        .inttab_tc0_019 (__INTTAB_CPU0 + 0x0320) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_25 )); }
        .inttab_tc0_01A (__INTTAB_CPU0 + 0x0340) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_26 )); }
        .inttab_tc0_01B (__INTTAB_CPU0 + 0x0360) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_27 )); }
        .inttab_tc0_01C (__INTTAB_CPU0 + 0x0380) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_28 )); }
        .inttab_tc0_01D (__INTTAB_CPU0 + 0x03A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_29 )); }
        .inttab_tc0_01E (__INTTAB_CPU0 + 0x03C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_30 )); }
        .inttab_tc0_01F (__INTTAB_CPU0 + 0x03E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_31 )); }
        .inttab_tc0_020 (__INTTAB_CPU0 + 0x0400) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_32 )); }
        .inttab_tc0_021 (__INTTAB_CPU0 + 0x0420) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_33 )); }
        .inttab_tc0_022 (__INTTAB_CPU0 + 0x0440) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_34 )); }
        .inttab_tc0_023 (__INTTAB_CPU0 + 0x0460) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_35 )); }
        .inttab_tc0_024 (__INTTAB_CPU0 + 0x0480) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_36 )); }
        .inttab_tc0_025 (__INTTAB_CPU0 + 0x04A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_37 )); }
        .inttab_tc0_026 (__INTTAB_CPU0 + 0x04C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_38 )); }
        .inttab_tc0_027 (__INTTAB_CPU0 + 0x04E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_39 )); }
        .inttab_tc0_028 (__INTTAB_CPU0 + 0x0500) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_40 )); }
        .inttab_tc0_029 (__INTTAB_CPU0 + 0x0520) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_41 )); }
        .inttab_tc0_02A (__INTTAB_CPU0 + 0x0540) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_42 )); }
        .inttab_tc0_02B (__INTTAB_CPU0 + 0x0560) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_43 )); }
        .inttab_tc0_02C (__INTTAB_CPU0 + 0x0580) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_44 )); }
        .inttab_tc0_02D (__INTTAB_CPU0 + 0x05A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_45 )); }
        .inttab_tc0_02E (__INTTAB_CPU0 + 0x05C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_46 )); }
        .inttab_tc0_02F (__INTTAB_CPU0 + 0x05E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_47 )); }
        .inttab_tc0_030 (__INTTAB_CPU0 + 0x0600) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_48 )); }
        .inttab_tc0_031 (__INTTAB_CPU0 + 0x0620) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_49 )); }
        .inttab_tc0_032 (__INTTAB_CPU0 + 0x0640) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_50 )); }
        .inttab_tc0_033 (__INTTAB_CPU0 + 0x0660) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_51 )); }
        .inttab_tc0_034 (__INTTAB_CPU0 + 0x0680) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_52 )); }
        .inttab_tc0_035 (__INTTAB_CPU0 + 0x06A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_53 )); }
        .inttab_tc0_036 (__INTTAB_CPU0 + 0x06C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_54 )); }
        .inttab_tc0_037 (__INTTAB_CPU0 + 0x06E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_55 )); }
        .inttab_tc0_038 (__INTTAB_CPU0 + 0x0700) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_56 )); }
        .inttab_tc0_039 (__INTTAB_CPU0 + 0x0720) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_57 )); }
        .inttab_tc0_03A (__INTTAB_CPU0 + 0x0740) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_58 )); }
        .inttab_tc0_03B (__INTTAB_CPU0 + 0x0760) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_59 )); }
        .inttab_tc0_03C (__INTTAB_CPU0 + 0x0780) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_60 )); }
        .inttab_tc0_03D (__INTTAB_CPU0 + 0x07A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_61 )); }
        .inttab_tc0_03E (__INTTAB_CPU0 + 0x07C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_62 )); }
        .inttab_tc0_03F (__INTTAB_CPU0 + 0x07E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_63 )); }
        .inttab_tc0_040 (__INTTAB_CPU0 + 0x0800) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_64 )); }
        .inttab_tc0_041 (__INTTAB_CPU0 + 0x0820) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_65 )); }
        .inttab_tc0_042 (__INTTAB_CPU0 + 0x0840) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_66 )); }
        .inttab_tc0_043 (__INTTAB_CPU0 + 0x0860) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_67 )); }
        .inttab_tc0_044 (__INTTAB_CPU0 + 0x0880) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_68 )); }
        .inttab_tc0_045 (__INTTAB_CPU0 + 0x08A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_69 )); }
        .inttab_tc0_046 (__INTTAB_CPU0 + 0x08C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_70 )); }
        .inttab_tc0_047 (__INTTAB_CPU0 + 0x08E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_71 )); }
        .inttab_tc0_048 (__INTTAB_CPU0 + 0x0900) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_72 )); }
        .inttab_tc0_049 (__INTTAB_CPU0 + 0x0920) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_73 )); }
        .inttab_tc0_04A (__INTTAB_CPU0 + 0x0940) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_74 )); }
        .inttab_tc0_04B (__INTTAB_CPU0 + 0x0960) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_75 )); }
        .inttab_tc0_04C (__INTTAB_CPU0 + 0x0980) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_76 )); }
        .inttab_tc0_04D (__INTTAB_CPU0 + 0x09A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_77 )); }
        .inttab_tc0_04E (__INTTAB_CPU0 + 0x09C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_78 )); }
        .inttab_tc0_04F (__INTTAB_CPU0 + 0x09E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_79 )); }
        .inttab_tc0_050 (__INTTAB_CPU0 + 0x0A00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_80 )); }
        .inttab_tc0_051 (__INTTAB_CPU0 + 0x0A20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_81 )); }
        .inttab_tc0_052 (__INTTAB_CPU0 + 0x0A40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_82 )); }
        .inttab_tc0_053 (__INTTAB_CPU0 + 0x0A60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_83 )); }
        .inttab_tc0_054 (__INTTAB_CPU0 + 0x0A80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_84 )); }
        .inttab_tc0_055 (__INTTAB_CPU0 + 0x0AA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_85 )); }
        .inttab_tc0_056 (__INTTAB_CPU0 + 0x0AC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_86 )); }
        .inttab_tc0_057 (__INTTAB_CPU0 + 0x0AE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_87 )); }
        .inttab_tc0_058 (__INTTAB_CPU0 + 0x0B00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_88 )); }
        .inttab_tc0_059 (__INTTAB_CPU0 + 0x0B20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_89 )); }
        .inttab_tc0_05A (__INTTAB_CPU0 + 0x0B40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_90 )); }
        .inttab_tc0_05B (__INTTAB_CPU0 + 0x0B60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_91 )); }
        .inttab_tc0_05C (__INTTAB_CPU0 + 0x0B80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_92 )); }
        .inttab_tc0_05D (__INTTAB_CPU0 + 0x0BA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_93 )); }
        .inttab_tc0_05E (__INTTAB_CPU0 + 0x0BC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_94 )); }
        .inttab_tc0_05F (__INTTAB_CPU0 + 0x0BE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_95 )); }
        .inttab_tc0_060 (__INTTAB_CPU0 + 0x0C00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_96 )); }
        .inttab_tc0_061 (__INTTAB_CPU0 + 0x0C20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_97 )); }
        .inttab_tc0_062 (__INTTAB_CPU0 + 0x0C40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_98 )); }
        .inttab_tc0_063 (__INTTAB_CPU0 + 0x0C60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_99 )); }
        .inttab_tc0_064 (__INTTAB_CPU0 + 0x0C80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_100)); }
        .inttab_tc0_065 (__INTTAB_CPU0 + 0x0CA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_101)); }
        .inttab_tc0_066 (__INTTAB_CPU0 + 0x0CC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_102)); }
        .inttab_tc0_067 (__INTTAB_CPU0 + 0x0CE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_103)); }
        .inttab_tc0_068 (__INTTAB_CPU0 + 0x0D00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_104)); }
        .inttab_tc0_069 (__INTTAB_CPU0 + 0x0D20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_105)); }
        .inttab_tc0_06A (__INTTAB_CPU0 + 0x0D40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_106)); }
        .inttab_tc0_06B (__INTTAB_CPU0 + 0x0D60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_107)); }
        .inttab_tc0_06C (__INTTAB_CPU0 + 0x0D80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_108)); }
        .inttab_tc0_06D (__INTTAB_CPU0 + 0x0DA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_109)); }
        .inttab_tc0_06E (__INTTAB_CPU0 + 0x0DC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_110)); }
        .inttab_tc0_06F (__INTTAB_CPU0 + 0x0DE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_111)); }
        .inttab_tc0_070 (__INTTAB_CPU0 + 0x0E00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_112)); }
        .inttab_tc0_071 (__INTTAB_CPU0 + 0x0E20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_113)); }
        .inttab_tc0_072 (__INTTAB_CPU0 + 0x0E40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_114)); }
        .inttab_tc0_073 (__INTTAB_CPU0 + 0x0E60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_115)); }
        .inttab_tc0_074 (__INTTAB_CPU0 + 0x0E80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_116)); }
        .inttab_tc0_075 (__INTTAB_CPU0 + 0x0EA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_117)); }
        .inttab_tc0_076 (__INTTAB_CPU0 + 0x0EC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_118)); }
        .inttab_tc0_077 (__INTTAB_CPU0 + 0x0EE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_119)); }
        .inttab_tc0_078 (__INTTAB_CPU0 + 0x0F00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_120)); }
        .inttab_tc0_079 (__INTTAB_CPU0 + 0x0F20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_121)); }
        .inttab_tc0_07A (__INTTAB_CPU0 + 0x0F40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_122)); }
        .inttab_tc0_07B (__INTTAB_CPU0 + 0x0F60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_123)); }
        .inttab_tc0_07C (__INTTAB_CPU0 + 0x0F80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_124)); }
        .inttab_tc0_07D (__INTTAB_CPU0 + 0x0FA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_125)); }
        .inttab_tc0_07E (__INTTAB_CPU0 + 0x0FC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_126)); }
        .inttab_tc0_07F (__INTTAB_CPU0 + 0x0FE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_127)); }
        .inttab_tc0_080 (__INTTAB_CPU0 + 0x1000) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_128)); }
        .inttab_tc0_081 (__INTTAB_CPU0 + 0x1020) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_129)); }
        .inttab_tc0_082 (__INTTAB_CPU0 + 0x1040) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_130)); }
        .inttab_tc0_083 (__INTTAB_CPU0 + 0x1060) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_131)); }
        .inttab_tc0_084 (__INTTAB_CPU0 + 0x1080) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_132)); }
        .inttab_tc0_085 (__INTTAB_CPU0 + 0x10A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_133)); }
        .inttab_tc0_086 (__INTTAB_CPU0 + 0x10C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_134)); }
        .inttab_tc0_087 (__INTTAB_CPU0 + 0x10E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_135)); }
        .inttab_tc0_088 (__INTTAB_CPU0 + 0x1100) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_136)); }
        .inttab_tc0_089 (__INTTAB_CPU0 + 0x1120) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_137)); }
        .inttab_tc0_08A (__INTTAB_CPU0 + 0x1140) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_138)); }
        .inttab_tc0_08B (__INTTAB_CPU0 + 0x1160) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_139)); }
        .inttab_tc0_08C (__INTTAB_CPU0 + 0x1180) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_140)); }
        .inttab_tc0_08D (__INTTAB_CPU0 + 0x11A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_141)); }
        .inttab_tc0_08E (__INTTAB_CPU0 + 0x11C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_142)); }
        .inttab_tc0_08F (__INTTAB_CPU0 + 0x11E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_143)); }
        .inttab_tc0_090 (__INTTAB_CPU0 + 0x1200) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_144)); }
        .inttab_tc0_091 (__INTTAB_CPU0 + 0x1220) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_145)); }
        .inttab_tc0_092 (__INTTAB_CPU0 + 0x1240) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_146)); }
        .inttab_tc0_093 (__INTTAB_CPU0 + 0x1260) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_147)); }
        .inttab_tc0_094 (__INTTAB_CPU0 + 0x1280) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_148)); }
        .inttab_tc0_095 (__INTTAB_CPU0 + 0x12A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_149)); }
        .inttab_tc0_096 (__INTTAB_CPU0 + 0x12C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_150)); }
        .inttab_tc0_097 (__INTTAB_CPU0 + 0x12E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_151)); }
        .inttab_tc0_098 (__INTTAB_CPU0 + 0x1300) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_152)); }
        .inttab_tc0_099 (__INTTAB_CPU0 + 0x1320) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_153)); }
        .inttab_tc0_09A (__INTTAB_CPU0 + 0x1340) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_154)); }
        .inttab_tc0_09B (__INTTAB_CPU0 + 0x1360) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_155)); }
        .inttab_tc0_09C (__INTTAB_CPU0 + 0x1380) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_156)); }
        .inttab_tc0_09D (__INTTAB_CPU0 + 0x13A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_157)); }
        .inttab_tc0_09E (__INTTAB_CPU0 + 0x13C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_158)); }
        .inttab_tc0_09F (__INTTAB_CPU0 + 0x13E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_159)); }
        .inttab_tc0_0A0 (__INTTAB_CPU0 + 0x1400) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_160)); }
        .inttab_tc0_0A1 (__INTTAB_CPU0 + 0x1420) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_161)); }
        .inttab_tc0_0A2 (__INTTAB_CPU0 + 0x1440) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_162)); }
        .inttab_tc0_0A3 (__INTTAB_CPU0 + 0x1460) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_163)); }
        .inttab_tc0_0A4 (__INTTAB_CPU0 + 0x1480) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_164)); }
        .inttab_tc0_0A5 (__INTTAB_CPU0 + 0x14A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_165)); }
        .inttab_tc0_0A6 (__INTTAB_CPU0 + 0x14C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_166)); }
        .inttab_tc0_0A7 (__INTTAB_CPU0 + 0x14E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_167)); }
        .inttab_tc0_0A8 (__INTTAB_CPU0 + 0x1500) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_168)); }
        .inttab_tc0_0A9 (__INTTAB_CPU0 + 0x1520) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_169)); }
        .inttab_tc0_0AA (__INTTAB_CPU0 + 0x1540) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_170)); }
        .inttab_tc0_0AB (__INTTAB_CPU0 + 0x1560) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_171)); }
        .inttab_tc0_0AC (__INTTAB_CPU0 + 0x1580) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_172)); }
        .inttab_tc0_0AD (__INTTAB_CPU0 + 0x15A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_173)); }
        .inttab_tc0_0AE (__INTTAB_CPU0 + 0x15C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_174)); }
        .inttab_tc0_0AF (__INTTAB_CPU0 + 0x15E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_175)); }
        .inttab_tc0_0B0 (__INTTAB_CPU0 + 0x1600) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_176)); }
        .inttab_tc0_0B1 (__INTTAB_CPU0 + 0x1620) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_177)); }
        .inttab_tc0_0B2 (__INTTAB_CPU0 + 0x1640) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_178)); }
        .inttab_tc0_0B3 (__INTTAB_CPU0 + 0x1660) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_179)); }
        .inttab_tc0_0B4 (__INTTAB_CPU0 + 0x1680) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_180)); }
        .inttab_tc0_0B5 (__INTTAB_CPU0 + 0x16A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_181)); }
        .inttab_tc0_0B6 (__INTTAB_CPU0 + 0x16C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_182)); }
        .inttab_tc0_0B7 (__INTTAB_CPU0 + 0x16E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_183)); }
        .inttab_tc0_0B8 (__INTTAB_CPU0 + 0x1700) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_184)); }
        .inttab_tc0_0B9 (__INTTAB_CPU0 + 0x1720) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_185)); }
        .inttab_tc0_0BA (__INTTAB_CPU0 + 0x1740) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_186)); }
        .inttab_tc0_0BB (__INTTAB_CPU0 + 0x1760) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_187)); }
        .inttab_tc0_0BC (__INTTAB_CPU0 + 0x1780) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_188)); }
        .inttab_tc0_0BD (__INTTAB_CPU0 + 0x17A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_189)); }
        .inttab_tc0_0BE (__INTTAB_CPU0 + 0x17C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_190)); }
        .inttab_tc0_0BF (__INTTAB_CPU0 + 0x17E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_191)); }
        .inttab_tc0_0C0 (__INTTAB_CPU0 + 0x1800) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_192)); }
        .inttab_tc0_0C1 (__INTTAB_CPU0 + 0x1820) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_193)); }
        .inttab_tc0_0C2 (__INTTAB_CPU0 + 0x1840) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_194)); }
        .inttab_tc0_0C3 (__INTTAB_CPU0 + 0x1860) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_195)); }
        .inttab_tc0_0C4 (__INTTAB_CPU0 + 0x1880) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_196)); }
        .inttab_tc0_0C5 (__INTTAB_CPU0 + 0x18A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_197)); }
        .inttab_tc0_0C6 (__INTTAB_CPU0 + 0x18C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_198)); }
        .inttab_tc0_0C7 (__INTTAB_CPU0 + 0x18E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_199)); }
        .inttab_tc0_0C8 (__INTTAB_CPU0 + 0x1900) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_200)); }
        .inttab_tc0_0C9 (__INTTAB_CPU0 + 0x1920) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_201)); }
        .inttab_tc0_0CA (__INTTAB_CPU0 + 0x1940) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_202)); }
        .inttab_tc0_0CB (__INTTAB_CPU0 + 0x1960) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_203)); }
        .inttab_tc0_0CC (__INTTAB_CPU0 + 0x1980) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_204)); }
        .inttab_tc0_0CD (__INTTAB_CPU0 + 0x19A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_205)); }
        .inttab_tc0_0CE (__INTTAB_CPU0 + 0x19C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_206)); }
        .inttab_tc0_0CF (__INTTAB_CPU0 + 0x19E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_207)); }
        .inttab_tc0_0D0 (__INTTAB_CPU0 + 0x1A00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_208)); }
        .inttab_tc0_0D1 (__INTTAB_CPU0 + 0x1A20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_209)); }
        .inttab_tc0_0D2 (__INTTAB_CPU0 + 0x1A40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_210)); }
        .inttab_tc0_0D3 (__INTTAB_CPU0 + 0x1A60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_211)); }
        .inttab_tc0_0D4 (__INTTAB_CPU0 + 0x1A80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_212)); }
        .inttab_tc0_0D5 (__INTTAB_CPU0 + 0x1AA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_213)); }
        .inttab_tc0_0D6 (__INTTAB_CPU0 + 0x1AC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_214)); }
        .inttab_tc0_0D7 (__INTTAB_CPU0 + 0x1AE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_215)); }
        .inttab_tc0_0D8 (__INTTAB_CPU0 + 0x1B00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_216)); }
        .inttab_tc0_0D9 (__INTTAB_CPU0 + 0x1B20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_217)); }
        .inttab_tc0_0DA (__INTTAB_CPU0 + 0x1B40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_218)); }
        .inttab_tc0_0DB (__INTTAB_CPU0 + 0x1B60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_219)); }
        .inttab_tc0_0DC (__INTTAB_CPU0 + 0x1B80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_220)); }
        .inttab_tc0_0DD (__INTTAB_CPU0 + 0x1BA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_221)); }
        .inttab_tc0_0DE (__INTTAB_CPU0 + 0x1BC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_222)); }
        .inttab_tc0_0DF (__INTTAB_CPU0 + 0x1BE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_223)); }
        .inttab_tc0_0E0 (__INTTAB_CPU0 + 0x1C00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_224)); }
        .inttab_tc0_0E1 (__INTTAB_CPU0 + 0x1C20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_225)); }
        .inttab_tc0_0E2 (__INTTAB_CPU0 + 0x1C40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_226)); }
        .inttab_tc0_0E3 (__INTTAB_CPU0 + 0x1C60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_227)); }
        .inttab_tc0_0E4 (__INTTAB_CPU0 + 0x1C80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_228)); }
        .inttab_tc0_0E5 (__INTTAB_CPU0 + 0x1CA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_229)); }
        .inttab_tc0_0E6 (__INTTAB_CPU0 + 0x1CC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_230)); }
        .inttab_tc0_0E7 (__INTTAB_CPU0 + 0x1CE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_231)); }
        .inttab_tc0_0E8 (__INTTAB_CPU0 + 0x1D00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_232)); }
        .inttab_tc0_0E9 (__INTTAB_CPU0 + 0x1D20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_233)); }
        .inttab_tc0_0EA (__INTTAB_CPU0 + 0x1D40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_234)); }
        .inttab_tc0_0EB (__INTTAB_CPU0 + 0x1D60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_235)); }
        .inttab_tc0_0EC (__INTTAB_CPU0 + 0x1D80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_236)); }
        .inttab_tc0_0ED (__INTTAB_CPU0 + 0x1DA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_237)); }
        .inttab_tc0_0EE (__INTTAB_CPU0 + 0x1DC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_238)); }
        .inttab_tc0_0EF (__INTTAB_CPU0 + 0x1DE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_239)); }
        .inttab_tc0_0F0 (__INTTAB_CPU0 + 0x1E00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_240)); }
        .inttab_tc0_0F1 (__INTTAB_CPU0 + 0x1E20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_241)); }
        .inttab_tc0_0F2 (__INTTAB_CPU0 + 0x1E40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_242)); }
        .inttab_tc0_0F3 (__INTTAB_CPU0 + 0x1E60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_243)); }
        .inttab_tc0_0F4 (__INTTAB_CPU0 + 0x1E80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_244)); }
        .inttab_tc0_0F5 (__INTTAB_CPU0 + 0x1EA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_245)); }
        .inttab_tc0_0F6 (__INTTAB_CPU0 + 0x1EC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_246)); }
        .inttab_tc0_0F7 (__INTTAB_CPU0 + 0x1EE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_247)); }
        .inttab_tc0_0F8 (__INTTAB_CPU0 + 0x1F00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_248)); }
        .inttab_tc0_0F9 (__INTTAB_CPU0 + 0x1F20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_249)); }
        .inttab_tc0_0FA (__INTTAB_CPU0 + 0x1F40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_250)); }
        .inttab_tc0_0FB (__INTTAB_CPU0 + 0x1F60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_251)); }
        .inttab_tc0_0FC (__INTTAB_CPU0 + 0x1F80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_252)); }
        .inttab_tc0_0FD (__INTTAB_CPU0 + 0x1FA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_253)); }
        .inttab_tc0_0FE (__INTTAB_CPU0 + 0x1FC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_254)); }
        .inttab_tc0_0FF (__INTTAB_CPU0 + 0x1FE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_255)); }
    }
    
    /*Fixed memory Allocations for BMHD*/
    CORE_ID = GLOBAL;
    SECTIONS
    {
        .bmhd_0_org (0xaf400000) : FLAGS(arl) { KEEP (*(.bmhd_0_orig)); } > ucb
        .bmhd_1_org (0xaf400200) : FLAGS(arl) { KEEP (*(.bmhd_1_orig)); } > ucb
        .bmhd_2_org (0xaf400400) : FLAGS(arl) { KEEP (*(.bmhd_2_orig)); } > ucb
        .bmhd_3_org (0xaf400600) : FLAGS(arl) { KEEP (*(.bmhd_3_orig)); } > ucb
        .ucb_reserved (0xaf400800) : FLAGS(arl) { } > ucb
        .bmhd_0_copy (0xaf401000) : FLAGS(arl) { KEEP (*(.bmhd_0_copy)); } > ucb
        .bmhd_1_copy (0xaf401200) : FLAGS(arl) { KEEP (*(.bmhd_1_copy)); } > ucb
        .bmhd_2_copy (0xaf401400) : FLAGS(arl) { KEEP (*(.bmhd_2_copy)); } > ucb
        .bmhd_3_copy (0xaf401600) : FLAGS(arl) { KEEP (*(.bmhd_3_copy)); } > ucb
    }
    
    /*Near Abbsolute Addressable Data Sections*/
    /*Near Absolute Data, selectable with patterns and user defined sections*/
    CORE_ID = CPU0;
    SECTIONS
    {
        CORE_SEC(.zdata) (LCF_DSPR0_START): FLAGS(awzl)
        {
            *Ifx_Ssw_Tc0.* (.zdata)
            *Cpu0_Main.* (.zdata)
            *(.zdata_cpu0)
            *(.zdata_cpu0.*)
            . = ALIGN(2);
        } > dsram0 AT> pfls0
        
        CORE_SEC(.zbss) (NOLOAD): FLAGS(awz)
        {
            *Ifx_Ssw_Tc0.* (.zbss)
            *Cpu0_Main.* (.zbss)
            *(.zbss_cpu0)
            *(.zbss_cpu0.*)
        } > dsram0
    }
    
    /*Near Absolute Data, selectable by toolchain*/
    CORE_ID = GLOBAL;
    SECTIONS
    {    
        CORE_SEC(.zdata_powerOn) : FLAGS(awzl)
        {
            *(.zdata.dsprPowerOnInit.cpu0.32bit)
            *(.zdata.dsprPowerOnInit.cpu0.16bit)
            *(.zdata.dsprPowerOnInit.cpu0.8bit)
            . = ALIGN(2);
        } > default_ram AT> pfls0
        
        CORE_SEC(.zdata) : FLAGS(awzl)
        {
            *(.zdata.dsprInit.cpu0.32bit)
            *(.zdata.dsprInit.cpu0.16bit)
            *(.zdata.dsprInit.cpu0.8bit)
            *(.zdata)
            *(.zdata.*)
            *(.gnu.linkonce.z.*)
            . = ALIGN(2);
        } > default_ram AT> pfls0
        
        CORE_SEC(.zbss_powerOn) (NOLOAD) : FLAGS(awz)
        {
            *(.zbss.dsprPowerOnClear.cpu0.32bit)
            *(.zbss.dsprPowerOnClear.cpu0.16bit)
            *(.zbss.dsprPowerOnClear.cpu0.8bit)
        } > default_ram
        
        CORE_SEC(.zbss_noClear) (NOLOAD) : FLAGS(awz)
        {
            *(.zbss.dsprNoInit.cpu0.32bit)
            *(.zbss.dsprNoInit.cpu0.16bit)
            *(.zbss.dsprNoInit.cpu0.8bit)
        } > default_ram
        
        CORE_SEC(.zbss) (NOLOAD) : FLAGS(awz)
        {
            *(.zbss.dsprClearOnInit.cpu0.32bit)
            *(.zbss.dsprClearOnInit.cpu0.16bit)
            *(.zbss.dsprClearOnInit.cpu0.8bit)
            *(.zbss)
            *(.zbss.*)
            *(.bbss)
            *(.bbss.*)
            *(.gnu.linkonce.zb.*)
        } > default_ram
    }

    CORE_ID = GLOBAL;
    SECTIONS
    {
        /*Cpu0_dlmu also is the segment start, all the near lmu data shll be located here*/
        CORE_SEC(.lmuzdata) : FLAGS(awzl)
        {
            *(.zlmudata)
            *(.zlmudata.*)
            . = ALIGN(2);
        } > cpu0_dlmu AT> pfls0
        
        CORE_SEC(.zbss) (NOLOAD) : FLAGS(awz)
        {
            *(.zlmubss)
            *(.zlmubss.*)
        } > cpu0_dlmu
    }
    
    /*Near Absolute Const, selectable with patterns and user defined sections*/
    CORE_ID = GLOBAL;
    SECTIONS
    {
        CORE_SEC(.zrodata) : FLAGS(arzl)
        {
            *Ifx_Ssw_Tc?.* (.zrodata)
            *Cpu?_Main.* (.zrodata)
            *(.zrodata_cpu?)
        } > pfls0
    }
    
    /*Near Absolute Const, selectable by toolchain*/
    CORE_ID = GLOBAL;
    SECTIONS
    {
        CORE_SEC(.zrodata) : FLAGS(arzl)
        {
            *(.zrodata.const.cpu0.32bit)
            *(.zrodata.const.cpu0.16bit)
            *(.zrodata.const.cpu0.8bit)
            *(.zrodata.config.cpu0.32bit)
            *(.zrodata.config.cpu0.16bit)
            *(.zrodata.config.cpu0.8bit)
            *(.zrodata)
            *(.zrodata.*)
        } > pfls0
    }

/*Relative A0/A1/A8/A9 Addressable Sections*/
CORE_ID = GLOBAL;
SECTIONS
{
    /*Relative A0 Addressable Data, selectable with patterns and user defined sections*/
        /*Note: A0 addressable area is common, to make the functions callable in any CPU*/
    /*Relative A0 Addressable Data, selectable by toolchain*/
    CORE_SEC(.sdata) : FLAGS(awsl)
    {
        *(.sdata)
        *(.sdata.*)
        . = ALIGN(2);
    } > default_ram AT> pfls0
    CORE_SEC(.sbss) (NOLOAD): FLAGS(aws)
    {
        *(.sbss)
        *(.sbss.*)
    } > default_ram
    _SMALL_DATA_ = SIZEOF(CORE_SEC(.sdata)) ? ADDR(CORE_SEC(.sdata)) : (ADDR(CORE_SEC(.sdata)) & 0xF0000000) + 32k ;
    __A0_MEM = _SMALL_DATA_;
}

CORE_ID = GLOBAL;
SECTIONS
{
    /*Relative A1 Addressable Const, selectable with patterns and user defined sections*/
        /*Note: A1 addressable area is common, to make the functions callable in any CPU*/
    /*Relative A1 Addressable Const, selectable by toolchain*/
    CORE_SEC(.sdata2) : FLAGS(arsl)
    {
        *(.srodata)
        *(.srodata.*)
    } > default_rom
    _SMALL_DATA2_ = SIZEOF(CORE_SEC(.sdata2)) ? ADDR(CORE_SEC(.sdata2)) : (ADDR(CORE_SEC(.sdata2)) & 0xF0000000) + 32k ;
    __A1_MEM = _SMALL_DATA2_;
}

CORE_ID = GLOBAL;
SECTIONS
{
    /*Relative A8 Addressable Const, selectable with patterns and user defined sections*/
    CORE_SEC(.sdata3) : FLAGS(arsl)
    {
        *(.rodata_a8)
        *(.rodata_a8.*)
    } > default_rom
    
    _SMALL_DATA3_ = SIZEOF(CORE_SEC(.sdata3)) ? ADDR(CORE_SEC(.sdata3)) : (ADDR(CORE_SEC(.sdata3)) & 0xF0000000) + 32k ;
    __A8_MEM = _SMALL_DATA3_;
}

/*Far Data / Far Const Sections, selectable with patterns and user defined sections*/
/*Far Data Sections, selectable with patterns and user defined sections*/
CORE_ID = CPU0 ;
SECTIONS
{
    /*DSRAM0 Sections*/
    CORE_SEC(.data) : FLAGS(awl)
    {
        *Ifx_Ssw_Tc0.* (.data)
        *Cpu0_Main.* (.data)
        *(.data_cpu0)
        *(.data_cpu0.*)
        . = ALIGN(2);
    } > dsram0 AT> pfls0
    
    CORE_SEC(.bss) (NOLOAD): FLAGS(aw)
    {
        *Ifx_Ssw_Tc0.* (.bss)
        *Cpu0_Main.* (.bss)
        *(.bss_cpu0)
        *(.bss_cpu0.*)
    } > dsram0
    
    /*DLMU0 Sections*/
    CORE_SEC(.lmudata) : FLAGS(awl)
    {
        *(.lmudata_cpu0)
        *(.lmudata_cpu0.*)
        . = ALIGN(2);
    } > cpu0_dlmu AT> pfls0
    
    CORE_SEC(.lmubss) : FLAGS(aw)
    {
        *(.lmubss_cpu0)
        *(.lmubss_cpu0.*)
    } > cpu0_dlmu
}

CORE_ID = GLOBAL;
SECTIONS
{
    /*Relative A9 Addressable Data, selectable with patterns and user defined sections*/
    CORE_SEC(.sdata4) :
    {
        *(.a9sdata)
        *(.a9sdata.*)
        . = ALIGN(2);
    } > cpu0_dlmu AT> pfls0
    
    CORE_SEC(.sbss4) :
    {
        *(.a9sbss)
        *(.a9sbss.*)    
    } > cpu0_dlmu
    
    _SMALL_DATA4_ = SIZEOF(CORE_SEC(.sdata4)) ? ADDR(CORE_SEC(.sdata4)) : (ADDR(CORE_SEC(.sdata4)) & 0xF0000000) + 32k ;
    __A9_MEM = _SMALL_DATA4_;
}

/*Far Data Sections, selectable by toolchain*/
CORE_ID = GLOBAL;
SECTIONS
{
    CORE_SEC(.bss_noClear) (NOLOAD) : FLAGS(aw)
    {
        *(.bss.farDsprNoInit.cpu0.32bit)
        *(.bss.farDsprNoInit.cpu0.16bit)
        *(.bss.farDsprNoInit.cpu0.8bit)
    } > default_ram
    
    CORE_SEC(.data) : FLAGS(awl)
    {
        *(.data.farDsprInit.cpu0.32bit)
        *(.data.farDsprInit.cpu0.16bit)
        *(.data.farDsprInit.cpu0.8bit)
        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d.*)
        . = ALIGN(2);
    } > default_ram AT> pfls0
    
    CORE_SEC(.bss) (NOLOAD) : FLAGS(aw)
    {
        *(.bss.farDsprClearOnInit.cpu0.32bit)
        *(.bss.farDsprClearOnInit.cpu0.16bit)
        *(.bss.farDsprClearOnInit.cpu0.8bit)
        *(.bss)
        *(.bss.*)
        *(.gnu.linkonce.b.*)
    } > default_ram
    
    .heap  : FLAGS(aw)
    {
    . = ALIGN(4);
    __HEAP = .;
    . += LCF_HEAP_SIZE;
    __HEAP_END = .;
    } > default_ram
    
    CORE_SEC(.lmudata) : FLAGS(awl)
    {
        *(.lmudata)
        *(.lmudata.*)
        . = ALIGN(2);
    } > cpu0_dlmu AT> pfls0
    
    CORE_SEC(.lmubss) : FLAGS(aw)
    {
        *(.lmubss)
        *(.lmubss.*)
    } > cpu0_dlmu
}
/*Far Const Sections, selectable with patterns and user defined sections*/
CORE_ID = CPU0;
SECTIONS
{
    CORE_SEC(.rodata) : FLAGS(arl)
    {
        *Ifx_Ssw_Tc0.* (.rodata)
        *Cpu0_Main.* (.rodata)
        *(.rodata_cpu0)
        *(.rodata_cpu0.*)
    } > pfls0
}

/*Far Const Sections, selectable by toolchain*/
CORE_ID = GLOBAL;
SECTIONS
{
    CORE_SEC(.rodata) : FLAGS(arl)
    {
        *(.rodata.farConst.cpu0.32bit)
        *(.rodata.farConst.cpu0.16bit)
        *(.rodata.farConst.cpu0.8bit)
        *(.rodata)
        *(.rodata.*)
    *(.gnu.linkonce.r.*)
    /*
     * Create the clear and copy tables that tell the startup code
     * which memory areas to clear and to copy, respectively.
     */
    . = ALIGN(4) ;
    PROVIDE(__clear_table = .);
    LONG(0 + ADDR(.CPU0.zbss));       LONG(SIZEOF(.CPU0.zbss));
    LONG(0 + ADDR(.CPU0.bss));        LONG(SIZEOF(.CPU0.bss));
    LONG(0 + ADDR(.CPU0.lmubss));     LONG(SIZEOF(.CPU0.lmubss));
    LONG(0 + ADDR(.zbss));            LONG(SIZEOF(.zbss));
    LONG(0 + ADDR(.sbss));            LONG(SIZEOF(.sbss));
    LONG(0 + ADDR(.bss));             LONG(SIZEOF(.bss));
    LONG(0 + ADDR(.lmubss));          LONG(SIZEOF(.lmubss));
    LONG(0 + ADDR(.sbss4));           LONG(SIZEOF(.sbss4));
    LONG(-1);                         LONG(-1);
    PROVIDE(__clear_table_powerOn = .);
    LONG(0 + ADDR(.zbss_powerOn));    LONG(SIZEOF(.zbss_powerOn));
    LONG(-1);                         LONG(-1);
    PROVIDE(__copy_table = .);
    LONG(LOADADDR(.CPU0.zdata));      LONG(0 + ADDR(.CPU0.zdata));      LONG(SIZEOF(.CPU0.zdata));
    LONG(LOADADDR(.CPU0.data));       LONG(0 + ADDR(.CPU0.data));       LONG(SIZEOF(.CPU0.data));
    LONG(LOADADDR(.CPU0.lmudata));    LONG(0 + ADDR(.CPU0.lmudata));    LONG(SIZEOF(.CPU0.lmudata));
    LONG(LOADADDR(.zdata));           LONG(0 + ADDR(.zdata));           LONG(SIZEOF(.zdata));
    LONG(LOADADDR(.sdata));           LONG(0 + ADDR(.sdata));           LONG(SIZEOF(.sdata));
    LONG(LOADADDR(.data));            LONG(0 + ADDR(.data));            LONG(SIZEOF(.data));
    LONG(LOADADDR(.lmudata));         LONG(0 + ADDR(.lmudata));         LONG(SIZEOF(.lmudata));
    LONG(LOADADDR(.sdata4));          LONG(0 + ADDR(.sdata4));          LONG(SIZEOF(.sdata4));
    LONG(LOADADDR(.CPU0.psram_text)); LONG(0 + ADDR(.CPU0.psram_text)); LONG(SIZEOF(.CPU0.psram_text));
    LONG(-1);                         LONG(-1);                         LONG(-1);
    PROVIDE(__copy_table_powerOn = .) ;
    LONG(LOADADDR(.zdata_powerOn));   LONG(0 + ADDR(.zdata_powerOn));   LONG(SIZEOF(.zdata_powerOn));
    LONG(-1);                         LONG(-1);                         LONG(-1);
    . = ALIGN(8);
    } > default_rom
}

/*Code selections*/
/*Code Sections, selectable with patterns and user defined sections*/
CORE_ID = CPU0;
SECTIONS
{
    CORE_SEC(.text) : FLAGS(axl)
    {
        . = ALIGN(2);
        *Ifx_Ssw_Tc0.*(.text)
        *Cpu0_Main.*(.text)
        *Ifx_Ssw_Tc0.*(.text.*)
        *Cpu0_Main.*(.text.*)
        *(.text_cpu0)
        *(.text_cpu0.*)
    } > pfls0
    
    /*
     * Code executed before calling main extra section for C++ constructor init
     *  -------------------------Start-----------------------------------------
     */
    .init :
    {
        PROVIDE(__init_start = .);
        KEEP(*(.init))
        KEEP(*(.init*))
        PROVIDE(__init_end = .);
        . = ALIGN(8);
    
    } > pfls0
    
    .fini :
    {
        PROVIDE(__fini_start = .);
        KEEP(*(.fini))
        KEEP(*(.fini*))
        PROVIDE(__fini_end = .);
        . = ALIGN(8);
    } > pfls0
    
    /*
     * Code executed before calling main extra section for C++ constructor init
     *  -------------------------End-----------------------------------------
     */
    CORE_SEC(.psram_text)  : FLAGS(awx)
    {
        . = ALIGN(2);
        *(.psram_text_cpu0)
        *(.psram_text_cpu0.*)
        *(.cpu0_psram)
        *(.cpu0_psram.*)
        . = ALIGN(2);
    } > psram0 AT> pfls0
}

/*Code Sections, selectable by toolchain*/
CORE_ID = GLOBAL;
SECTIONS
{
    CORE_SEC(.text) : FLAGS(axl)
    {
        *(.text.fast.pfls.cpu0)
        *(.text.slow.pfls.cpu0)
        *(.text.5ms.pfls.cpu0)
        *(.text.10ms.pfls.cpu0)
        *(.text.callout.pfls.cpu0)
        *(.text)
        *(.text.*)
        *(.gnu.linkonce.t.*)
        *(.gnu.warning)        /* .gnu.warning sections are handled specially by elf32.em. */
        . = ALIGN(4);
    } > default_rom

    /*
     * C++ exception handling tables.  NOTE: gcc emits .eh_frame
     * sections when compiling C sources with debugging enabled (-g).
     * If you can be sure that your final application consists
     * exclusively of C objects (i.e., no C++ objects), you may use
     * the -R option of the "strip" and "objcopy" utilities to remove
     * the .eh_frame section from the executable.
     */
    .eh_frame_hdr :
    { 
        *(.eh_frame_hdr)
    } > default_rom
	
    .eh_frame  :
    {
        *(.gcc_except_table)
        __EH_FRAME_BEGIN__ = . ;
        KEEP (*(.eh_frame))
        __EH_FRAME_END__ = . ;
        . = ALIGN(8);
    } > default_rom

    /*
     * Constructors and destructors.
     */
    .ctors : FLAGS(ar)
    {
        __CTOR_LIST__ = . ;
        LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2);
        /*
         * Code executed before calling main extra section for C++ constructor init
         *  -------------------------Start-----------------------------------------
         */
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o ) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
        /*
         * Code executed before calling main extra section for C++ constructor init
         *  -------------------------End-----------------------------------------
         */
        LONG(0) ;
        __CTOR_END__ = . ;
        . = ALIGN(8);
    } > default_rom
    .dtors : FLAGS(ar)
    {
        __DTOR_LIST__ = . ;
        LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2);
        /*
         * Code executed before calling main extra section for C++ distructor init
         *  -------------------------Start-----------------------------------------
         */
        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o ) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
        /*
         * Code executed before calling main extra section for C++ distructor init
         *  -------------------------End-----------------------------------------
         */
        LONG(0) ;
        __DTOR_END__ = . ;
        . = ALIGN(8);
    } > default_rom
    /*
     * DWARF debug sections.
     * Symbols in the DWARF debugging sections are relative to the
     * beginning of the section, so we begin them at 0.
     */
    /*
     * DWARF 1
     */
    .comment         0 : { *(.comment) }
    .debug           0 : { *(.debug) }
    .line            0 : { *(.line) }
    /*
     * GNU DWARF 1 extensions
     */
    .debug_srcinfo   0 : { *(.debug_srcinfo) }
    .debug_sfnames   0 : { *(.debug_sfnames) }
    /*
     * DWARF 1.1 and DWARF 2
     */
    .debug_aranges   0 : { *(.debug_aranges) }
    .debug_pubnames  0 : { *(.debug_pubnames) }
    /*
     * DWARF 2
     */
    .debug_info      0 : { *(.debug_info) }
    .debug_abbrev    0 : { *(.debug_abbrev) }
    .debug_line      0 : { *(.debug_line) }
    .debug_frame     0 : { *(.debug_frame) }
    .debug_str       0 : { *(.debug_str) }
    .debug_loc       0 : { *(.debug_loc) }
    .debug_macinfo   0 : { *(.debug_macinfo) }
    .debug_ranges    0 : { *(.debug_ranges) }
    /*
     * SGI/MIPS DWARF 2 extensions
     */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }
    /*
     * Optional sections that may only appear when relocating.
     */
    /*
     * Optional sections that may appear regardless of relocating.
     */
    .version_info    0 : { *(.version_info) }
    .boffs           0 : { KEEP (*(.boffs)) }
}

