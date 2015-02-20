#include <LiquidCrystal.h>
#define DPin 7
#define LedPin 6
#define APin A0

 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);
 
   int val = 0 ;
  int oldval =0  ;
void setup() 
{ 
pinMode(LedPin,OUTPUT);//設置數位IO腳模式，OUTPUT為Output 
 pinMode(DPin,INPUT);//定義digital為輸入介面
 //pinMode(APin,INPUT);//定義為類比輸入介面
 

  Serial.begin(9600);//設定串列傳輸速率為9600 } 
 
 // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Photo Interrupter");
}
void loop() {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):


   val=digitalRead(DPin);//讀取感測器的值 
    Serial.print(oldval);//輸出模擬值，並將其列印出來
    Serial.print("/");//輸出模擬值，並將其列印出來
    Serial.print(val);//輸出模擬值，並將其列印出來
    Serial.print("\n");//輸出模擬值，並將其列印出來
 
    if (val ==1)
    {
          if (val != oldval)
            {
                lcd.setCursor(1, 1);
                  lcd.print("              ") ;
                 lcd.setCursor(1, 1);
                lcd.print("SomeBody Coming");
                 digitalWrite(LedPin,HIGH)  ; 
                   delay(50);  
                  oldval= val ;
            }
    }
    else
    {
          if (val != oldval)
            {
                lcd.setCursor(1, 1);
                lcd.print("                ") ;
               lcd.setCursor(1, 1);
              lcd.print("Ready");
               digitalWrite(LedPin,LOW)  ; 
                oldval= val ;
            }
      }
 

} 



