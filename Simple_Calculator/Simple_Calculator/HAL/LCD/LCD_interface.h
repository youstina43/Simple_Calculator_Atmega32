/*
* LCD_interface.h
*
* Created: 9/15/2023 9:49:53 PM
*  Author: youstina atef
*/


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "DIO_Interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#define F_CPU 16000000
#include "util/delay.h"


void LCD_init();
void LCD_Write_CMD(uint8 CMD);
void LCD_Write_CHAR(uint8 CHAR);
void LCD_WriteString(const uint8 * str);

void LCD_WriteNUM(s64 NUM);
void LCD_WriteFLOAT(f64 num,uint8 Percision);
 void LCD_Clear(void);

void LCD_GoTo(uint8 ROW, uint8 COL);

#endif /* LCD_INTERFACE_H_ */