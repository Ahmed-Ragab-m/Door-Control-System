/*
 * PWM_Private.h
 *
 * Created: 3/17/2024 11:05:11 AM
 *  Author: Lenovo
 */ 


#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

/* TIMER0 Registers*/
/*TCCR0_REGISTER*/
#define TCCR0_REG   (*(volatile u8*)0x53)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7
/*TCNT0_REGISTER*/
#define TCNT0_REG   (*(volatile u8*)0x52)
/*OCR0_REGISTER*/
#define OCR0_REG    (*(volatile u8*)0x5C)
/*TTIMSK_REGISTER*/
#define TIMSK_REG   (*(volatile u8*)0x59)
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7
/*TIFR_REGISTER*/
#define TIFR_REG    (*(volatile u8*)0x58)
#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7
/*TIFR_REGISTER*/
#define TWCR_REG    (*(volatile u8*)0x56)
#define SPMCR_REG   (*(volatile u8*)0x57)


/*TIMER1 REGISTERS*/

/*TIMER1 TCCR1A_REG */
#define TCCR1A_REG    (*(volatile u8*)0x4F)
#define WGM10     0
#define WGM11     1
#define FOC1B     2
#define FOC1A     3
#define COM1B0    4
#define COM1B1    5
#define COM1A0    6
#define COM1A1    7

/*TIMER1 TCCR1B_REG */
#define TCCR1B_REG   (*(volatile u8*)0x4E)
#define CS10     0
#define CS11     1
#define CS12     2
#define WGM12    3
#define WGM13    4
#define ICES1    6
#define ICNC1    7

/*TIMER1 TCNT1_REG */
#define TCNT1H_REG  (*(volatile u8*)0x4D)
#define TCNT1L_REG  (*(volatile u8*)0x4C)
#define TCNT1_REG   (*(volatile u16*)0x4C)

/*TIMER1 OCR1A_REG */
#define OCR1AH_REG  (*(volatile u8*)0x4B)
#define OCR1AL_REG  (*(volatile u8*)0x4A)
#define OCR1A_REG   (*(volatile u16*)0x4A)

/*TIMER1 OCR1B_REG */
#define OCR1BH_REG  (*(volatile u8*)0x49)
#define OCR1BL_REG  (*(volatile u8*)0x48)
#define OCR1B_REG   (*(volatile u16*)0x48)

/*TIMER1 ICR1_REG */
#define ICR1H_REG  (*(volatile u8*)0x47)
#define ICR1L_REG  (*(volatile u8*)0x46)
#define ICR1_REG   (*(volatile u16*)0x46)

/*TIMER1 TIMSK_REG */
#define TIMSK_REG  (*(volatile u8*)0x59)
#define TOIE0     0
#define OCIE0     1
#define TOIE1     2
#define OCIE1B    3
#define OCIE1A    4
#define TICIE1    5
#define TOIE2     6
#define OCIE2     7

/*TIMER1 TIFR_REG */
#define TIFR_REG  (*(volatile u8*)0x58)
#define TOV0   0
#define OCF0   1
#define TOV1   2
#define OCF1B  3
#define OCF1A  4
#define ICF1   5
#define TOV2   6
#define OCF2   7

#endif /* PWM_PRIVATE_H_ */