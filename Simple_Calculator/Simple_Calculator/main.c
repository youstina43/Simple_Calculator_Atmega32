/*
 * Simple_Calculator.c
 *
 * Created: 9/15/2023 6:05:09 PM
 * Author : youstina atef
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Confg.h"
#include "DIO_Private.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#include "KEY_Interface.h"
#include "KEY_Confg.h"
#include "KEY_Private.h"

#define F_CPU   16000000
#include <util/delay.h>

int main(void)
{
    DIO_init();
    LCD_init();
    KEY_VoidInit();
    
    LCD_GoTo(0,4);
    LCD_WriteString("WElCOME");
    LCD_GoTo(1,3);
    LCD_WriteString("CALCULATOR");
    _delay_ms(200);
    LCD_Clear();
  
    uint8 PressedKey,Operator='\0';
    f32 Num1=0,Num2=0;
    f32 Res;
    while(1)
    {      
	    PressedKey = Key_U8PressedKey();
		
	    if(PressedKey>='0' && PressedKey<='9')
	    {
		    if(Operator=='\0')
		    {   	   
		            LCD_Write_CHAR(PressedKey);
			    Num1 = Num1*10 + (PressedKey-'0');
		    }
		    else
		    {
				LCD_Write_CHAR(PressedKey);
			    Num2 = (Num2*10) + (PressedKey-'0');
		    }
	    }
	    else if(PressedKey=='+' || PressedKey=='-' || PressedKey=='*' ||PressedKey=='/' )
	    {   
		    LCD_Write_CHAR(PressedKey);
		    Operator = PressedKey;
	    }
	    else if(PressedKey=='=')
	    {    
		    LCD_Write_CHAR(PressedKey);
		    switch(Operator)
		    {
			    case '+':
			    Res = Num1 + Num2;
			    break;
			    case '-':
			    Res = Num1 - Num2;
			    break;
			    case '*':
			    Res = Num1 * Num2;
			    break;
			    case '/':
			    if(Num2!=0)
			    {
				    Res=Num1/Num2;
			    }
			    else
			    {
				    LCD_Clear();
				    LCD_WriteString("Division By Zero");
				    continue;
			    }
			    break;
			    default :
			    LCD_Clear();
			    LCD_WriteString("Invalid Operator !");
		    }
			
		    LCD_WriteNUM(Res);
		    Num1 = Res;
			 Num2 = 0;
		    Operator = '\0';

	    }
	    else if(PressedKey=='C')
	    {
		    LCD_Clear();
		    Num1 = 0;
			Num2 =0;
		    Operator='\0';
	    }
       
    }
    return 0;
}
		
		
 

