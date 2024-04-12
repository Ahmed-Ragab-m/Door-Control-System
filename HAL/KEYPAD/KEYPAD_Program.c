#include "STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#include "KEYPAD_Interface.h"


#define F_CPU 16000000
#include "util/delay.h"


void KEYPAD_voidInit(void)
{
	DIO_voidSetPinValue(ROW0,HIGH);
	DIO_voidSetPinValue(ROW1,HIGH);
	DIO_voidSetPinValue(ROW2,HIGH);
	DIO_voidSetPinValue(ROW3,HIGH);
}


u8 KEYPAD_u8GetPressedKey(void)
{
	u8 PressedKey = NO_PRESSED_KEY;
	u8 RowIndex,ColumnIndex;
	u8 PinValue;
	u8 Array[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = KPD_ARRAY;
	u8 RowsArray[NUMBER_OF_ROWS] = {ROW0,ROW1,ROW2,ROW3};
	u8 ColumnsArray[NUMBER_OF_COLUMNS] = {COL0,COL1,COL2,COL3};

	for (RowIndex=0; RowIndex < NUMBER_OF_ROWS; RowIndex++)
	{
		
		DIO_voidSetPinValue(RowsArray[RowIndex], LOW);
		

		for (ColumnIndex=0; ColumnIndex<NUMBER_OF_COLUMNS; ColumnIndex++)
		{
			PinValue=DIO_voidGetPinValue(ColumnsArray[ColumnIndex]);
			if (PinValue==0)
			{
				
				while(PinValue==0)
				{
					PinValue=DIO_voidGetPinValue(ColumnsArray[ColumnIndex]);
				}
				PressedKey= Array[RowIndex][ColumnIndex];
				return PressedKey;
			}
			
		}
		
		DIO_voidSetPinValue(RowsArray[RowIndex], HIGH);
	}
	return PressedKey;
}
