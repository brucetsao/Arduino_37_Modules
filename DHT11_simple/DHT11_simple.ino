int DHpin=7; 
byte dat[5]; 

byte read_data() 
{ 
    byte data; 
    for(int i=0; i<8;i++) 
    { 
        if(digitalRead(DHpin)==LOW) 
            { 
            
                while(digitalRead(DHpin)==LOW);                   //等待50us
                    delayMicroseconds(30);                                //判斷高電位的持續時間，以判定數據是‘0’還是‘1’ 
            
                if(digitalRead(DHpin)==HIGH) 
                    data |=(1<<(7-i));                                             //高位在前，低位在後
            
                while(digitalRead(DHpin) == HIGH);                //數據‘1’，等待下一位的接收
            } 
    } 
    return data; 
} 

void start_test() 
{ 
    digitalWrite(DHpin,LOW);                          //拉低總線，發開始信號
    delay(30);                                                     //延遲時間要大於18ms，以便檢測器能檢測到開始訊號； 
    digitalWrite(DHpin,HIGH); 
    delayMicroseconds(40);                             //等待感測器響應； 
    pinMode(DHpin,INPUT); 
  while(digitalRead(DHpin) == HIGH); 
      delayMicroseconds(80);                            //發出響應，拉低总线80us； 
    if(digitalRead(DHpin) == LOW); 
        delayMicroseconds(80);                             //線路80us後開始發送數據； 

for(int i=0;i<4;i++)                                         //接收溫溼度數據，校验位不考虑； 
    dat[i] = read_data(); 

      pinMode(DHpin,OUTPUT); 
      digitalWrite(DHpin,HIGH);                              //發送完數據後釋放線路，等待下一次的開始訊號； 
  } 

void setup() 
{ 
    Serial.begin(9600); 
    pinMode(DHpin,OUTPUT); 
} 

void loop() 
{ 
    start_test(); 
    Serial.print("Current humdity = "); 
    Serial.print(dat[0], DEC);                                 //顯示濕度的整數位； 
    Serial.print('.');          
    Serial.print(dat[1],DEC);                                  //顯示濕度的小數位； 
    Serial.println('%'); 
    Serial.print("Current temperature = "); 
    Serial.print(dat[2], DEC);                                //顯示溫度的整數位； 
    Serial.print('.'); 
    Serial.print(dat[3],DEC);                                 //顯示溫度的小數位； 
    Serial.println('C'); 
    delay(700); 
  }
