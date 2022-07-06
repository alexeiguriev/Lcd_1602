#include "Lcd1602.h"

#include <stdlib.h>
#include <util/delay.h>

void Lcd1602_Com(uint8_t p)
{
	LCD_MODE_PORT &= ~(1 << RS);
	LCD_MODE_PORT |= (1 << EN);
	LCD_DATA_PORT = p;
	_delay_us(100);
	LCD_MODE_PORT &= ~(1 << EN);
	_delay_us(100);
}

// Data Insetr
void Lcd1602_Data(uint8_t p)
{
	_delay_us(100);
	LCD_MODE_PORT |= (1 << RS)|(1 << EN);
	LCD_DATA_PORT = p;
	_delay_us(100);
	LCD_MODE_PORT &= ~(1 << EN);
	_delay_us(100);
	Lcd1602_Com(0x06);
}

//Initializarea LCD
void Lcd1602_Init(void)
{
	LCD_MODE_DDR |= (1 << PC2)|(1 << PC1)|(1 << PC0);
	LCD_MODE_PORT = 0x00;
	LCD_DATA_DDR = 0xFF;
	LCD_DATA_PORT = 0x00;
	_delay_ms(150);
	Lcd1602_Com(0x08);
	_delay_us(1000);
	Lcd1602_Com(0x38);
	_delay_us(100);
	Lcd1602_Com(0x38);
	_delay_us(100);
	Lcd1602_Com(0x38);
	_delay_us(100);
	Lcd1602_Com(0x01);
	_delay_us(100);
	Lcd1602_Com(0x06);
	_delay_ms(10);
	Lcd1602_Com(0x0C);
}

void Lcd1602_PrintString(const char lcd_str[]){
	for(int n = 0;lcd_str[n]!='\0';n++)
	{
		Lcd1602_Data(lcd_str[n]);
	}
}
void Lcd1602_SetPosition(uint8_t x, uint8_t y)
{
	char adress;
	adress=(0x40*y+x)|0b10000000;
	Lcd1602_Com(adress);
}

void Lcd1602_Clear(void)
{
	Lcd1602_Com(0x01);
	_delay_ms(3);
}
void Lcd1602_CursorHome(void)
{
	Lcd1602_Com(0x02);
	_delay_ms(3);
}

void Lcd1602_PrintIntVall(int vall)
{
	char buf[20];
	itoa(vall, buf, 10);
	Lcd1602_PrintString(buf);
	
}
