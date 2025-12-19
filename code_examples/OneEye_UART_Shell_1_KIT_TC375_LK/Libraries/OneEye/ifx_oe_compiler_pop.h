#if _MSC_VER
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__TASKING__)
#else
#error Unknown compiler
#endif
