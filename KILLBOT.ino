#include <Servo.h>
#include <NewPing.h>
//delcare the pins used for recieving an echo and trig calculations to find proximity
#define TRIG_PIN 5
#define ECHO_PIN 4

NewPing sonar(TRIG_PIN, ECHO_PIN, 400); // NewPing setup of pins and maximum distance.

Servo launch;
Servo wrist;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  launch.attach(2);
  wrist.attach(3);
}

void attack(){
  wrist.write(90);
  launch.write(45);
  delay(400);
  launch.write(90);
  delay(1000);
  launch.write(135);
  delay(700);
  launch.write(90);
}

void loop() {
  wrist.write(135);
  delay(50);
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  int dist = uS / US_ROUNDTRIP_CM;
  if(dist != 0 && dist <= 5){
    attack();
  }

}
