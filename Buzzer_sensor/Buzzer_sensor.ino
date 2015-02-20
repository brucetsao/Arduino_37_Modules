#define speakerPin 7                                     //設定喇叭的接腳為第8孔
void setup()
{
    pinMode(speakerPin,OUTPUT)   ;           //設定喇叭為輸出  
}

void loop()
{
    digitalWrite(speakerPin, HIGH); 
        
    delay(1000);                                               //設定喇叭饗的時間 
    
    digitalWrite(speakerPin, LOW); 
    
    delay(1000)    ;                                           //設定喇叭不響的時間 

}    
