/*
* NAME - Rohit Maurya
Date- 04/Feb/2020 
*/



#ifndef _JHD204_H_
#define _JHD204_H_

#include<Arduino.h>



/* 4 bit mode inetrfacing pin*/
#define LCD_RS D7     // Registor selector pin
#define LCD_EN D8     // Enable pin
#define LCD_Br A0    // brightness controll
#define LCD_D4 D5    // lcd data pin D1
#define LCD_D5 D6   // lcd data pin D2
#define LCD_D6 D3    // lcd data pin D3
#define LCD_D7 D4   // lcd data pin D4

/* use to diffrent command to different task */
enum command {
  LCD_Clear_Display         =   0x01,
  LCD_Home_Position         =   0x02,
  LCD_Display_On            =   0x0C,
  LCD_Display_Cursor        =   0x0E,     // Dispaly on with cursor
  LCD_Display_Cursor_blink  =   0x0F,
  LCD_Display_Off           =   0x08,
  LCD_Inc_Cursor            =   0x06,     // increment cursor after each byte wirtten display
  LCD_Inc_cur_Shift_Text    =   0x07,     // increment cursor,shift text
  LCD_Decr_cursor_Noshift   =   0x04,
  LCD_Decr_cursor_shift     =   0x05,
  LCD_Curosr_Move_Right     =   0x14,     // shift one char right
  LCD_Cursor_Move_Left      =   0x10,     // shift one char left
   
  LCD_Cursor_Move_Down      =   0xC0,     // shift cursor down one char
  LCD_Shift_Text_Right      =   0x1C,     // Shift text one space to the right
  LCD_Shift_Text_Left       =   0x18,     // Shift text one space to the left
  LCD_Set_4bit_mode         =   0x28,     // 4 bit interface,2 line display 5x7
  LCD_Display_line1         =   0x80,     // lcd display address for line 1
  LCD_Display_line2         =   0xC0,     // lcd display address for line 2
  LCD_Display_line3         =   0x94,     // lcd display address for line 3
  LCD_Display_line4         =   0xD4      // lcd display address for line 4

};


void LCD_init();
void LCD_CmdWrite(byte );
void LCD_dataWrite(byte );
void Send_data(byte);
void LCD_intWrite(int );
void set_cursor(uint8_t ,uint8_t );
void LCD_StringWrite(String );
 void LCD_ClearLine(uint8_t );

#endif
