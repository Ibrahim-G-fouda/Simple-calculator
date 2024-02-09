/*
 * std_macros1.h
 *
 * Created: 13/06/2023 10:53:06 م
 *  Author: handsa
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define Reg_siz 8
#define set_bit(reg,bit) reg|=(1<<bit)
#define clr_bit(reg,bit) reg&=(~(1<<bit))
#define tog_bit(reg,bit) reg^=(1<<bit)
#define read_bit(reg,bit) ((reg &(1<<bit))>>bit)
#define is_bit_set(reg,bit)  ((reg &(1<<bit))>>bit)
#define is_bit_clr(reg,bit)  !((reg &(1<<bit))>>bit)
#define ror(reg,num) reg=(reg<<(Reg_siz -num))|(reg>>(num))
#define rol(reg,num) reg=(reg>>(Reg_siz -num))|(reg<<(num))

#endif /* STD_MACROS1_H_ */