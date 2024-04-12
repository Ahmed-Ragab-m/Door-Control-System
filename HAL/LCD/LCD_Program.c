#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

#define F_CPU 16000000
#include "util/delay.h"


void LCD_WriteCommand(u8 Command)
{
	#if LCD_MODE == LCD_4BIT_MODE
	DIO_voidSetPinValue(RS,LOW);
	DIO_voidSetPinValue(D7,GET_BIT(Command,7));
	DIO_voidSetPinValue(D6,GET_BIT(Command,6));
	DIO_voidSetPinValue(D5,GET_BIT(Command,5));
	DIO_voidSetPinValue(D4,GET_BIT(Command,4));
	DIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(D7,GET_BIT(Command,3));
	DIO_voidSetPinValue(D6,GET_BIT(Command,2));
	DIO_voidSetPinValue(D5,GET_BIT(Command,1));
	DIO_voidSetPinValue(D4,GET_BIT(Command,0));
	DIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	#elif LCD_MODE==LCD_8BIT_MODE
	DIO_voidSetPinValue(RS,LOW);
	DIO_voidSetPortValue(LCD_PORT,Command);
	DIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	#endif
}

void LCD_WriteCHAR(u8 Charcter)
{
	#if LCD_MODE==LCD_4BIT_MODE
	DIO_voidSetPinValue(RS,HIGH);
	DIO_voidSetPinValue(D7,GET_BIT(Charcter,7));
	DIO_voidSetPinValue(D6,GET_BIT(Charcter,6));
	DIO_voidSetPinValue(D5,GET_BIT(Charcter,5));
	DIO_voidSetPinValue(D4,GET_BIT(Charcter,4));
	DIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(D7,GET_BIT(Charcter,3));
	DIO_voidSetPinValue(D6,GET_BIT(Charcter,2));
	DIO_voidSetPinValue(D5,GET_BIT(Charcter,1));
	DIO_voidSetPinValue(D4,GET_BIT(Charcter,0));
	DIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	#elif LCD_MODE==LCD_4BIT_MODE
	DIO_voidSetPinValue(RS,HIGH);
	DIO_voidSetPinValue(LCD_PORT,Character);
	DIO_voidSetPinValue(EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,LOW);
	_delay_ms(1);
	#endif
}

void LCD_voidInit(void)
{
	#if LCD_MODE==LCD_4BIT_MODE
	_delay_ms(50);
	LCD_WriteCommand(LCD_CMD_RETURN_HOME);
	LCD_WriteCommand(LCD_CMD_FUNCTION_4BIT_2LINES);
	LCD_WriteCommand(LCD_CMD_DISP_ON_CURSOR_OFF);
	LCD_WriteCommand(LCD_CMD_CLEAR_SCREEN);
	_delay_ms(1);
	LCD_WriteCommand(LCD_CMD_ENTRY_MODE);
	#elif LCD_MODE==LCD_8BIT_MODE
	_delay_ms(50);
	LCD_WriteCommand(LCD_CMD_FUNCTION_8BIT_2LINES);
	LCD_WriteCommand(LCD_CMD_DISP_ON_CURSOR_OFF);
	LCD_WriteCommand(LCD_CMD_CLEAR_SCREEN);
	_delay_ms(1);
	LCD_WriteCommand(LCD_CMD_ENTRY_MODE);
	#endif
}


void LCD_voidWriteCharacter(u8 Character)
{
	LCD_WriteCHAR(Character);
}


void LCD_voidWriteString(u8*str)
{
	int i;
	for(i=0;str[i];i++)
	{
		LCD_voidWriteCharacter(str[i]);
	}
}

void LCD_voidWriteNumber(s16 num)
{
	u8 str[16];
	u16 i;
	s16 j;
	if(num==0)
	{
		LCD_voidWriteCharacter('0');
		return;
	}
	if(num<0)
	{
		LCD_voidWriteCharacter('-');
		num=num*-1;
	}
	for(i=0;num>0;i++)
	{
		str[i]=num%10+'0';
		num=num/10;
	}
	str[i]=0;
	for(j=i-1;j>=0;j--)
	{
		LCD_voidWriteCharacter(str[j]);
	}

}

void LCD_voidClearDisplay(void)
{
	LCD_WriteCommand(LCD_CMD_CLEAR_SCREEN);
	_delay_ms(1);
}

void LCD_voidSetCursor(u8 line,u8 cell)
{
	// line 0-1  cell 0-15
	if(line==0)
	{
		LCD_WriteCommand(LCD_CMD_BEGIN_AT_FIRST_ROW+cell);
	}
	else if(line==1)
	{
		LCD_WriteCommand(LCD_CMD_BEGIN_AT_FIRST_ROW+(0x40+cell));
	}
	
}


void LCD_voidCreateCustomunCharacter(u8*Pattern,u8 address)
{
	LCD_WriteCommand(0x40+address*8);
	for(u8 i=0;i<8;i++)
	{
		LCD_WriteCHAR(Pattern[i]);
	}
	LCD_WriteCommand(LCD_CMD_BEGIN_AT_FIRST_ROW);
	
}
