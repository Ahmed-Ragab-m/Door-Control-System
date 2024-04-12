

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "STD_TYPES.h"

typedef enum{         //  DIO PORTS
	PA,
	PB,
	PC,
	PD
}DIO_PORT;

typedef enum{         //  PIN STATUS
	INFREE,
	INPULL_UP,
	OUTPUT
}PIN_STATUS;

typedef enum{         //  PIN VOLT
	LOW,
	HIGH
	}PIN_VOLT;

typedef enum{         // DIO PINS 
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_PINS;

/*DIO Intialize All Pins SUCH AS OUTPUT, INFREE, INPUT_PULLUP*/
void DIO_voidSetAllPinsDirections(void);
/* Pin APIS*/
void DIO_voidSetPinDirection(DIO_PINS PIN,PIN_STATUS status);
void DIO_voidSetPinValue(DIO_PINS PIN,PIN_VOLT volt);
PIN_VOLT DIO_voidGetPinValue(DIO_PINS PIN);
void DIO_voidTogglePinValue(DIO_PINS PIN);

/* Port Apis */	
void DIO_voidSetPortValue(DIO_PORT PORT,u8 data);
u8 DIO_u8GetPortValue(DIO_PORT PORT);
void DIO_voidTogglePortValue(DIO_PORT PORT);


#endif /* DIO_INTERFACE_H_ */