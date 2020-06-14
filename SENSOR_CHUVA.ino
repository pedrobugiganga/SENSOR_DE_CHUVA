#include <Servo.h> // inclui a biblioteca servo.h
#define pinServo A0
#define sensorChuva A2
#define fakeGnd A4
#define fakeVcc A5
Servo servo;
int i=0;
int realchuva;
float media;
float mediaM[500];

void setup() {

 Serial.begin(9600);
 pinMode(pinServo,OUTPUT);
 pinMode(sensorChuva, INPUT);
 pinMode(fakeGnd, OUTPUT);
 pinMode(fakeVcc, OUTPUT);
 digitalWrite(fakeGnd,LOW);
 digitalWrite(fakeVcc,HIGH);
 servo.attach(pinServo);

}

void loop() {
delay(100);
for(i=0;i<500;i++)
{
  realchuva = analogRead(sensorChuva); 
  mediaM[i] = realchuva;
  media=media+mediaM[i];
}

int media_result = media / 500;

Serial.println(media_result);
if(media_result<355){
servo.write(80);
delay(2500);
}
else{
 servo.write(0);}

 media=0;
}
