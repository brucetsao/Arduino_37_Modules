
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);

int potPin = 0; //定義類比介面0 連接LM35 溫度感測器
void setup()
{
Serial.begin(9600);//設置串列傳輸速率
 // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
 
}
void loop()
{
int val;//定義變數
int dat;//定義變數
val=analogRead(0);// 讀取感測器的模擬值並賦值給val
dat=(125*val)>>8;//溫度計算公式
Serial.print("Tep:");//原樣輸出顯示Tep 字串代表溫度
Serial.print(dat);//輸出顯示dat 的值
Serial.println("C");//原樣輸出顯示C 字串
 // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
    lcd.print("Tep:");
    lcd.print(dat);
    lcd.print(" .C");
delay(500);//延時0.5 秒
}

