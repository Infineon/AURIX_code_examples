#if _MSC_VER
#elif defined(__GNUC__) && ((IFX_CFG_OE_AL_UC == IFX_CFG_OE_AL_UC_XMC_XMCLIB) ||(IFX_CFG_OE_AL_UC == IFX_CFG_OE_AL_UC_CY_PDL))
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"
#elif defined(__GNUC__)
#elif defined(__TASKING__)
#else
#error Unknown compiler
#endif
