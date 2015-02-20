#include <LiquidCrystal.h>
#define ZPin 7
#define LedPin1 6
#define LedPin2 5
#define XPin A0
#define YPin A1

 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);
 
   int val1 = 0 ;
   int val2 = 0 ;
   int val3 = 0 ;
void setup() 
{ 
pinMode(LedPin1,OUTPUT);//設置數位IO腳模式，OUTPUT為Output 
pinMode(LedPin2,OUTPUT);//設置數位IO腳模式，OUTPUT為Output 
 pinMode(ZPin,INPUT);//定義digital為輸入介面
 //pinMode(XPin,INPUT);//定義為類比輸入介面
// pinMode(YPin,INPUT);//定義為類比輸入介面

 

  Serial.begin(9600);//設定串列傳輸速率為9600 } 
 
 // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("XY Joystick");
}
void loop() 
{

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):


   val1=analogRead(XPin);
   val2=analogRead(YPin);
   val3=digitalRead(ZPin);
    Serial.print(val1);
    Serial.print("/");
    Serial.print(val2);
    Serial.print("/");
    Serial.print(val3);
    Serial.print("\n");
 
      lcd.setCursor(1, 1);
        lcd.print("                 ") ;
       lcd.setCursor(1, 1);
      lcd.print("X=");
       lcd.print(val1);
      // digitalWrite(val1)  ; 
      lcd.print("  Y=");
       lcd.print(val2);
      // digitalWrite(val2)  ;
       lcd.print(" Z=");
       lcd.print(val3);     
       
       //-------------
       analogWrite(LedPin1,map(val1,0,1023,0,255)) ;
       analogWrite(LedPin2,map(val2,0,1023,0,255)) ;
         delay(10);  
          

} 



