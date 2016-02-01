/*
 * DIO_proc.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#include "MyVars.h"
#include "Ahmed.Fanni_util.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"


extern void DIO_voidInit(void)
{
	DDRA=DIO_U8PORTADIR;
	DDRB=DIO_U8PORTBDIR;
	DDRB=DIO_U8PORTCDIR;
	DDRB=DIO_U8PORTDDIR;

	PORTA= PORTA | (DIO_U8PORTAVAL & DIO_U8PORTADIR);
	PORTB= PORTB | (DIO_U8PORTBVAL & DIO_U8PORTBDIR);
	PORTC= PORTC | (DIO_U8PORTCVAL & DIO_U8PORTCDIR);
	PORTD= PORTD | (DIO_U8PORTDVAL & DIO_U8PORTDDIR);
}

extern U8 DIO_U8ReadPinVal(U8 Copy_U8PinIdx, U8* Copy_U8PtrToVal)
{
	U8 Local_U8Flag= U8_NoError;
	if (Copy_U8PinIdx >=0 && Copy_U8PinIdx <= 7)
	{
		*Copy_U8PtrToVal=GetBit(PINA,Copy_U8PinIdx);
	}
	else if (Copy_U8PinIdx >= 8 && Copy_U8PinIdx <= 15)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-8;
		*Copy_U8PtrToVal=GetBit(PINB,Copy_U8PinIdx);
	}
	else if (Copy_U8PinIdx >= 16 && Copy_U8PinIdx <= 23)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-16;
		*Copy_U8PtrToVal=GetBit(PINC,Copy_U8PinIdx);
	}
	else if (Copy_U8PinIdx >= 24 && Copy_U8PinIdx <= 31)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-24;
		*Copy_U8PtrToVal=GetBit(PIND,Copy_U8PinIdx);
	}
	else
	{
		Local_U8Flag= U8_Error;
	}
	return Local_U8Flag;
}

extern U8 DIO_U8WritePinVal(U8 Copy_U8PinIdx, U8 Copy_U8PinVal)
{
	U8 Local_U8Flag= U8_NoError;
	if (Copy_U8PinIdx <= 7 && Copy_U8PinIdx >= 0 )
	{
		switch (Copy_U8PinVal)
		{
		case 1: SetBit(PORTA,Copy_U8PinIdx); break;
		case 0: ClrBit(PORTA,Copy_U8PinIdx); break;
		}
	}
	else if (Copy_U8PinIdx >= 8 && Copy_U8PinIdx <= 15)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-8;
		switch (Copy_U8PinVal)
		{
		case 1: SetBit(PORTB,Copy_U8PinIdx); break;
		case 0: ClrBit(PORTB,Copy_U8PinIdx); break;
		}
	}
	else if (Copy_U8PinIdx >= 16 && Copy_U8PinIdx <= 23)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-16;
		switch (Copy_U8PinVal)
		{
		case 1: SetBit(PORTC,Copy_U8PinIdx); break;
		case 0: ClrBit(PORTC,Copy_U8PinIdx); break;
		}
	}
	else if (Copy_U8PinIdx >= 24 && Copy_U8PinIdx <= 31)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-24;
		switch (Copy_U8PinVal)
		{
		case 1: SetBit(PORTD,Copy_U8PinIdx); break;
		case 0: ClrBit(PORTD,Copy_U8PinIdx); break;
		}
	}
	else
	{
		Local_U8Flag= U8_Error;
	}
	return Local_U8Flag;
}

extern U8 DIO_U8ReadPortVal(U8 Copy_U8PortIdx, U8* Copy_U8PtrToVal)
{
	U8 Local_U8Flag= U8_NoError;
	switch (Copy_U8PortIdx)
	{
	case DIO_U8PORT0: *Copy_U8PtrToVal = PINA;	break;

	case DIO_U8PORT1: *Copy_U8PtrToVal = PINB;	break;

	case DIO_U8PORT2: *Copy_U8PtrToVal = PINC;	break;

	case DIO_U8PORT3: *Copy_U8PtrToVal = PIND;	break;

	default: Local_U8Flag= U8_Error;

	}
return Local_U8Flag;
}

extern U8 DIO_U8WritePortVal(U8 Copy_U8PortIdx, U8 Copy_U8PortVal)
{
	U8 Local_U8Flag= U8_NoError;
	switch (Copy_U8PortIdx)
	{
	case DIO_U8PORT0: Assign(PORTA,Copy_U8PortVal);	break;

	case DIO_U8PORT1: Assign(PORTB,Copy_U8PortVal);	break;

	case DIO_U8PORT2: Assign(PORTC,Copy_U8PortVal);	break;

	case DIO_U8PORT3: Assign(PORTD,Copy_U8PortVal);	break;

	default: Local_U8Flag= U8_Error;

	}
return Local_U8Flag;

}

extern U8 DIO_U8WritePinDir(U8 Copy_U8PinIdx, U8 Copy_U8PinDir)
{
	U8 Local_U8Flag= U8_NoError;
	if (Copy_U8PinIdx <= 7 && Copy_U8PinIdx >=0)
	{
		switch (Copy_U8PinDir)
		{
		case 1: SetBit(DDRA,Copy_U8PinIdx); break;
		case 0: ClrBit(DDRA,Copy_U8PinIdx); break;
		}
	}
	else if (Copy_U8PinIdx >= 8 && Copy_U8PinIdx <= 15)
	{
		switch (Copy_U8PinDir)
		{
		Copy_U8PinIdx=Copy_U8PinIdx-8;
		case 1: SetBit(DDRB,Copy_U8PinIdx); break;
		case 0: ClrBit(DDRB,Copy_U8PinIdx); break;
		}
	}
	else if (Copy_U8PinIdx >= 16 && Copy_U8PinIdx <= 23)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-16;
		switch (Copy_U8PinDir)
		{
		case 1: SetBit(DDRC,Copy_U8PinIdx); break;
		case 0: ClrBit(DDRC,Copy_U8PinIdx); break;
		}
	}
	else if (Copy_U8PinIdx >= 24 && Copy_U8PinIdx <= 31)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-24;
		switch (Copy_U8PinDir)
		{
		case 1: SetBit(DDRD,Copy_U8PinIdx); break;
		case 0: ClrBit(DDRD,Copy_U8PinIdx); break;
		}
	}
	else
	{
		Local_U8Flag= U8_Error;
	}
	return Local_U8Flag;
}

extern U8 DIO_U8WritePortDir(U8 Copy_U8PortIdx, U8 Copy_U8PortDir)
{
	U8 Local_U8Flag= U8_NoError;
	switch (Copy_U8PortIdx)
	{
	case DIO_U8PORT0: Assign(DDRA,Copy_U8PortDir);	break;

	case DIO_U8PORT1: Assign(DDRB,Copy_U8PortDir);	break;

	case DIO_U8PORT2: Assign(DDRC,Copy_U8PortDir);	break;

	case DIO_U8PORT3: Assign(DDRD,Copy_U8PortDir);	break;

	default: Local_U8Flag= U8_Error;

	}
return Local_U8Flag;
}

extern U8 DIO_U8ReadPinDir(U8 Copy_U8PinIdx, U8* Copy_U8PtrToDir)
{
	U8 Local_U8Flag= U8_NoError;
	if (Copy_U8PinIdx <= 7 && Copy_U8PinIdx >=0)
	{
		*Copy_U8PtrToDir=GetBit(PINA,Copy_U8PinIdx);
	}
	else if (Copy_U8PinIdx >= 8 && Copy_U8PinIdx <= 15)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-8;
		*Copy_U8PtrToDir=GetBit(PINB,Copy_U8PinIdx);
	}
	else if (Copy_U8PinIdx >= 16 && Copy_U8PinIdx <= 23)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-16;
		*Copy_U8PtrToDir=GetBit(PINC,Copy_U8PinIdx);
	}
	else if (Copy_U8PinIdx >= 24 && Copy_U8PinIdx <= 31)
	{
		Copy_U8PinIdx=Copy_U8PinIdx-24;
		*Copy_U8PtrToDir=GetBit(PIND,Copy_U8PinIdx);
	}
	else
	{
		Local_U8Flag= U8_Error;
	}
	return Local_U8Flag;
}

extern U8 DIO_U8ReadPortDir(U8* Copy_U8PortIdx, U8* Copy_U8PtrToDir)
{
	U8 Local_U8Flag= U8_NoError;
	switch (Copy_U8PortIdx)
	{
	case DIO_U8PORT0	: *Copy_U8PtrToDir = PINA;	break;

	case DIO_U8PORT1	: *Copy_U8PtrToDir = PINB;	break;

	case DIO_U8PORT2	: *Copy_U8PtrToDir = PINC;	break;

	case DIO_U8PORT3	: *Copy_U8PtrToDir = PIND;	break;

	default: Local_U8Flag= U8_Error;

	}
return Local_U8Flag;
}
