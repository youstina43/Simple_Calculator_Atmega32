/*
 * DIO_Privateh.h
 *
 * Created: 9/13/2023 11:51:48 PM
 *  Author: Youstina Atef
 */ 


#ifndef DIO_PRIVATEH_H_
#define DIO_PRIVATEH_H_

 /* DIO REGISTERS*/
 
 /* DATA DIRCTION REGISTERS */
 #define DDRA           (*(volatile uint8*)0x3A)
 #define DDRB           (*(volatile uint8*)0x37)
 #define DDRC           (*(volatile uint8*)0x34)
 #define DDRD           (*(volatile uint8*)0x31)

 /* OUTPUT REGISTERS */
 #define PORTA          (*(volatile uint8*)0x3B)
 #define PORTB          (*(volatile uint8*)0x38)
 #define PORTC          (*(volatile uint8*)0x35)
 #define PORTD          (*(volatile uint8*)0x32)

 /* INPUT REGISTERS */
 #define PINA           (*(volatile uint8*)0x39)
 #define PINB           (*(volatile uint8*)0x36)
 #define PINC           (*(volatile uint8*)0x33)
 #define PIND           (*(volatile uint8*)0x30)


 /* Macros For Pins Initial Directions */

 #define DIO_INITIAL_INPUT               0
 #define DIO_INITIAL_OUTPUT              1

 /* Macros For Pins Initial Values */

 #define DIO_INITIAL_INPUT_FLOATING      0
 #define DIO_INITIAL_INPUT_PULLUP        1
 #define DIO_INITIAL_OUTPUT_LOW          0
 #define DIO_INITIAL_OUTPUT_HIGH	     1
 
 /* Macros For Concatenation Functions */

 #define CONC(b7,b6,b5,b4,b3,b2,b1,b0)        CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
 #define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* DIO_PRIVATEH_H_ */