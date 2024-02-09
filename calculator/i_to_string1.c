/*
 * int_to_string1.c
 *
 * Created: 12/07/2023 12:05:43 م
 *  Author: handsa
 */ 
void tostring(char str[],int c) // char str[] is pointer to char
{
	int i,rem,len=0;
	int n;
	n=c;
	if (n!=0)
	{
	while(n!=0)
	{
		len++;
		n/=10;
	}
	
	for(i=0;i<len;i++)
	{
		rem=c%10;
		c=c/10;
		str[len-(i+1)]=rem+'0';//add ascii code of '0'(48)to every digit to get its ascii code
	}
	
	str[len]='\0';
	}
	else
	{
	str[0]='0';
	str[1]='\0'	;
	}

}