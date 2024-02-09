/*
 * keyPad_drives.h
 *
 * Created: 10/07/2023 07:42:08 م
 *  Author: handsa
 */ 


#ifndef KEYPAD_DRIVES_H_
#define KEYPAD_DRIVES_H_
void keypad_init(unsigned char port);
unsigned char keypad_read(unsigned char port);
#define oo 0xff




#endif /* KEYPAD_DRIVES_H_ */