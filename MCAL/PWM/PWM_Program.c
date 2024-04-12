/*
 * PWM_Program.c
 *
 * Created: 3/17/2024 11:05:59 AM
 *  Author: Ahmed Ragab
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PWM_Private.h"
#include "PWM_Config.h"
#include "PWM_Interface.h"

/*PWM FOR CHANNEL0 OCO*/
void PWM_voidInitChanel0(void)
{
	#if CHANNEL0_MODE==FAST_PWM
	//Select mode fast PWM mode
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	// Select Non Inverting PWM mode
	CLEAR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#elif CHANNEL0_MODE==PWM_PHASE_CORRECT
	// select PWM phase correct mode
	SET_BIT(TCCR0_REG,WGM00);
	CLEAR_BIT(TCCR0_REG,WGM01);
	//Select Non Inverting PWM phase correct mode
	CLEAR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
    #endif
}

void PWM_voidGenerateChanel0(u8 DutyCycle)
{
	// select FAST PWM MODE
	#if CHANNEL0_MODE==FAST_PWM
	if(DutyCycle<=100)
	{
		OCR0_REG=((DutyCycle*256)/100)-1;
		// SET PRSECALER 64
		SET_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
	}
	else
	{
		// return error
	}
	// select FAST PWM PHASE CORRECT MODE
	#elif CHANNEL0_MODE==PWM_PHASE_CORRECT
	if(DutyCycle<=100)
	{
		OCR0_REG=((DutyCycle*510)/2)-1;
		// SET PRSECALER 64
		SET_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
	}
	else
	{
		// return error
	}
	#endif
	
}

void PWM_voidStopChanel0(void)
{
	CLEAR_BIT(TCCR1B_REG,CS10);
	CLEAR_BIT(TCCR1B_REG,CS11);
	CLEAR_BIT(TCCR1B_REG,CS12);
}

/*****************************************************************************/
//PWM FOR CHANNEL1 OCR1

void PWM_voidInitChanel1A(void)
{
	//Select mode fast PWM mode(14)
	CLEAR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);
	// Select Non Inverting PWM mode
	CLEAR_BIT(TCCR1A_REG, COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
	
}

void PWM_voidGeneratePWM_Chanel1A(u16 Frequency_hz,f32 DutyCycle)
{
	if(DutyCycle<=100)
	{
		// Tick time 4us
		ICR1_REG=(((u32)1000000/Frequency_hz)/4)-1;
		OCR1A_REG=((DutyCycle*(ICR1_REG+1))/100)-1;
		// SET PRSECALER 64
		SET_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLEAR_BIT(TCCR1B_REG,CS12);
	}
	else
	{
		// return error
	}
	
}

void PWM_voidStop_Channel1A(void)
{
	CLEAR_BIT(TCCR1B_REG,CS10);
	CLEAR_BIT(TCCR1B_REG,CS11);
	CLEAR_BIT(TCCR1B_REG,CS12);
}
