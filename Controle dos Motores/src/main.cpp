#include <Arduino.h>
#include <ESP32Servo.h>
#include <Ps3Controller.h>

Servo myservo;

void setup() {
    Serial.begin(9600);
    Ps3.begin("94:b9:7e:d5:ab:e2");

    myservo.attach(27);
    myservo.write(1);

    Serial.println("Ready.");
}

void loop() {
  if (Ps3.data.button.cross){
    myservo.write(178);
  }

  if (Ps3.data.button.triangle){
    myservo.write(2);
  }
}