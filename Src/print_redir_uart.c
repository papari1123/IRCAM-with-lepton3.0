#include "print_redir_uart.h"


#ifdef USART_DEBUG 
/*printf retarget to UART*/
UART_HandleTypeDef* huart_debug;

void APP_UART_DEBUG_Init(UART_HandleTypeDef* huart)
{
    huart_debug = huart;
}


int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(huart_debug, ptr, len, 1000); //print the input ptr.
    return len; //return length.
}
#endif