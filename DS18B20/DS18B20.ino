#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7

 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Temperature Sensor");
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("DallasTemperature");

  // 初始化 
  sensors.begin();
}

void loop(void)
{
  // 要求匯流排上的所有感測器進行溫度轉換
  sensors.requestTemperatures();

  // 取得溫度讀數（攝氏）並輸出，
  // 參數0代表匯流排上第0個1-Wire裝置 
  Serial.println(sensors.getTempCByIndex(0));
  lcd.setCursor(1, 1);
    lcd.print("              ") ;
   lcd.setCursor(1, 1);
  lcd.print(sensors.getTempCByIndex(0));

  delay(2000);
}
