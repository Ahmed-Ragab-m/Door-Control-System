/*
 * PWM_Interface.h
 *
 * Created: 3/17/2024 11:04:50 AM
 *  Author: Lenovo
 */ 
#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_
#include "STD_TYPES.h"

#define FAST_PWM           1
#define PWM_PHASE_CORRECT  2

/*PWM CHANNEL0 OCO*/
void PWM_voidInitChanel0(void);
void PWM_voidGenerateChanel0(u8 DutyCycle);
void PWM_voidStopChanel0(void);

/*PWM CHANNEL1A OC1A*/
void PWM_voidInitChanel1A(void);
void PWM_voidGeneratePWM_Chanel1A(u16 Frequency_hz,f32 DutyCycle);
void PWM_voidStop_Channel1A(void);


#endif /* PWM_INTERFACE_H_ */