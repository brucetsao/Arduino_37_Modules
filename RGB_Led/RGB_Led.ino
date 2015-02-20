int LedRpin = 7;    // dual Led Color1 Pin
int LedGpin =6;     // dual Led Color2 Pin
int LedBpin =5;     // dual Led Color3 Pin
int i,j,k;

void setup() {
  pinMode(LedRpin, OUTPUT);
  pinMode(LedGpin, OUTPUT);
  pinMode(LedBpin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
for(i=0; i<255; i++)
  {
    for(j=0; j<255; j++)
      {
        for(k=0; k<255; k++)
          {
           analogWrite(LedRpin, i);
           analogWrite(LedGpin, j);
           analogWrite(LedBpin, k);
          }
      }
      
  }

}
