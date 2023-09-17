/*
 * LCD_config.h
 *
 * Created: 9/15/2023 9:49:33 PM
 *  Author: youstina atef
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "DIO_Interface.h"


 #define LCD_CMD_PORT   DIO_PORTA
 
 #define RS_PIN         DIO_PIN3
 #define RW_PIN         DIO_PIN1
 #define E_PIN          DIO_PIN2
 
 #define LCD_DATA_PORT  DIO_PORTB
 #define LCD_D4_Pin         DIO_PIN0
 #define LCD_D5_Pin         DIO_PIN1
 #define LCD_D6_Pin         DIO_PIN2
 #define LCD_D7_Pin         DIO_PIN4

#endif /* LCD_CONFIG_H_ */