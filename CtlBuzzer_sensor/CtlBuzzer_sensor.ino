#define speakerPin 7                                    //設定蜂鸣器接腳為第7孔
void setup()
{  
      pinMode(speakerPin,OUTPUT);                    //設定蜂鳴器為輸出
}

void loop()
{
  
unsigned char i,j;                                      //定義變數
while(1)
  {
    for(i=0;i<80;i++);                                        //發出一個频率的聲音
      {   
          digitalWrite(speakerPin,HIGH);                       //發出聲音
          delay(1);                                                      //延时1ms
          digitalWrite(speakerPin,LOW);                      //不發聲音
          delay(1);                                                      //延时1ms
          
          for(i=0;i<100;i++);                                     //發出另一個頻率的聲音
          {  
              digitalWrite(speakerPin,HIGH);                      //發聲音
              delay(2);                                                     //延时2ms
              digitalWrite(speakerPin,LOW);                     //不發聲音
              delay(2);                                                     //延时2ms
          }
      }
  }

}
