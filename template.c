#include <Arduino.h>
#include <vector>
#include <WiFi.h>
#include <Wire.h>
#include "Servo.h"

${EXTINC}

typedef int Number;
typedef int Boolean;
using namespace std;
Servo Servo1;
Servo Servo2;
#define _EN_A  16
#define _EN_B  17
#define _EN_C  18
#define _EN_D  19
#define _MotorA_ch  4
#define _MotorB_ch  5
#define _MotorC_ch  6
#define _MotorD_ch  7
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;
int speedm = 0;

${VARIABLE}

${FUNCTION}


void setup()
{
Servo1.attach(14);
Servo2.attach(15);
ledcSetup(_MotorA_ch, 75, 8);
ledcAttachPin(_EN_A, _MotorA_ch);
ledcSetup(_MotorB_ch, 75, 8);
ledcAttachPin(_EN_B, _MotorB_ch);
ledcSetup(_MotorC_ch, 75, 8);
ledcAttachPin(_EN_C, _MotorC_ch);
ledcSetup(_MotorD_ch, 75, 8);
ledcAttachPin(_EN_D, _MotorD_ch);
  ${SETUP_CODE}
  ${BLOCKSETUP}
}
void loop()
{
  ${LOOP_CODE}
  ${LOOP_EXT_CODE}
}