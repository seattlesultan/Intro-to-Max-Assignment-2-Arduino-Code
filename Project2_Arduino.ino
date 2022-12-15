/*
 * This sketch sends one sensor and a counter value that increments once per loop as packet that consists of a list of 2 items 
 * separated by a space.
 */
const int potpin1 = 2;
const int potpin2 = 3; 
int sensorValue1 = 0; // variable to store sensor value
int sensorValue2 = 0; // variable to store sensor value
int pot1 = 0;
int pot2 = 0;
int button = 0;
int buttonPort = 4;



int count; // variable to store loop counter

void setup() {
  Serial.begin(9600); 
  pinMode(4, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  button = digitalRead(buttonPort);
  sensorValue1 = analogRead(0); // analog read into sensor value variable
  sensorValue2 = analogRead(1);
  pot1 = analogRead(potpin1);
  pot2 = analogRead(potpin2);
  count = count + 1; // increment counter
  
  Serial.print(button);
  Serial.write(32);
  
  Serial.print(pot1);
  Serial.write(32);
  
  Serial.print(pot2);
  Serial.write(32);
  
  Serial.print(sensorValue1);
  Serial.write(32);
  
  Serial.print(sensorValue2);
  Serial.write(32);
  
  Serial.println(count); //Print counter state to serial and immediately send ASCII 13 and 10 to mark end of the packet.
  delay(100);
}
