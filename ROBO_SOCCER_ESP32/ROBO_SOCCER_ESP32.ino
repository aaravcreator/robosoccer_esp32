#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// SAFE Motor Pins
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

void stopMotor()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("ROBOT_GRADED"); // Change your team name here

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotor(); // Ensure motors OFF at boot
}

void loop()
{

  if (SerialBT.available())
  {
    char command = SerialBT.read();

    switch (command)
    {

    case 'F':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

    case 'B':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;

    case 'L':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

    case 'R':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;

    case 'S':
      stopMotor();
      break;
    }
  }
}
