// Pin number
const int trig = 9;
const int echo = 10;
const int buzz = 11;
const int led = 13;

long duration;
int distance;
int safeDistance;


void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //Clears the trig Pin
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  //Sets the trigPIn on HIGH state for 10 micro sec

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  //Reads the echopins, return the sound wave travel time in microseconds
  duration = pulseIn(echo,HIGH);

  //Calculating distance
  distance = duration*0.034/2;
  safeDistance = distance;

  //Distance for the alarm
  if(safeDistance <= 20){
  digitalWrite(buzz,HIGH);
  digitalWrite(led,HIGH);
  }else {
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);
  }

  //Print Distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

}
