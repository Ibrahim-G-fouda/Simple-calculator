/*
 * kypad_drives.c
 *
 * Created: 10/07/2023 07:41:38 م
 *  Author: handsa
 */ 
#define  F_CPU  8000000Ul

#include <util/delay.h>

#include "keyPad_drives.h"


void keypad_init(unsigned char port)
{
	dio_set_pin(port,0,1);
	dio_set_pin(port,1,1);
    dio_set_pin(port,2,1);
    dio_set_pin(port,3,1);
    dio_pull_up_en(port,4,1);
    dio_pull_up_en(port,5,1);
     dio_pull_up_en(port,6,1);
	  dio_pull_up_en(port,7,1);

}
unsigned char keypad_read(unsigned char port)
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	unsigned char raw ,col,x;
volatile		unsigned char ret=0xff;
		
		for (raw=0;raw<=3;raw++)
		{
		dio_write_pin(port,0,1);
		dio_write_pin(port,1,1);
		dio_write_pin(port,2,1);
		dio_write_pin(port,3,1);
		dio_write_pin(port,raw,0);
		
		for(col=0;col<=3;col++)
		{
	
			x=dio_read_pin(port,col+4);
			
			if ((x==0))
			{
			ret=arr[raw][col];
		
			break;
			}
		
		
		}
		if (x==0)
		{
		
			break;
		}
		

		}


return ret;

}

