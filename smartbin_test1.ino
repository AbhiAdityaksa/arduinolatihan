#define trigpin 9
#define echopin 8
#define ledred 7
#define trigpin2 5
#define echopin2 6

#include <Servo.h>

Servo servo;

float duration, distance, duration2, distance2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode (echopin,INPUT);
  pinMode(trigpin2,OUTPUT);
  pinMode (echopin2,INPUT);
  pinMode (ledred, OUTPUT);
  servo.attach(10);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin2,LOW);
  duration2 = pulseIn(echopin2, HIGH);
  distance2 = (duration2/2)*0.0343;

  if(distance2 >= 8){
    sampahterbuka();
  }else{
    servo.write(90);
    Serial.println("Sampah penuh");
    Serial.println(" ");
    Serial.print(distance2);
    Serial.println(" cm");
    digitalWrite(ledred,HIGH);
    delay(2000);
    digitalWrite(ledred,LOW);
    delayMicroseconds(200);
    digitalWrite(ledred,HIGH);
    delayMicroseconds(200);
    digitalWrite(ledred,LOW);
    delay(200);
    digitalWrite(ledred,HIGH);
    delay(1000);
  }
}
void sampahterbuka(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)*0.0343;
  
  if (distance <= 30){
    digitalWrite(trigpin2,LOW);
    digitalWrite(echopin2,LOW);
    digitalWrite(ledred,HIGH);
    Serial.println("Silakan");
    servo.write(0);
    delay(2000);
    servo.detach(); 
    delay(5000);
    servo.attach(10);
  }else{
    digitalWrite(ledred,LOW);
    servo.write(90);
    Serial.print(distance);
    Serial.println(" cm");
    delayMicroseconds(3000);
  }
  delay(1500);
}
