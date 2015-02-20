int Led1pin = 7;    // dual Led Color1 Pin
int Led2pin =6;     // dual Led Color2 Pin
int val;

void setup() {
  pinMode(Led1pin, OUTPUT);
  pinMode(Led2pin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
for(val=255; val>0; val--)
  {
   analogWrite(Led1pin, val);
   analogWrite(Led2pin, 255-val);
   delay(15); 
  }
for(val=0; val<255; val++)
  {
   analogWrite(Led1pin, val);
   analogWrite(Led2pin, 255-val);
   delay(15); 
  }
 Serial.println(val, DEC);
}
