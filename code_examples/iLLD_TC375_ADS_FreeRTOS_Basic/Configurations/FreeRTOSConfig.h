#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION                       1
#define configUSE_IDLE_HOOK                        0

#define configCPU_CLOCK_HZ                         ( ( unsigned long ) 300000000UL )
#define configTICK_RATE_HZ                         ( ( TickType_t ) 1000UL )

#define configMAX_PRIORITIES                       ( 10 )
#define configMINIMAL_STACK_SIZE                   ( ( unsigned short ) 256 )
#define configTOTAL_HEAP_SIZE                      ( ( size_t ) ( 32U * 1024U ) )
#define configMAX_TASK_NAME_LEN                    ( 16 )

#define configENABLE_BACKWARD_COMPATIBILITY        0
#define configUSE_TRACE_FACILITY                   0
#define configUSE_16_BIT_TICKS                     0
#define configIDLE_SHOULD_YIELD                    0
#define configUSE_MALLOC_FAILED_HOOK               0
#define configCHECK_FOR_STACK_OVERFLOW             1
#define configUSE_TICK_HOOK                        0
#define configUSE_COUNTING_SEMAPHORES              1
#define configUSE_RECURSIVE_MUTEXES                1
#define configUSE_MUTEXES                          1
#define configRECORD_STACK_HIGH_ADDRESS            1

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS    5

/* Software timer configuration. */
#define configUSE_TIMERS                           ( 1 )
#define configTIMER_TASK_PRIORITY                  ( 9 )
#define configTIMER_QUEUE_LENGTH                   ( 5 )
#define configTIMER_TASK_STACK_DEPTH               configMINIMAL_STACK_SIZE

/* Set the following definitions to 1 to include the API function, or zero
 * to exclude the API function. */
#define INCLUDE_vTaskPrioritySet                   1
#define INCLUDE_uxTaskPriorityGet                  1
#define INCLUDE_vTaskDelete                        1
#define INCLUDE_vTaskCleanUpResources              1
#define INCLUDE_vTaskSuspend                       1
#define INCLUDE_vTaskDelayUntil                    1
#define INCLUDE_vTaskDelay                         1

/* Interrupt above priority 31 are not effected by critical sections, but cannot call interrupt safe FreeRTOS functions. */
#define configMAX_API_CALL_INTERRUPT_PRIORITY      31

/* Default definition of configASSERT(). */
#ifdef DEBUG
#ifdef __TASKING__
#define configASSERT( x )    if( ( x ) == 0 ) { __disable(); __debug(); }
#endif
#ifdef __clang__
#define configASSERT( x )    if( ( x ) == 0 ) { __builtin_tricore_disable(); __builtin_tricore_debug(); }
#endif
#else
#define configASSERT( x ) ((void)(x)) /* Empty macro to remove compiler warning(s) about unused variables */
#endif

/* AURIX TCxxx definitions */
#define configCONTEXT_INTERRUPT_PRIORITY    1 
#define configTIMER_INTERRUPT_PRIORITY      2 /* This value must not be bigger then context priority */
#define configCPU_NR                        0
#define configPROVIDE_SYSCALL_TRAP          0
#define configSYSCALL_CALL_DEPTH            2
#define configSTM                           ( ( uint32_t * ) (0xF0001000 + configCPU_NR*0x100 ) )
#define configSTM_SRC                       ( ( uint32_t * ) (0xF0038300 + configCPU_NR*0x8) )
#define configSTM_CLOCK_HZ                  ( 100000000 )
#define configSTM_DEBUG                     ( 1 )
#define configCONTEXT_SRC                   ( ( uint32_t * ) 0xF0038990 )

#endif /* FREERTOS_CONFIG_H */
