#include <LiquidCrystal.h>
#define SERIAL_BAUDRATE 9600
#define CLK_PIN 2 // 定義連接腳位
#define DT_PIN 3
#define SW_PIN 4

#define interruptA 0 // UNO腳位2是interrupt 0，其他板子請見官方網頁

volatile long count = 0;
unsigned long t = 0;
 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);


void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  // 當狀態下降時，代表旋轉編碼器被轉動了
  attachInterrupt(interruptA, rotaryEncoderChanged, FALLING);
  pinMode(CLK_PIN, INPUT_PULLUP); // 輸入模式並啟用內建上拉電阻
  pinMode(DT_PIN, INPUT_PULLUP); 
  pinMode(SW_PIN, INPUT_PULLUP); 
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Rotary Sensor");

}
void loop() {
  if(digitalRead(SW_PIN) == LOW){ // 按下開關，歸零
     count = 0;  
     Serial.println("count reset to 0");
      lcd.setCursor(1, 1);
        lcd.print("              ") ;
       lcd.setCursor(1, 1);
      lcd.print("Count reset to 0");

     delay(300);
  }
}
void rotaryEncoderChanged(){ // when CLK_PIN is FALLING
  unsigned long temp = millis();
  if(temp - t < 200) // 去彈跳
    return;
  t = temp;
  
  // DT_PIN的狀態代表正轉或逆轉
  count += digitalRead(DT_PIN) == HIGH ? 1 : -1;
  Serial.println(count);
    lcd.setCursor(1, 1);
    lcd.print("                 ") ;
   lcd.setCursor(1, 1);
  lcd.print("Counter = ");
  lcd.print(count);
  
}
