
#include <Servo.h>
#include <LiquidCrystal.h>

const int moistureSen = A0;  // Moisture sensor
const int metalSen = 13;

const int wetLed = A3;
const int dryLed = A4;
const int metalLed = A5;

const int in1 = 5;
const int in2 = 6;
const int en = 4;

bool runOnce = true;
Servo wet;
Servo dry;
Servo metal;

void setup() {

  servoAttach();
  pinMode(wetLed, OUTPUT);
  pinMode(dryLed, OUTPUT);
  pinMode(metalLed, OUTPUT);
  pinMode(en, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  conveyorRun();
  if (digitalRead(metalSen) == HIGH && runOnce) {
    digitalWrite(metalLed, HIGH);
    delay(200);
    digitalWrite(metalLed, LOW);
    metal.write(180);
    delay(300);
    metal.write(0);
    Serial.print("Detected: ");
    Serial.println("Metal");
    delay(200);
  }
  if (analogRead(moistureSen) >= 500) {
    digitalWrite(wetLed, HIGH);
    delay(200);
    digitalWrite(wetLed, LOW);
    wet.write(180);
    delay(300);
    wet.write(0);
    Serial.print("Detected: Wet Non-metal: MoistureLevel: ");
    Serial.println(analogRead(moistureSen));
    delay(200);
  } else if (analogRead(moistureSen) <= 200) {
    digitalWrite(dryLed, HIGH);
    delay(200);
    digitalWrite(dryLed, LOW);
    dry.write(180);
    delay(300);
    dry.write(0);
    Serial.print("Detected: Dry Non-metal: MoistureLevel: ");
    Serial.println(analogRead(moistureSen));
    delay(200);
  }

  // Serial.println(digitalRead(metalSen));
  // // delay(200);
  // digitalWrite(dryLed, LOW);
  // dry.write(180);
  // delay(300);
  // dry.write(0);
}
void servoAttach() {
  wet.attach(12);
  dry.attach(11);
  metal.attach(10);
}
void conveyorRun() {
  digitalWrite(en, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}