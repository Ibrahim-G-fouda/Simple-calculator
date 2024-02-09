/*
 * calculator.c
 *
 * Created: 10/12/2023 05:01:34 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include <math.h>
#include "prog init.h"
int main(void)
{
lcd_init();
keypad_init('c');
 unsigned short first[16]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
int work_space[16]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
unsigned char mirror[16]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
 //unsigned char mul_index[8]={0};
 // unsigned char sum_index[8]={0};
  unsigned char str[11];
  unsigned char char_index[8]={0};//index of characters
int digits_mum[8]={0};//number of digits in every real number
	 // int real_num_count=0;//number of real numbers after concat
	  int num_count=0;//numbe of digits befor concat
	  int char_count=0;//number of operators
	 signed long result=0;
	  unsigned long last_res=0;
	 double res=0;
	  signed long right;
	   signed long left;
	 int sum;
	   unsigned char key_pad_recive=oo;//variable reciving from keybad
	   unsigned char a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i,j,k,m,n,o,p,offset;//general purpose counters
	  int l;// percentage
	  unsigned short big_count=0;
    while(1)
    {
  a=0;//
  b=0;//
  c=0;//
  d=0;//
  e=0;//
  f=0;//
  j=0;//
  h=0;
  i=0;
  g=0;
  k=0;//
  l=0;
  n=0;//
  o=0;
  p=0;
  offset=0;
 right=0;
 left=0;
 last_res=0;
num_count=0;//numbe of digits befor concat
 char_count=0;//number of operators
 result=0;
last_res=0;
 res=0;
  sum=0;
  for (a=0;a<16;a++)//a used
  {
key_pad_recive=ret_keypad();
dm(300);
if((key_pad_recive=='0')||(key_pad_recive=='1')||(key_pad_recive=='2')||(key_pad_recive=='3')||(key_pad_recive=='4')||(key_pad_recive=='5')||(key_pad_recive=='6')||(key_pad_recive=='7')||(key_pad_recive=='8')||(key_pad_recive=='9'))
{
first[a]=(key_pad_recive-48);
num_count++;

}
else if ((key_pad_recive=='+')||(key_pad_recive=='-')||(key_pad_recive=='*')||(key_pad_recive=='/')||(key_pad_recive=='=')&&((a!=0)&&(a!=15)))
{
/*****************************/
//while()
//{

//lcd_send_cmd(clr_screen);;
//tostring();;
//lcd_send_string(str);
//lcd_send_char(num_count+48);	
//for(;;);
//}

/*****************************/
first[a]=key_pad_recive;
char_count++;

digits_mum[b]=num_count;//b used
b++;
num_count=0;

//first[a]=key_pad_recive;
if ((key_pad_recive=='+')||(key_pad_recive=='-')||(key_pad_recive=='*')||(key_pad_recive=='/'))
{
char_index[d]=a; //d used
d++;	
}
if ((key_pad_recive=='='))
{
break;
}
}
else if((key_pad_recive=='+')||(key_pad_recive=='-')||(key_pad_recive=='*')||(key_pad_recive=='/')||(key_pad_recive=='=')&&((a==0)||(a==15)))
 {
	 lcd_send_cmd(clr_screen);
	 lcd_send_string("math error");
	 dm(3000);
	 break;

 }
 /**/



}//after big for

 /*****************************/
 //
 //m=0;
 //while(m<d)
//{

	 //lcd_send_cmd(clr_screen);;
	 //tostring();;
	 //lcd_send_string(str);
	//lcd_send_char(char_index[1]+48);
	// m++;
	
 //}
  //for(;;);
  /*****************************/ 
  big_count=b+char_count;
  /*****************************/
  //
  //m=0;
  //while(m<d)
  //{
//lcd_send_cmd(clr_screen);;
	  //tostring();;
	  //lcd_send_string(str);
	// lcd_send_char(big_count+48);
	  // m++;
	  
  //}
//for(;;);
  
  /*****************************/
   /************************************************************************/
   /*      concatination stage                                                                
   /***********************************************************************/
//lcd_send_cmd(clr_screen);
 for (e=0;e<b;e++)//e used
 {
 switch(digits_mum[e])
 {
	 
		 case 1:
		 l=1;
		 break;
		 case 2:
		 l=10;
		 break;
		 case 3:
		 l=100;
		 break;
		 case 4:
		 l=1000;
		 break;
		 case 5:
		 l=10000;
		 break;
		 case 6:
		 l=100000;
		 break;
		 default:
		 break;
	


 }
if (offset==0)
{
for (j=0;j<digits_mum[e];j++)//j used 
{


sum=sum+(first[offset+j]*l);
l=l/10;



}
}
else
{
	sum=0;//the bigest pain!!
	for (j=1;j<=digits_mum[e];j++)
	{
	
	sum=sum+(first[offset+j]*l);
	l=l/10;

	}	


//lcd_send_char(offset+48);
//lcd_send_char('D');
}
 
  //lcd_send_char((sum/100)+48);
//lcd_send_char((sum/10)%10+48);
//lcd_send_char((sum%10)+48);

 //lcd_send_char(offset+48);
 // lcd_send_char('D');
 offset=offset+j;
 work_space[h]=sum;
 mirror[h]=1;//h used
 h++;
 work_space[h]=first[offset];
 mirror[h]=first[offset];
 h++;
} 
 /*****************************/
 //
// m=0;
 // lcd_send_cmd(clr_screen);;
// while(m<big_count)
//{
	
	// tostring(str,work_space[m]);;
	//lcd_send_string(str);
	// lcd_send_char((work_space[m]/100)+48);
	//lcd_send_char((work_space[m]/10)%10+48);
	//lcd_send_char((work_space[m]%10)+48);

	//lcd_send_char(offset+48);
	// lcd_send_char('D');
	//m=m+2;
	 
//}
 //for(;;);
 
 /*****************************/

/************************************************************************/
/* last stage                                                                      */
/************************************************************************/
 for(g=0;g<big_count-1;g++)//g used
 {
	 if ((mirror[g]=='/')||(mirror[g]=='*'))
	 {
	if ((mirror[g]=='*'))
	{
	k=g;//k used
	while(k<=big_count)
	{
		k++;
		if (mirror[k]==1);
		{
		right=work_space[k];
		work_space[k]='0';
		mirror[k]='0';
		break;
		}
	}
	k=g;
	while(k>=0)
	{
		k--;
		if (mirror[k]==1);
		{
			left=work_space[k];
			work_space[k]='0';
			mirror[k]='0';
			break;
		}
		
	}
result=left*right;
work_space[g]=result;

	
	}
	else if ((mirror[g]=='/'))
	{
	k=g;//k used
	while(k<=big_count)
	{
		k++;
		if (mirror[k]==1);
		{
			right=work_space[k];
			work_space[k]='0';
			mirror[k]='0';
			break;
		}
	}
	k=g;
	while(k>=0)
	{
		k--;
		if (mirror[k]==1);
		{
			left=work_space[k];
			work_space[k]='0';
			mirror[k]='0';
			break;
		}
		
	}
	res=(double)left/right;
	work_space[g]=res;

	
	}
	
	 }

 }// big for
 /************************************************************************/
 /* sum for                                                                     */
 /************************************************************************/
  for(g=0;g<big_count;g++)//g used
  {
	  if ((mirror[g]=='-')||(mirror[g]=='+'))
	  {
		  if ((mirror[g]=='+'))
		  {
			  k=g;//k used
			  while(k<=big_count)
			  {
				  k++;
				  if (mirror[k]==1);
				  {
					  right=work_space[k];
					  work_space[k]='0';
					  mirror[k]='0';
					  break;
				  }
			  }
			  k=g;
			  while(k>=0)
			  {
				  k--;
				  if (mirror[k]==1);
				  {
					  left=work_space[k];
					  work_space[k]='0';
					  mirror[k]='0';
					  break;
				  }
				  
			  }
			  result=left+right;
			  work_space[g]=result;

			  
		  }
		  else if ((mirror[g]=='-'))
		  {
			  k=g;//k used
			  while(k<=big_count)
			  {
				  k++;
				  if (mirror[k]==1);
				  {
					  right=work_space[k];
					  work_space[k]='0';
					  mirror[k]='0';
					  break;
				  }
			  }
			  k=g;
			  while(k>=0)
			  {
				  k--;
				  if (mirror[k]==1);
				  {
					  left=work_space[k];
					  work_space[k]='0';
					  mirror[k]='0';
					  break;
				  }
				  
			  }
			  result=left-right;
			  work_space[g]=result;

			  
		  }
		  
	  }

  }// last sum for
 while (work_space[n]=='0')
  {
n++;
  } 

tostring(str,work_space[n]);
 lcd_send_cmd(clr_screen);
 lcd_send_string(str);
dm(5000);

  }
    }
  

