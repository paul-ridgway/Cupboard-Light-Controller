#include <Arduino.h>

#define OUT1 11
#define OUT2 6
#define IN1 7
#define IN2 8

void setup()
{
  Serial.begin(9600);
  delay(100);
  while (!Serial)
  {
  }
  Serial.println("Light Control!");

  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
}

uint32_t in1On = 0;
uint32_t in2On = 0;

void loop()
{
  bool in1 = !digitalRead(IN1);
  bool in2 = !digitalRead(IN2);

  if (in1)
  {
    if (in1On == 0)
    {
      in1On = millis();
    }
  }
  else
  {
    in1On = 0;
  }

  if (in2)
  {
    if (in2On == 0)
    {
      in2On = millis();
    }
  }
  else
  {
    in2On = 0;
  }

  if (in1 && millis() - in1On > 600000) {
    in1 = false;
  }

  if (in2 && millis() - in2On > 600000) {
    in2 = false;
  }

  Serial.print("In 1:");
  Serial.print(in1);
  Serial.print(". In 2:");
  Serial.println(in2);
  digitalWrite(OUT1, in1);
  digitalWrite(OUT2, in2);

  delay(100);
}