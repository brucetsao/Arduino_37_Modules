#include <LiquidCrystal.h>
#define relayDPin  7  

 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);
 
 
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

