
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*DIO REGISTERS*/

#define DDRA   (*(volatile unsigned char*)0X3A)
#define PORTA  (*(volatile unsigned char*)0X3B)
#define PINA   (*(volatile unsigned char*)0X39)

#define DDRB   (*(volatile unsigned char*)0X37)
#define PORTB  (*(volatile unsigned char*)0X38)
#define PINB   (*(volatile unsigned char*)0X36)

#define DDRC   (*(volatile unsigned char*)0X34)
#define PORTC  (*(volatile unsigned char*)0X35)
#define PINC   (*(volatile unsigned char*)0X33)

#define DDRD   (*(volatile unsigned char*)0X31)
#define PORTD  (*(volatile unsigned char*)0X32)
#define PIND   (*(volatile unsigned char*)0X30)

extern PIN_STATUS PINS_Arr[TOTAL_PINS];



#endif /* DIO_PRIVATE_H_ */