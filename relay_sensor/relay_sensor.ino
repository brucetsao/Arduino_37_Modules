#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define relayDPin  7  

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
 
 
void setup() 
{ 

 pinMode(relayDPin,OUTPUT);
 

  Serial.begin(9600);//設定串列傳輸速率為9600 } 
 
 // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Relay Control");
}
void loop() {
  int val ;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
        lcd.setCursor(0, 1);
        lcd.print("                    ") ;
         digitalWrite(relayDPin,HIGH);
        Serial.println("Open Relay & Turn on Led");
           lcd.setCursor(0, 1);
          lcd.print("Turn on Led");
        delay(3000);  
//-------------------------------------
        lcd.setCursor(0, 1);
        lcd.print("                    ") ;
         digitalWrite(relayDPin,LOW);
        Serial.println("Open Relay & Turn on Led");
           lcd.setCursor(0, 1);
          lcd.print("Turn off Led");
        delay(1000);  

} 

