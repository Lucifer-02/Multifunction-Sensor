#include <xc.h>
#include <stdint.h>
#include "Uart.h"
#include "config.h"

void UART_Rx_Init(void){
    // Baud rate configuration
    BRGH = 1;
    SPBRG = 25;
    // Enable Asynchronous Serial Port
    SYNC = 0;
    SPEN = 1;
    // Configure Rx-Tx pin for UART 
    TRISC6 = 1;
    TRISC7 = 1;
    // Enable continuous data reception
    CREN = 1;
    // Enable interrupt flag
    RCIE = 1;
}
