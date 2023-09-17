/*
* LCD_prog.c
*
* Created: 9/15/2023 9:50:14 PM
*  Author: Youstina
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Confg.h"
#include "DIO_Private.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


void LCD_init(){
	_delay_ms(35);

	// set Rs pin = 0 (write command)
	DIO_setPinValue(LCD_CMD_PORT,RS_PIN,DIO_PIN_LOW);
	private_voidWriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
	LCD_Write_CMD(0b00101000);
	_delay_us(45);
	
	// Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_Write_CMD(0b00001111);
	_delay_us(45);
	
	// Clear Display
	//LCD_Write_CMD(0b00000001);
	_delay_ms(2);
	
	// Set Entry Mode
	LCD_Write_CMD(0b00000110);	
}

void LCD_Write_CMD(uint8 CMD){
	
	// set Rs pin = 0 (write command)
	DIO_setPinValue(LCD_CMD_PORT,RS_PIN,DIO_PIN_LOW);

	// Write The Most 4 bits Of command on Data Pins
	private_voidWriteHalfPort(CMD>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
	
	// Write The Least 4 bits Of command on Data Pins
	private_voidWriteHalfPort(CMD);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
}

void LCD_Write_CHAR(uint8 CHAR){
	
	// set Rs pin = 1 (write data)
	DIO_setPinValue(LCD_CMD_PORT,RS_PIN,DIO_PIN_HIGH);
	
	// Write The Most 4 bits Of data on Data Pins
	private_voidWriteHalfPort(CHAR>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
	
	// Write The Least 4 bits Of data on Data Pins
	private_voidWriteHalfPort(CHAR);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
}


void LCD_GoTo(uint8 ROW, uint8 COL)
{
	uint8 Address[2] = {LCD_Line1_1stAddress, LCD_Line2_1stAddress};
	LCD_Write_CMD(Address[ROW] + COL);
}


void LCD_Clear(void)
{
	LCD_Write_CMD(CMD_Clear_Display);
}

void LCD_WriteString(const uint8 * str){
	
	while( (*str) !='\0'){
		LCD_Write_CHAR(*str);
		str++;
		
	}	
}

void LCD_WriteNUM(s64 NUM){
	u64 Multiplier=1;
	
	if(NUM == 0){	LCD_Write_CHAR('0'); 	}
	
	else
	{
		if(NUM < 0) {	LCD_Write_CHAR('-');
		NUM *= -1;		 }
		
		if(NUM > 0){
			
			while( (s64)(NUM/Multiplier) != 0){	Multiplier*=10;	}

			do
			{
				Multiplier/=10;
				LCD_Write_CHAR( NUM/Multiplier +'0');
				NUM %=Multiplier;
			}
			while(Multiplier != 1 );
			
		}
	}
}

void LCD_WriteFLOAT(f64 num,uint8 Percision)
{
	u64 val,i;
	val = (u64) num;
	LCD_WriteNUM(val);
	LCD_Write_CHAR('.');
	num -= val;
	for (i = 0; i < Percision; i++)
	{
		num *=10;
		val = (int)num;
		LCD_Write_CHAR(val+'0');
		num -=val;
	}
}



static void private_voidWriteHalfPort(uint8 copy_u8Value)
{
	DIO_setPinValue(LCD_DATA_PORT,LCD_D4_Pin,GET_BIT(copy_u8Value,0));
	DIO_setPinValue(LCD_DATA_PORT,LCD_D5_Pin,GET_BIT(copy_u8Value,1));
	DIO_setPinValue(LCD_DATA_PORT,LCD_D6_Pin,GET_BIT(copy_u8Value,2));
	DIO_setPinValue(LCD_DATA_PORT,LCD_D7_Pin,GET_BIT(copy_u8Value,3));
}




