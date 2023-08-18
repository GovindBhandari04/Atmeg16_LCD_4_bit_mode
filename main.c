/*
 * 4 Bit LCD mode.c
 *
 * Created: 8/18/2023 5:11:51 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h>

void lcd_data(unsigned char data)
{
	PORTD = (data & 0xf0);
	PORTC |= (1<<PC0);
	PORTC &= ~(1<<PC1);
	PORTC |= (1<<PC2);
	_delay_ms(2);
	PORTC &= ~(1<<PC2);
	
	PORTD = ((data<<4) & 0xf0);
	PORTC |= (1<<PC0);
	PORTC &= ~(1<<PC1);
	PORTC |= (1<<PC2);
	_delay_ms(2);
	PORTC &= ~(1<<PC2);
}

void lcd_command(unsigned char cmd)
{
	PORTD = (cmd & 0xf0);
	PORTC &= ~(1<<PC0);
	PORTC &= ~(1<<PC1);
	PORTC |= (1<<PC2);
	_delay_ms(2);
	PORTC &= ~(1<<PC2);
	
	PORTD = ((cmd<<4) & 0xf0);
	PORTC &= ~(1<<PC0);
	PORTC &= ~(1<<PC1);
	PORTC |= (1<<PC2);
	_delay_ms(2);
	PORTC &= ~(1<<PC2);
}

void lcd_string(const char *string,char length)
{
	for(int i=0;i<length;i++)
	{
		lcd_data(string[i]);
	}
}

void lcd_intialize()
{
	     lcd_command(0x02);
	     lcd_command(0x28);
         lcd_command(0x06);
         lcd_command(0x0C);
         lcd_command(0x01);
}
int main(void)
{
   DDRD |= (1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7);
   DDRC |= (1<<DDC0)|(1<<DDC1)|(1<<DDC2);
   
   lcd_intialize();
   
    while (1) 
    {
		lcd_command(0x85);
		lcd_string("GOVIND",6);
		lcd_command(0xC4);
		lcd_string("BHANDARI",8);
    }
}

