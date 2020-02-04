

#include"JHD20x4.h"


void setup() {
  Serial.begin(9600);
  LCD_init();
  
  LCD_CmdWrite(LCD_Clear_Display);
  set_cursor(0, 0);
  delay(1000);
//   LCD_CmdWrite(0x80);
  LCD_StringWrite("WELLCOM TO GITHUB ");
  delay(2000);
  LCD_CmdWrite(LCD_Display_line2);
  LCD_StringWrite("Rohit maurya ");
  delay(2000);
  LCD_CmdWrite(LCD_Display_line3);
  LCD_StringWrite("prayagRaj ");
 delay(2000);
 LCD_CmdWrite(LCD_Display_line4);
  LCD_StringWrite("Utter Pradesh ");
  delay(2000);
 

}


void loop() {
  // put your main code here, to run repeatedly:

}
