//When someone touches the doorknob the analogRead value from the wire drops a bit.

int sensorPin = 0;  
int ledPin = 13;      
int sensorValue = 0;  
int pot;
int sensor;

void setup() {
 
 pinMode(ledPin, OUTPUT);  
 Serial.begin(9600);
}

void loop() {
 sensorValue = analogRead(sensorPin); //the doorknob sensor wire
delay(10);  
pot=analogRead(5);  // the potentiometer is connected to analog 5

Serial.print(sensorValue);  //sensor wire value
Serial.print("      ");
Serial.println(pot);        //potentiometer value
delay(100);

if(sensorValue<pot){   // this allows you to turn the potentiometer to a sensitive borderline value
                      // when someone touches the knob it dips just below the pot value

    digitalWrite(13,HIGH); //the led (alarm) lights up.  This could be replaced by a buzzer
    delay(100);
    digitalWrite(13,LOW);
}
 
 
}
