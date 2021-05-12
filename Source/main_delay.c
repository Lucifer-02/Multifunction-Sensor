#include <xc.h>
#include <stdint.h>
#include "config.h"

#define _XTAL_FREQ 4000000


void Servo_move90();
void Servo_move180();


void main(void) {
    
    TRISD = 0x00;   // Configure PORTD as output to control Servo
    PORTD = 0x00;
    TRISC = 0xff;   // Configure PORTC as input to receive Processer signal

    while(1)
    {
        if(RC7)
        {   
          Servo_move90();

        }
        else 
        {
          Servo_move180();

        }
      }

}

void Servo_move90()
{
    int i;
    for(i = 0; i<50;i++)
    {
                RD0 = 1;
          __delay_ms(1);
          RD0 = 0;
          __delay_ms(19);

    }
    __delay_ms(10);
}

void Servo_move180()
{
    int i;
    for(i = 0; i<50;i++)
    {
                RD0 = 1;
          __delay_ms(2.5);
          RD0 = 0;
          __delay_ms(17.5);

    }
    __delay_ms(10);
}
