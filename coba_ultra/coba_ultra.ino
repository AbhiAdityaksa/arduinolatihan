#define trigPin 10
#define echoPin 13
#define buzzer 9
#define redPin 6
#define greenPin 7
#define orangePin 8

float duration,distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(orangePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)*0.0343;

  Serial.print("Distance = ");
  if (distance <= 5){
    Serial.println("Bahaya");
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, LOW);
    digitalWrite(buzzer, HIGH);
    digitalWrite(redPin, HIGH);
    delay(2000);
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(redPin, LOW);
    delay(2000);
    digitalWrite(buzzer, HIGH);
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, LOW);
  }
  if(distance <= 10){
    Serial.println("Hati-Hati");
    digitalWrite(greenPin,LOW);     
    digitalWrite(orangePin,HIGH);
    delay(2000);
    digitalWrite(orangePin,LOW);
    delay(2000);
    digitalWrite(orangePin,HIGH);
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(orangePin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenPin, HIGH);
    delay(500);
  }
  delayMicroseconds(50);
}
