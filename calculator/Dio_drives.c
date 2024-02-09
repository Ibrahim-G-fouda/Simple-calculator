/*
 * Dio_drives.c
 *
 * Created: 08/05/2023 10:58:42 ص
 *  Author: handsa
 */ 
#include <avr/io.h>
#define  F_CPU  8000000Ul
void dio_set_pin(char port,char pin,char dir)
{
	switch (port)
	{
		case 'A':
			case 'a':
			if (dir ==1)
			{
			DDRA|=(1<<pin);
			}
	else
	{
	DDRA&=(~(1<<pin));	
	}break;
	
	case 'B':
	case 'b':
	if (dir ==1)
	{
		DDRB|=(1<<pin);
	}
	else
	{
		DDRB&=(~(1<<pin));
	}break;

case 'C':
case 'c':
if (dir ==1)
{
	DDRC|=(1<<pin);
}
else
{
	DDRC&=(~(1<<pin));
}break;
	
	case 'D':
	case 'd':
	if (dir ==1)
	{
		DDRD|=(1<<pin);
	}
	else
	{
		DDRD&=(~(1<<pin));
	}break;
	
	default:
	break;
}
	}
	void dio_write_pin(char port,char pin,char val)
	{
		switch(port)
	{
		case  'A':
		case 'a':
		if (val==1)
		{
		PORTA=PORTA|(1<<pin);
		}
	else
	{
		PORTA=PORTA & (~(1<<pin));
	}break;
	case  'B':
	case 'b':
	if (val==1)
	{
		PORTB=PORTB|(1<<pin);
	}
	else
	{
		PORTB=PORTB & (~(1<<pin));
	}break;
	case 'C':
	case 'c':
	if (val==1)
	{
		PORTC =PORTC |(1<<pin);
	}
	else
	{
		PORTC =PORTC  & (~(1<<pin));
	}break;
	case 'D':
	case 'd':
	if (val==1)
	{
		PORTD =PORTD |(1<<pin);
	}
	else
	{
		PORTD =PORTD  & (~(1<<pin));
	}break;
	
	default:
	break;
	}	
	}
		unsigned char dio_read_pin(	unsigned char port,	unsigned char pin)
		{
		unsigned char val ;
		switch(port)
		{
		case 'A':
		case 'a':	
		val =((PINA>>pin)&1);
		break;
		case  'B':
		case 'b':
		val =((PINB>>pin)&1);
			break;;
		case  'C':
		case 'c':
		val =((PINC>>pin)&1);
			break;
			case  'D':
			case 'd':
			val =((PIND>>pin)&1);
			break;
			default:
			break;
		
		}
		return val;
				}		
				void dio_toggle_pin(char port,char pin)
				{
					switch (port)
					{
					case 'A':
					case 'a':
					PORTA=PORTA^(1<<pin);
					break;
					case 'b':
					case 'B':
					PORTB=PORTB^(1<<pin);
					break;
					case 'C':
					case 'c':
					PORTC=PORTC^(1<<pin);
					break;
					case  'D':
					case 'd':
					PORTD=PORTD^(1<<pin);
					break;
					default:
					break;
					}
			}
			void dio_set_port(unsigned char port,unsigned char dir)
			{
				switch(port)
				{
				case 'A':
				case 'a':
					DDRA=dir;
	break;
	case 'b':
	case 'B':
	DDRB=dir;
	break;
	case 'C':
	case 'c':
	DDRC=dir;
	break;
	case  'D':
	case 'd':
	DDRD=dir;
	break;
	default:
	break;
	
	}
}
void dio_write_port(char port,unsigned char val)
{
	switch(port)
	{
	case 'A':
	case 'a':
	PORTA=val;	
	break;
	case 'B':
	case 'b':
	PORTB=val;
	break;
	case 'C':
	case 'c':
	PORTC=val;
	break;
	case 'D':
	case 'd':
	PORTD=val;
	break;
	default:
	break;
	
	}
}
unsigned char dio_read_port(unsigned char port)
{
	unsigned char val;
	switch (port)
	{
	case 'a' :
	case 'A' :
	val=PINA;
	break;
	case 'B' :
	case 'b' :
	val=PINB;
	break;
	case 'C' :
	case 'c' :
	val=PINC;
	break;
	case 'D' :
	case 'd' :
	val=PIND;
	break;
	default:
	break;
	
	}
	
}
void dio_toggle_port(char port)
{
		unsigned char val;
		switch (port)
		{
			case 'a' :
			case 'A' :
			PORTA=~PORTA;
			break;
			case 'B' :
			case 'b' :
				PORTB=~PORTB;
			break;
			case 'C' :
			case 'c' :
				PORTC=~PORTC;
			break;
			case 'D' :
			case 'd' :
		PORTD=~PORTD;
			break;
			default:
			break;
			
		}
}
void dio_pull_up_en (char port,char pin ,char en)
{
	
	switch(port)
{
	case 'a':
	case 'A':
if (en==1)
{
PORTA=PORTA|(1<<pin);
DDRA=DDRA&(~(1<<pin));
}
else
{
	PORTA=PORTA&(~(1<<pin));
}break;
case 'b':
case 'B':
if (en==1)
{
	PORTB=PORTB|(1<<pin);
	DDRB=DDRB&(~(1<<pin));
}
else
{
	PORTB=PORTB&(~(1<<pin));
}break;
case 'c':
case 'C':
if (en==1)
{
	PORTC=PORTC|(1<<pin);
	DDRC=DDRC&(~(1<<pin));
}
else
{
	PORTC=PORTC&(~(1<<pin));
}break;
case 'd':
case 'D':
if (en==1)
{
	PORTD=PORTD|(1<<pin);
	DDRD=DDRD&(~(1<<pin));
}
else
{
	PORTD=PORTD&(~(1<<pin));
}break;
default:
break;
}
}
void dio_write_lo_level(char port,unsigned char val)
{
	val=val & 0x0f;
	switch(port)
	{
		case 'a':
		case 'A':
		PORTA=PORTA& 0xf0;
		PORTA=PORTA|val;
		break;
		case 'b':
		case 'B':
		PORTB=PORTB& 0xf0;
		PORTB=PORTB|val;
		break;
		case 'c':
		case 'C':
		PORTC=PORTC& 0xf0;
		PORTC=PORTC|val;
		break;
		case 'd':
		case 'D':
		PORTD=PORTD& 0xf0;
		PORTD=PORTD|val;
		break;
		default:
		break;
	}


}
void dio_write_hi_level(char port,unsigned char val)
{
	val =val <<4;
	val=val & 0xf0;
	switch(port)
	{
		case 'a':
		case 'A':
		PORTA=PORTA& 0x0f;
		PORTA=PORTA|val;
		break;
		case 'b':
		case 'B':
		PORTB=PORTB& 0x0f;
		PORTB=PORTB|val;
		break;
		case 'c':
		case 'C':
		PORTC=PORTC& 0x0f;
		PORTC=PORTC|val;
		break;
		case 'd':
		case 'D':
		PORTD=PORTD& 0x0f;
		PORTD=PORTD|val;
		break;
		default:
		break;
	}


}