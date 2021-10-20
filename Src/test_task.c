
#include <stdint.h>
#include "tasks.h"
#include "pt.h"
#include "stm32f4xx_hal.h"

#if defined(USART_DEBUG) || defined(GDB_SEMIHOSTING)
#define DEBUG_PRINTF(...) printf( __VA_ARGS__);
#else
#define DEBUG_PRINTF(...)
#endif

PT_THREAD (test_task(struct pt *pt)) 
{
    static uint32_t msCount;
    PT_BEGIN(pt);
    DEBUG_PRINTF("TEST task2\n\r");
    msCount = HAL_GetTick();
    static int test=0;
    while(1)
    {
        PT_WAIT_UNTIL(pt, (HAL_GetTick() - msCount) > 1000);
        DEBUG_PRINTF("TEST CNT:%d\n\r",test++);
        msCount = HAL_GetTick();
    } 
    PT_END(pt);
}