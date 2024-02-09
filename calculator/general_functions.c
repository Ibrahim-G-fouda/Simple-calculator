/*
 * general_functions.c
 *
 * Created: 10/12/2023 05:55:47 م
 *  Author: handsa
 */ 
#include "prog init.h"
#include <math.h>
unsigned char flag=0;//flag for keypad latch
char ret_keypad(void)
{
unsigned  char x=oo;
do 
{

x=keypad_read('c');

/************************************************************************/
/*            if ((x!=oo)&&(flag==0))
{
	
	lcd_send_char(x);
	flag=1;
	
}
else if((x==oo)&&(flag==1))
{
	flag=0;
}                                                          */
/************************************************************************/
	
} while (x==oo);
lcd_send_char(x);
return x;
}