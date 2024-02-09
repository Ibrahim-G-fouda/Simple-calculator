/*
 * lcd_drives.c
 *
 * Created: 02/07/2023 10:23:01 م
 *  Author: handsa
 */ 
#include "DIO_drives.h"
#include "lcd.h"
#define dm _delay_ms
void lcd_init()
{
	#if defined eight_bits_mode
	dm(200);
dio_set_port(st1,255);
	dio_set_pin(st2,en,1);
		dio_set_pin(st2,rw,1);
			dio_set_pin(st2,rs,1);
			lcd_send_cmd(eight_bits);
			dm(1);
			lcd_send_cmd(cursor_on_disp_on);
			dm(1);
			lcd_send_cmd(return_home);
			dm(10);
			
			lcd_send_cmd(clr_screen);
			dm(10);
		//lcd_send_cmd(0x04);
lcd_send_cmd(entry_mode);
	dm(1);

#elif defined four_bits_mode
dio_set_pin(st1,0,1);
dio_set_pin(st1,1,1);
dio_set_pin(st1,2,1);
dio_set_pin(st1,3,1);
dio_set_pin(st2,en,1);
dio_set_pin(st2,rs,1);


lcd_send_cmd(return_home);

dm(10);
lcd_send_cmd(four_bits);
dm(1);

lcd_send_cmd(clr_screen);
dm(10);
lcd_send_cmd(entry_mode);
dm(1);
lcd_send_cmd(cursor_on_disp_on);
dm(1);


#endif
}
static void pulse(void)
{
	dio_write_pin(st2,en,1);
	dm(2);
		dio_write_pin(st2,en,0);
			dm(2);
}
void lcd_send_cmd(char data)
{
	#if defined eight_bits_mode
	
	dio_write_port(st1,data);
	dio_write_pin(st2,rs,0);
	pulse();
	dm(1);
#elif defined four_bits_mode
dio_write_lo_level(st1,data>>4);
dio_write_pin(st2,rs,0);
pulse();
dm(1);
dio_write_lo_level(st1,data);
pulse();
dm(1);
#endif
}
void lcd_send_char(char data)
{
		#if defined eight_bits_mode
	dio_write_port(st1,data);
	dio_write_pin(st2,rs,1);
	pulse();
	dm(1);
#elif defined four_bits_mode
dio_write_lo_level(st1,data>>4);
dio_write_pin(st2,rs,1);
pulse();
dm(1);
dio_write_lo_level(st1,data);
pulse();
dm(1);
#endif
}
void lcd_send_string(char * data)
{
	while (*data!='\0')
	{
	lcd_send_char(*data);
	data++;

	
	}
		dm(1);
		
}
void lcd_clrscrean(void)
{
	lcd_send_cmd(clr_screen);
	dm(10);
}
void lcd_move_cursor(char row,char coloumn)
{
	char data;
	if (row>2||row<1||coloumn<1||coloumn>16)
	{
	data =0x80;
	}
else if (row==1)
{
	data=0x80+coloumn-1;
}
else if (row==2)
{
	data=0xc0+coloumn-1;
}
lcd_send_cmd(data);
dm(1);
}
