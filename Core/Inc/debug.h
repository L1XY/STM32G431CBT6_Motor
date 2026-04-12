#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "usart.h"
#include "stdio.h"
#include "stdint.h"

extern char debug_buf[128];

#define debug(...) {\
    int len = 0;\
    len = snprintf(debug_buf, sizeof(debug_buf), __VA_ARGS__);\
    if (len > 0)\
    {\
        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)debug_buf, len);\
    }\
}

#endif
