#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO/DIO_Interface.h"
#include "ADC/ADC_Interface.h"
#include "SPI/SPI_Interface.h"
#include "LCD/LCD_Interface.h"
#include "KEYPAD/KEYPAD_Interface.h"
#include "EXI/EXInterrupt_Interface.h"
#include "GIE/GIE_Interface.h"
#include "TIMER0/TIMER0_Interface.h"
#include "PWM/PWM_Interface.h"
#include "DC_MOTOR/DCMOTOR_Config.h"
#include "DC_MOTOR/DCMOTOR_Interface.h"
#include "WDT/WDT_Interface.h"
#include "SERVO/SERVO_Interface.h"

#define F_CPU 16000000
#include "util/delay.h"

//#include <avr/io.h>

u16 Password=123;

/*function to get password from user*/

u16 GET_Password(void)
{
	LCD_voidSetCursor(0,0);
	LCD_voidWriteString("Door Control System");
	LCD_voidSetCursor(1,0);
	LCD_voidWriteString("Enter Password:");
	u8 key;
	u16 enterd_pass=0,temp=0;
	while(1)
	{
		key=KEYPAD_u8GetPressedKey();
		if(key!='#')
		{
			if(key>='0'&&key<='9')
			{
				LCD_voidWriteCharacter('*');
				temp=(temp*10)+(key-'0');
			}
			if(key=='=')
			{
				enterd_pass=temp;
				break;
			}
		}
	}
	return enterd_pass;
	
}



int main(void)
{
	DIO_voidSetAllPinsDirections();
    LCD_voidInit();
	KEYPAD_voidInit();
	PWM_voidInitChanel1A();
	SERVO_voidStart(0);
	u16 enterd_pass=0;
	u8 flag=0;
	
    while (1) 
    {
		for(u8 i=0;i<3&&flag==0;i++)
		{
			enterd_pass=GET_Password();
			if(enterd_pass==Password)
			{
				LCD_voidClearDisplay();
				LCD_voidSetCursor(0,7);
				LCD_voidWriteString("Hello..");
				LCD_voidSetCursor(1,3);
				LCD_voidWriteString("DOOR IS OPEND");
				SERVO_voidStart(90);
				flag=1;
				
			}
			else 
			{
				if(i==2)
				{
					LCD_voidClearDisplay();
					LCD_voidSetCursor(0,3);
					LCD_voidWriteString("Restart System");
					DIO_voidSetPinValue(PINC0,HIGH);
					DIO_voidSetPinValue(PINC1,HIGH);
					flag=1;
					break;
				}
				else
				{
					LCD_voidClearDisplay();
					LCD_voidSetCursor(0,4);
					LCD_voidWriteString("Try Again...");
					_delay_ms(500);
				}
			}
		}
		
		
    }
	
}



