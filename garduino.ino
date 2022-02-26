#define MOISTURESENSOR A0
#define WATERPUMP A1
int dry = 200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(WATERPUMP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   for (int i = 0; i <= 100; i++) 
   { 
    sensorValue = sensorValue + analogRead(MOISTURESENSOR); 
    delay(1); 
   } 
   sensorValue = sensorValue/100.0; 

   if (sensorValue < dry)
    {
      digitalWrite(WATERPUMP, HIGH); // turn on pump 5 seconds
      delay(10000);
    }
}
