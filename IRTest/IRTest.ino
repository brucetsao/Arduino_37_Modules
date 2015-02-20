#include <LiquidCrystal.h>
#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN); // 初始化紅外線訊號輸入
decode_results results; // 儲存訊號的結構
 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);
 void setup() 
{ 
  Serial.begin(9600);//設定串列傳輸速率為9600 } 
 
 // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("IR Test");
  irrecv.enableIRIn(); // 啟動接收
}
void loop() {
  if (irrecv.decode(&results)) { // 接收紅外線訊號並解碼
    Serial.print("results value is "); // 輸出解碼後的資料
    Serial.print(results.value, HEX);
    Serial.print(", bits is ");
    Serial.print(results.bits);
    Serial.print(", decode_type is ");
    Serial.println(results.decode_type);
    irrecv.resume(); // 準備接收下一個訊號
  }} 



