#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

/*DIO Initialize ALL pins Direction AS INPUT OR OUTPUT*/

void DIO_voidSetPinDirection(DIO_PINS PIN,PIN_STATUS status)
{
	DIO_PORT PORT=PIN/8;
	u8 PIN_NUM=PIN%8;
	switch(status)
	{
		case OUTPUT:
		switch(PORT)
		{
			case PA:
			SET_BIT(DDRA,PIN_NUM);
			CLEAR_BIT(PORTA,PIN_NUM);
			break;
			case PB:
			SET_BIT(DDRB,PIN_NUM);
			CLEAR_BIT(PORTB,PIN_NUM);
			break;
			case PC:
			SET_BIT(DDRC,PIN_NUM);
			CLEAR_BIT(PORTC,PIN_NUM);
			break;
			case PD:
			SET_BIT(DDRD,PIN_NUM);
			CLEAR_BIT(PORTD,PIN_NUM);
			break;
		}
		break;
		case INFREE:
		switch(PORT)
		{
			case PA:
			CLEAR_BIT(DDRA,PIN_NUM);
			CLEAR_BIT(PORTA,PIN_NUM);
			break;
			case PB:
			CLEAR_BIT(DDRB,PIN_NUM);
			CLEAR_BIT(PORTB,PIN_NUM);
			break;
			case PC:
			CLEAR_BIT(DDRC,PIN_NUM);
			CLEAR_BIT(PORTC,PIN_NUM);
			break;
			case PD:
			CLEAR_BIT(DDRD,PIN_NUM);
			CLEAR_BIT(PORTD,PIN_NUM);
			break;
		}
		break;
		case INPULL_UP:
		switch(PORT)
		{
			case PA:
			CLEAR_BIT(DDRA,PIN_NUM);
			SET_BIT(PORTA,PIN_NUM);
			break;
			case PB:
			CLEAR_BIT(DDRB,PIN_NUM);
			SET_BIT(PORTB,PIN_NUM);
			break;
			case PC:
			CLEAR_BIT(DDRC,PIN_NUM);
			SET_BIT(PORTC,PIN_NUM);
			break;
			case PD:
			CLEAR_BIT(DDRD,PIN_NUM);
			SET_BIT(PORTD,PIN_NUM);
			break;
		}
		break;
	}
}

/* SET VALUE OF PIN AS HIGH OR LOE*/

void DIO_voidSetPinValue(DIO_PINS PIN,PIN_VOLT volt)
{
	DIO_PORT PORT=PIN/8;
	u8 PIN_NUM=PIN%8;
	
	
	if(volt==LOW)
	{
		switch(PORT)
		{
			case PA:
			CLEAR_BIT(PORTA,PIN_NUM);
			break;
			case PB:
			CLEAR_BIT(PORTB,PIN_NUM);
			break;
			case PC:
			CLEAR_BIT(PORTC,PIN_NUM);
			break;
			case PD:
			CLEAR_BIT(PORTD,PIN_NUM);
			break;
		}

	}
	
	else if(volt==HIGH)
	{
		switch(PORT)
		{
			case PA:
			SET_BIT(PORTA,PIN_NUM);
			break;
			case PB:
			SET_BIT(PORTB,PIN_NUM);
			break;
			case PC:
			SET_BIT(PORTC,PIN_NUM);
			break;
			case PD:
			SET_BIT(PORTD,PIN_NUM);
			break;
			
		}
	}
	
	
}

/*GET THE VALUE OF PIN 1 OR 0*/

PIN_VOLT DIO_voidGetPinValue(DIO_PINS PIN)
{
	DIO_PORT PORT=PIN/8;
	u8 PIN_NUM=PIN%8;
	PIN_VOLT volt=LOW;
	switch(PORT)
	{
		case PA:
		volt= GET_BIT(PINA,PIN_NUM);
		break;
		case PB:
		volt= GET_BIT(PINB,PIN_NUM);
		break;
		case PC:
		volt= GET_BIT(PINC,PIN_NUM);
		break;
		case PD:
		volt= GET_BIT(PIND,PIN_NUM);
		break;
	}
	return volt;
}

/* Toggle pin value 0 or 1*/

void DIO_voidTogglePinValue(DIO_PINS PIN)
{
	DIO_PORT PORT=PIN/8;
	u8 PIN_NUM=PIN%8;
	switch(PORT)
	{
		case PA:
		TOGGLE_BIT(PORTA,PIN_NUM);
		break;
		case PB:
		TOGGLE_BIT(PORTB,PIN_NUM);
		break;
		case PC:
		TOGGLE_BIT(PORTC,PIN_NUM);
		break;
		case PD:
		TOGGLE_BIT(PORTD,PIN_NUM);
		break;
	}
}

/*set all pin direction such as input or output*/

void DIO_voidSetAllPinsDirections(void)
{
	DIO_PINS i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_voidSetPinDirection(i,PINS_Arr[i]);
	}
	
	
}

/*SET Value To PORT */

void DIO_voidSetPortValue(DIO_PORT PORT,u8 data)
{
	switch(PORT)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		PORTC=data;
		break;
		case PD:
		PORTD=data;
		break;
	}
	
}



u8 DIO_u8GetPortValue(DIO_PORT PORT)
{
	u8 PortValue=0;
	switch(PORT)
	{
		case PA:
		PortValue=PORTA;
		break;
		case PB:
		PortValue=PORTA;
		break;
		case PC:
		PortValue=PORTA;
		break;
		case PD:
		PortValue=PORTA;
		break;
	}
	return PortValue;
}

void DIO_voidTogglePortValue(DIO_PORT PORT)
{
	switch(PORT)
	{
		case PA:
		PORTA=PORTA^0XFF;
		break;
		case PB:
		PORTB=PORTB^0XFF;
		break;
		case PC:
		PORTC=PORTC^0XFF;
		break;
		case PD:
		PORTD=PORTD^0XFF;
		break;
	}
}
