#include <xc.h>
#include <stdint.h>
#include "Servo.h"
#include "config.h"
#include "Uart.h"

uint8_t TMR1_COUNTER = 0; 
uint8_t Data = 'A'; // Data from Bluetooth

void main(void) {
    
    TRISB0 = 0;   // Configure PB0 as output to control Servo
    TRISB1 = 1;   // Configure PB1 as output to receive Control signals
    TRISD = 0x00;
    PORTD = 0xFF;
    RB0 = 0;

    TMR1_CMP_Unit();    // Configure for Timer1 Compare
    UART_Rx_Init();     // Confiture for UART Receiver

    while(1)
    {   
        PORTD = Data;
        if(Data == 'A') // Auto mode
        {
            if(AUTO_CRL_SIG)
            {   
                Open_Window();  
            }
            else
            {
                Close_Window(); 
            }
        }
        else{   // Manual mode

            switch(Data){

                case 'O':   Open_Window(); break;                        
                case 'C':   Close_Window(); break;                        
                case 'H':   Open_Half_Window(); break;                                      
                default:    break;
                       
            }

        }

    }
  
    return;
}

void __interrupt() ISR(void){   
    // Generate signals PWM
    if(CCP1IF){

        TMR1_COUNTER++;

        if(TMR1_COUNTER >= PWM1DC)
        {
            SERVO_CRL = 0;
        }
        if(TMR1_COUNTER == 200)
        {
            SERVO_CRL = 1;
            TMR1_COUNTER = 0;
        }

        CCP1IF = 0;
    }
    // Receive Bluetooth Datas
    if(RCIF == 1){

        Data = RCREG;

        RCIF = 0;
    }
    
}

