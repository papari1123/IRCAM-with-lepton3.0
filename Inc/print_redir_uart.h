#include "stm32f4xx_hal.h"
#ifdef USART_DEBUG
int _write (int file, char *ptr, int len);
void APP_UART_DEBUG_Init(UART_HandleTypeDef* huart);
#endif
