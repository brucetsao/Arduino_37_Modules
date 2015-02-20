int ledPin=6;

int sensorPin=0;

const double alpha = 0.75;              // smoothing參數 可自行調整0~1之間的值
const double beta = 0.5;                // find peak參數 可自行調整0~1之間的值
const int period = 20;                  // sample脈搏的delay period

double change=0.0;

void setup()
{
Serial.begin(9600);
pinMode(ledPin,OUTPUT);

}

void loop()
{

 senseHeartRate();  

}

void senseHeartRate()
{
    int count = 0;                              // 記錄心跳次數
    double oldValue = 0;                        // 記錄上一次sense到的值
    double oldChange = 0;                       // 記錄上一次值的改變
       
    unsigned long startTime = millis();         // 記錄開始測量時間
   
    while(millis() - startTime < 10000) {       // sense 10 seconds
        int rawValue = analogRead(sensorPin);   // 讀取心跳sensor的值
        double value = alpha*oldValue + (1-alpha)*rawValue;     //smoothing value
   
        //find peak
        double change = value-oldValue;         // 計算跟上一次值的改變量
        if (change>beta && oldChange<-beta) {   // heart beat
            count = count + 1;
        }
         
        oldValue = value;
        oldChange = change;
        delay(period);
    }
 
}

