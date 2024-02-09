/*
 * lcd.h
 *
 * Created: 02/07/2023 10:23:42 م
 *  Author: handsa
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#define  F_CPU  8000000Ul

#include <util/delay.h>

#include "DIO_drives.h"
#include "lcd_config.h"
#define clr_screen 0x01
#define cursor_on_disp_on 0x0e
#define return_home 0x02
#define entry_mode 0x06
#define left_right_write 0x04
#define disp_on_cursor_off 0x0c
#define sh_l_disp_on_w 0x07
#define cursor_blink 0x0f
#define  cursor_off_disp_off 0x08
#define cursor_sh_l 0x10
#define cursor_sh_r 0x14
#define disp_lift_sh 0x18
#define disp_righr_sh 0x1c
#if defined  four_bits_mode

	#define en 0
	#define rs 1
	#define rw 2
	#define four_bits 0x28
	

#elif defined  eight_bits_mode

	#define en 0
	#define rs 1
	#define rw 2
	#define eight_bits 0x38

#endif
void lcd_init(void);
 static void pulse(void);
void lcd_send_cmd(char data);
void lcd_send_char(char data);
void lcd_send_string(char * data);
void lcd_clrscrean(void);
void lcd_move_cursor(char row,char colo);
#endif /* LCD_H_ */