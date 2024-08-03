const int motorPin1 = 8; // Pin connected to IN1 on the motor driver
const int motorPin2 = 9; // Pin connected to IN2 on the motor driver
const int enablePin = 10; // Pin connected to ENA on the motor driver
char data = 0; // Variable to store the data from Bluetooth
void setup() {
 // Set all the motor control pins to outputs
 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);
 pinMode(enablePin, OUTPUT);
 pinMode(13,OUTPUT);
 // Start the serial communication
 Serial.begin(9600);
}
void forward(){
 digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, LOW);
 analogWrite(enablePin, 255); // Set speed to maximum
 delay(3000); // Run for 5 seconds (adjust as needed)
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, LOW);
}
void backward(){
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, HIGH);
 analogWrite(enablePin, 255); // Set speed to maximum
 delay(3000); // Run for 5 seconds (adjust as needed)
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, LOW);
}
void loop() {
 // Check if data is available to read
 if (Serial.available() > 0) {
Smart Home Automation with Energy Conservation
 Dept of CSD, DSCE 2023-24 10
 data = Serial.read(); // Read the incoming data
 if (data == 'F') { // Run the motor forward
 forward();
 } else if (data == 'B') { // Run the motor backward
 backward();
 } else if (data == 'S') { // Stop the motor
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, LOW);
 }
 }
float sensorValue = analogRead(A0);
 // Reads the analog input ranging from 0 to 1023
 Serial.println(sensorValue);
 if(sensorValue<=400)
 {
 digitalWrite(13,HIGH);
 }
 }
 else{
 digitalWrite(13,LOW);
 }
}