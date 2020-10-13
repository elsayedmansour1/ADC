#ifndef _DIO_INT_H
#define _DIO_INT_H


void DIO_VidSetPinDirection	(u8 LOC_u8Port,u8 LOC_u8PinNumber,u8 LOC_u8State);
/*comment*/
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_VidSetPinDirection.								**/
/**	Return Type	: void.					   		   		**/
/**	Arguments		: Port and Pin number and Direction(Input or output).	**/
/**	Functionality	: Setting the direction of specific pin at run time.    **/
/*****************************************************************************/
/*****************************************************************************/
void DIO_VidSetPinValue	(u8 LOC_u8Port,u8 LOC_u8PinNumber,u8 LOC_u8Value);
/*comment*/
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_VidSetPinValue.									**/
/**	Return Type	: void.					   		   		**/
/**	Arguments		: Port and Pin number and Value(High or Low).			**/
/**	Functionality	: Setting the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
void DIO_VidSetPortDirection	(u8 LOC_u8Port,u8 LOC_u8Value);
/*comment*/
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_VidSetPortDirection.								**/
/**	Return Type	: void.					   		   		**/
/**	Arguments		: Port and Direction(Input or output)).									**/
/**	Functionality	:Setting the direction of specific port at run time.    **/
/*****************************************************************************/
/*****************************************************************************/
void DIO_VidSetPortValue	(u8 LOC_u8Port,u8 LOC_u8Value);
/*comment*/
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_VidSetPortValue.								**/
/**	Return Type	: void.					   		   		**/
/**	Arguments		: Port and Pin number and Value(High or Low).											**/
/**	Functionality	: Setting the Value of specific port at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
u8 DIO_u8GetPinValue	(u8 LOC_u8Port,u8 LOC_u8Pin);
/*comment*/
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_u8GetPinValue.								**/
/**	Return Type	: u8.					   		   		**/
/**	Arguments		: Port and Pin number.											**/
/**	Functionality	: Get the Value of specific pin at run time	    **/
/*****************************************************************************/
/*****************************************************************************/
void DIO_u8TogglePinValue   	(u8 LOC_u8Port,u8 LOC_u8Pin);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuTogglePinValue.								**/
/**	Return Type	: void.					   		   		**/
/**	Arguments		: Port and Pin number.									**/
/**	Functionality	: Toggling the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/















#endif