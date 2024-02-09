/*
 * app_type.c
 *
 * Created: 07/12/2023 07:35:11 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
  lcd_init();
//lcd_send_cmd(disp_on_cursor_off);
  keypad_init('c');
   unsigned char x;
   unsigned char flag=0;
    while(1)
    {
      x=keypad_read('c');
	  if ((x!=oo)&&(flag==0))
	  {
	 if (x=='A')
	 {
	 lcd_send_cmd(clr_screen);
	 }
	 else
	 {
		 lcd_send_char(x);
		 flag=1; 
	 }
	
	  }
	  else if((x==oo)&&(flag==1)) 
	  {
		  flag=0;
	  }
    
	}
}