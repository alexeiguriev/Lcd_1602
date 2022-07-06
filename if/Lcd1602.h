/*
 * LCD1602.h
 *
 * Created: 7/6/2022 4:34:55 PM
 *  Author: alexei.guriev
 */ 


#ifndef LCD1602_H_
#define LCD1602_H_

#include "Lcd1602Cfg/Lcd1602Cfg.h"

void Lcd1602_Init(void);

void Lcd1602_Com(uint8_t p);
void Lcd1602_Data(uint8_t p);
void Lcd1602_PrintString(const char LCD_str[]);
void Lcd1602_SetPosition(uint8_t x, uint8_t y);
void Lcd1602_Clear(void);
void Lcd1602_CursorHome(void);
void Lcd1602_PrintIntVall(int vall);


#endif /* LCD1602_H_ */