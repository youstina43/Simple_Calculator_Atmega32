/*
 * DIO_Interface.h
 *
 * Created: 9/13/2023 11:52:18 PM
 *  Author: Youstina Atef
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_CONFG.h"
#include "DIO_Private.h"

/*************** MACROS FOR PIN ***************/
/* Macros For Pin Id */
#define DIO_PIN0           0
#define DIO_PIN1           1
#define DIO_PIN2           2
#define DIO_PIN3           3
#define DIO_PIN4           4
#define DIO_PIN5           5
#define DIO_PIN6           6
#define DIO_PIN7           7

/* Macros For Pin Direction */
#define DIO_PIN_INPUT      0
#define DIO_PIN_OUTPUT     1

/* Macros For Pin state */
#define DIO_PIN_LOW        0
#define DIO_PIN_HIGH       1


/*************** MACROS FOR PORT ***************/

/* Macros For Port Id */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

/* Macros For Port Direction */
#define DIO_PORT_INPUT      0x00
#define DIO_PORT_OUTPUT     0xff

/* Macros For Port state */
#define DIO_PORT_LOW        0x00
#define DIO_PORT_HIGH       0xff


/*************** APIS PROTO TYPES ***************/

void DIO_init(void);

/* Pin Apis */
void DIO_setPinDirection            (uint8 PortId, uint8 PinId, uint8 PinDirection);
void DIO_setPinValue                (uint8 PortId, uint8 PinId, uint8 PinValue);
void DIO_getPinValue                (uint8 PortId, uint8 PinId, uint8* PinValue);
void DIO_togglePinValue             (uint8 PortId, uint8 PinId);
void DIO_activePinInPullUpResistance(uint8 PortId, uint8 PinId);

/* Port Apis */
void DIO_setPortDirection            (uint8 PortId, uint8 PortDirection);
void DIO_setPortValue                (uint8 PortId, uint8 PortValue);
void DIO_getPortValue                (uint8 PortId, uint8* PortValue);
void DIO_togglePortValue             (uint8 PortId);
void DIO_activePortInPullUpResistance(uint8 PortId);




#endif /* DIO_INTERFACE_H_ */