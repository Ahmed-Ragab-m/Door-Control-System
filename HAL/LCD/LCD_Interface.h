

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);
void LCD_voidWriteCharacter(u8 Character);
void LCD_voidWriteString(u8*str);
void LCD_voidWriteNumber(s16 num);
void LCD_voidClearDisplay(void);
void LCD_voidSetCursor(u8 line,u8 cell);
void LCD_voidCreateCustomunCharacter(u8*Pattern,u8 address);



#endif /* LCD_INTERFACE_H_ */