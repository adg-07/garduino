#define MOISTURESENSOR A0
#define WATERPUMP A1

// Max amount for the moisture sensor is around 500, so 200 is roughly 40% moisture
int dry = 200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Set water pump to output
  pinMode(WATERPUMP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Take the average of moisture levels over 1 second to make the data more stable
   for (int i = 0; i <= 100; i++) 
   { 
    sensorValue = sensorValue + analogRead(MOISTURESENSOR); 
    delay(10); 
   } 
   sensorValue = sensorValue/100.0; 

   // Turn sensor on if the soil is too dry
   if (sensorValue < dry)
    {
      // turn on pump 10 seconds
      digitalWrite(WATERPUMP, HIGH); 
      delay(10000);
    }

   // Turn water pump off
    digitalWrite(WATERPUMP, LOW);
    delay(10000);
}
