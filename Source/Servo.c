#include <xc.h>
#include <stdint.h>
#include "Servo.h"
#include "config.h"

void TMR1_CMP_Unit(void)
{
    // Configure the Timer1 module to Counter mode
    TMR1 = 0;
    T1CKPS0 = 0;    // Prescale 1:1
    T1CKPS1 = 0;
    TMR1CS = 0;     // Internal clock 
    T1OSCEN = 1;    //  Oscillator is shut-off
    T1SYNC = 0;     // Do not synchronize external clock input
    TMR1ON = 1;     // Enables Timer1
    
    // Configure the CCP1 module to Compare mode
    CCP1M0 = 1;
    CCP1M1 = 1;
    CCP1M2 = 0;
    CCP1M3 = 1;

    CCPR1 = 100;    // Set value to compare
    
    // Enable CCP1 Interrupt
    CCP1IE = 1;
    PEIE = 1;
    GIE = 1;

}

void Servo_MoveTo(uint8_t Angle, uint8_t *PWM1DC) 
{
   // Angle is ranging from 0 upto 180 
   double DC = (0.04 + (double)Angle*11/9000) * 100;

   *PWM1DC = (uint8_t)DC;
}

void Close_Window(void)
{
    Servo_MoveTo(0, &PWM1DC);
}

void Open_Window(void)
{
        Servo_MoveTo(90, &PWM1DC);
}

void Open_Half_Window(void)
{
    Servo_MoveTo(45,&PWM1DC);
}

