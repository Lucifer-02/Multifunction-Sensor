/* File: Servo.h */

void Servo_MoveTo(uint8_t Angle, uint8_t *PWM1DC);  // Move Servo corresponding to angles
void TMR1_CMP_Unit(void);   // Set Compare mode to TIMER1
void Close_Window(void);    // Close window by Servo
void Open_Window(void);     // Open window by Servo
void Open_Half_Window(void);	// Open half window by Servo

uint8_t  PWM1DC = 15;    // Duty Cycle * 100