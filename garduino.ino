// The pins for the sensor and pump are placeholders for now
#define MOISTURE_SENSOR A0
#define WATER_PUMP A1
// The max water level for the moisture sensor is about 500, so 200 is ~40% moisture
#define DRY 200
int sensorValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Set water pump to output
  pinMode(WATER_PUMP, OUTPUT);
}

void sensorOn() 
{
  analogWrite(MOISTURE_SENSOR, 255);
}

void sensorOff()
{
  analogWrite(MOISTURE_SENSOR, 0);
}
void loop() {
  // put your main code here, to run repeatedly:
sensorOn();
  // Take the average of moisture levels over 1 second to make the data more stable
   for (int i = 0; i <= 100; i++) 
   { 
    sensorValue = sensorValue + analogRead(MOISTURE_SENSOR); 
    delay(10); 
   } 
   sensorValue = sensorValue/100.0; 

   // Turn sensor on if the soil is too dry
   if (sensorValue < DRY)
    {
      // The pump can pump 240L/hour, or about 66.6 ml/sec, so to pump out 2 liters we turn the pump on for 30 seconds
      // turn on pump 30 seconds
     sensorOff();
      digitalWrite(WATER_PUMP, HIGH); 
      delay(30000);
     
    }

   // Turn water pump off for 20 seconds
    digitalWrite(WATER_PUMP, LOW);
  sensorOff();
    delay(20000);
}
