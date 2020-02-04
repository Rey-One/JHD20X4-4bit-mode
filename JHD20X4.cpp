

#include"JHD20x4.h"
extern command cmd;
/*========================================================
   initilize the pin output mode for 4 bit interfacing
  =========================================================*/
/* first initilize the pin and  Display command to write the
    any charecter in LCD
*/
void LCD_init()
{
  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_EN, OUTPUT);
  pinMode(LCD_D4, OUTPUT);
  pinMode(LCD_D5, OUTPUT);
  pinMode(LCD_D6, OUTPUT);
  pinMode(LCD_D7, OUTPUT);
  pinMode(LCD_Br, OUTPUT);


  LCD_CmdWrite(LCD_Home_Position);            // reset
  LCD_CmdWrite(LCD_Set_4bit_mode);            // Initialize Lcd in 4-bit mode,2 line enable 5x7 mode for chars
//  LCD_CmdWrite( LCD_Display_On );             // Display on only
  LCD_CmdWrite( 0x0E );

}
/*=====================================================
    command write in 4bitmode interfacing
  ======================================================*/
// send command data hexadecimal value

void LCD_CmdWrite(byte cmd)
{
  digitalWrite(LCD_RS, LOW);
  /* send higher bit cmd data */
  Send_data( cmd >> 4);
  digitalWrite(LCD_EN, HIGH);
  digitalWrite(LCD_EN, LOW);
  /*send lower bit cmd data*/
  Send_data( cmd );
  digitalWrite(LCD_EN, HIGH);
  digitalWrite(LCD_EN, LOW);
  delayMicroseconds(100);
}

/*=========================================
      data write in 4 bit mode
  ============================================*/
// send data (ascii value) to write the display

void LCD_dataWrite(byte data)
{
  digitalWrite(LCD_RS, HIGH);
  /* send higher bit cmd data */
  Send_data( data >> 4);
  digitalWrite(LCD_EN, HIGH);
  digitalWrite(LCD_EN, LOW);
  /*send lower bit cmd data*/
  Send_data( data );
  digitalWrite(LCD_EN, HIGH);
  digitalWrite(LCD_EN, LOW);
  delayMicroseconds(200);
}

/*=============================================
    Display the string data  into LCD

  ==============================================*/
// pass the string argument through the function

void LCD_StringWrite(String str)
{
  for (uint8_t i = 0; i < str.length(); i++)
  {
    LCD_dataWrite(str[i]);
    
  }
}
/*===================================================================
   create a function to pass the 4 bit (lower or higher bit) data
   through the function and send the value to different pin of LCD
  =====================================================================*/

// function use to send the 4 bit data to different port of LCD

void Send_data(byte num)
{
  digitalWrite(LCD_D4, (num >> 0) & 1);
  digitalWrite(LCD_D5, (num >> 1) & 1);
  digitalWrite(LCD_D6, (num >> 2) & 1);
  digitalWrite(LCD_D7, (num >> 3) & 1);
}

/*=========================================================================
       Scrolling line  string  on LCD
         where cursor indicate
/*  =========================================================================*/
/* set the cursor position on sting
 *   pass row and colom value
 *   row and col start form 0
 *==========================================================================*/
void set_cursor(uint8_t row, uint8_t col)
{
  switch (row)
  {
    case 0 :Serial.println("line1"); LCD_CmdWrite(LCD_Display_line1 + col); break;
    case 1 :Serial.println("line2"); LCD_CmdWrite(LCD_Display_line2 + col); break;
    case 2 :Serial.println("line3"); LCD_CmdWrite(LCD_Display_line3 + col); break;
    case 3 :Serial.println("line4"); LCD_CmdWrite(LCD_Display_line4 + col); break;
  }

}
/*=========================================================================
 * this uction use to clesar the particular line 
 *========================================================================*/
 void LCD_ClearLine(uint8_t len)
 {
  set_cursor(len, 2);
  for(uint8_t i=0;i<18;i++)
  LCD_dataWrite(0x00);
 }
/*=========================================================================
       Scrolling line  string  on LCD
         where cursor indicate
/*  =========================================================================*/
/*
void LCD_ScrollingString(String Str)
{
  if(Str.length() > 18)
  {
    
  }
}*/
