/*
 * DIO_drives.h
 *
 * Created: 08/05/2023 10:59:37 ص
 *  Author: handsa
 */ 


#ifndef DIO_DRIVES_H_
#define DIO_DRIVES_H_
void dio_set_pin(char port,char pin,char dir);
void dio_write_pin(char port,char pin,char val); 
		void dio_toggle_pin(char port,char pin);
unsigned char dio_read_pin(unsigned char port,unsigned char pin); 
void dio_set_port(char port,char dir);
void dio_write_port(char port,char val);
void dio_toggle_port(char port);
unsigned char dio_read_port(unsigned char port);
void dio_pull_up_en (char port,char pin ,char en);

#endif /* DIO_DRIVES_H_ */