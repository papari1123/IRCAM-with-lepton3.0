
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
    while(1)
    {
        msCount = HAL_GetTick();
        while(1)
        {
            if( (HAL_GetTick() - msCount) > 3000 )
			{
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
                DEBUG_PRINTF("TEST CNT");
                break;
            }
        }
    }   
    PT_END(pt);
}