/*
 * SERVO_Program.c
 *
 * Created: 3/18/2024 1:11:02 PM
 *  Author: AHMED RAGAB
 */ 
#include "DIO/DIO_Interface.h"
#include "PWM/PWM_Interface.h"
#include "SERVO/SERVO_Interface.h"

void SERVO_voidStart(u8 copy_u8Angle)
{
	u8 local_u8desired = (((copy_u8Angle + 90)/180)*5) + 5;
	PWM_voidGeneratePWM_Chanel1A(50,local_u8desired);
	
}


void SERVO_voidStop(void)
{
	PWM_voidStop_Channel1A();
}
