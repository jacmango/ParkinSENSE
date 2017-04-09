int sensorPin = A0;   //sensor on the Arduino analog 0
int speakerPin = 9;   //speaker on Arduino pin 9
int ledPin = 13;      //led on Arduino pin ~13
 
//minimum and maximum values detected by the sensor
//it may depend on the sensor and circuit
//you can test them empirically
int minValue = 0;      
int maxValue = 1023;
 
void setup()
{
  //setting the digital 
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
    int sensorValue = analogRead(sensorPin);    
 
    //for the LED in PWM (light intensity) the value I read needs to be mapped to 0-255
    int output = map(sensorValue, minValue, maxValue, 0, 255);
 
    //send it to the pin
    analogWrite(ledPin, output);
 

 
    //print it to the console
    Serial.print("\t Analog input = ");      
    Serial.println(sensorValue);
 
    Serial.print("\t Analog output = ");      
    Serial.println(output);
 
}
