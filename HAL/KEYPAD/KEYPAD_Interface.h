
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KPD_ROWS_PORT 	PORTC

#define ROW0 	PINC5
#define ROW1	PINC4
#define ROW2	PINC3
#define ROW3	PINC2

#define KPD_COLS_PORT 	PORTD

#define COL0 	PIND7
#define COL1	PIND6
#define COL2	PIND4
#define COL3	PIND3

#define KPD_ARRAY  {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}}

#define NO_PRESSED_KEY 	'#'

#define NUMBER_OF_ROWS			4
#define NUMBER_OF_COLUMNS		4

void KEYPAD_voidInit(void);
u8 KEYPAD_u8GetPressedKey(void);




#endif /* KEYPAD_INTERFACE_H_ */