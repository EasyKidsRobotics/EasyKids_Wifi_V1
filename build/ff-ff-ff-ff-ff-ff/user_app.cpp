#include <Arduino.h>
#include <vector>
#include <WiFi.h>
#include <Wire.h>
#include "SPI.h"

#include "Servo.h"

#include "TFT_eSPI.h" //for matrix led

TFT_eSPI tft = TFT_eSPI();

typedef int Number;
typedef int Boolean;
using namespace std;

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

void do_something();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
void _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
void _E0_B8_AD_E0_B9_88_E0_B8_B2_E0_B8_99_E0_B8_84_E0_B9_88_E0_B8_B2_E0_B9_81_E0_B8_AA_E0_B8_87();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(int _E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2);
void _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
void _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
void _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
void _E0_B8_AD_E0_B8_AD_E0_B8_81_E0_B8_88_E0_B8_B2_E0_B8_81_E0_B8_88_E0_B8_B8_E0_B8_94_E0_B8_AA_E0_B8_95_E0_B8_B2_E0_B8_A3_E0_B9_8C_E0_B8_97();
void _E0_B9_80_E0_B8_97_E0_B8_AA_E0_B8_AA_E0_B8_A7_E0_B8_B4_E0_B8_95_E0_B8_8B_E0_B9_8C();
void _E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_8B_E0_B8_AD_E0_B8_A3_E0_B9_8C_E0_B9_82_E0_B8_A7();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(int _E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2);
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
void _E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B8_81_E0_B8_A5_E0_B8_B1_E0_B8_9A_E0_B8_95_E0_B8_B1_E0_B8_A7();
void _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_872();
void _E0_B8_AB_E0_B8_A5_E0_B8_B8_E0_B8_A1_E0_B8_94_E0_B8_B3_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
void _E0_B8_AB_E0_B8_A5_E0_B8_B8_E0_B8_94_E0_B8_94_E0_B8_B3_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_8B_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_8B_E0_B9_87_E0_B8_84_E0_B8_AA_E0_B8_B5_E0_B9_81_E0_B8_94_E0_B8_87();
int _E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2;
Number light;
Number red;
Servo Servo1;

void do_something(){

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2(){

  m1 = 45;
  m1 = map(m1, 0, 100, 0, 255);
  ledcWrite(_MotorA_ch, 0);
  ledcWrite(_MotorB_ch, m1);

  m3 = 40;
  m3 = map(m3, 0, 100, 0, 255);
  ledcWrite(_MotorC_ch, 0);
  ledcWrite(_MotorD_ch, m3);

          return;

}
void _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94(){

        ledcWrite(_MotorA_ch, 0);
        ledcWrite(_MotorB_ch, 0);
        ledcWrite(_MotorC_ch, 0);
        ledcWrite(_MotorD_ch, 0);

          return;

}
void _E0_B8_AD_E0_B9_88_E0_B8_B2_E0_B8_99_E0_B8_84_E0_B9_88_E0_B8_B2_E0_B9_81_E0_B8_AA_E0_B8_87(){
          while(1) {
    Serial.println((analogRead(36)));
  }

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(int _E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2){
          _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
  delay(_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2);
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
  delay(200);
  _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  delay(250);
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87(){

  m2 = 100;
  m2 = map(m2, 0, 100, 0, 255);
  ledcWrite(_MotorA_ch, m2);
  ledcWrite(_MotorB_ch, 0);

  m4 = 100;
  m4 = map(m4, 0, 100, 0, 255);
  ledcWrite(_MotorC_ch, m4);
  ledcWrite(_MotorD_ch, 0);

          return;

}
void _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(){

  m1 = 100;
  m1 = map(m1, 0, 100, 0, 255);
  ledcWrite(_MotorA_ch, 0);
  ledcWrite(_MotorB_ch, m1);

  m4 = 100;
  m4 = map(m4, 0, 100, 0, 255);
  ledcWrite(_MotorC_ch, m4);
  ledcWrite(_MotorD_ch, 0);

          return;

}
void _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(){

  m2 = 100;
  m2 = map(m2, 0, 100, 0, 255);
  ledcWrite(_MotorA_ch, m2);
  ledcWrite(_MotorB_ch, 0);

  m3 = 100;
  m3 = map(m3, 0, 100, 0, 255);
  ledcWrite(_MotorC_ch, 0);
  ledcWrite(_MotorD_ch, m3);

          return;

}
void _E0_B8_AD_E0_B8_AD_E0_B8_81_E0_B8_88_E0_B8_B2_E0_B8_81_E0_B8_88_E0_B8_B8_E0_B8_94_E0_B8_AA_E0_B8_95_E0_B8_B2_E0_B8_A3_E0_B9_8C_E0_B8_97(){
          while (true) {
    if (digitalRead(25) == 0) {
      delay(1000);

      m1 = 60;
      m1 = map(m1, 0, 100, 0, 255);
      ledcWrite(_MotorA_ch, 0);
      ledcWrite(_MotorB_ch, m1);

      m3 = 60;
      m3 = map(m3, 0, 100, 0, 255);
      ledcWrite(_MotorC_ch, 0);
      ledcWrite(_MotorD_ch, m3);
      delay(500);
      break;
    }
  }

          return;

}
void _E0_B9_80_E0_B8_97_E0_B8_AA_E0_B8_AA_E0_B8_A7_E0_B8_B4_E0_B8_95_E0_B8_8B_E0_B9_8C(){
          while(1) {
    if (digitalRead(25) == 0) {

      m1 = 100;
      m1 = map(m1, 0, 100, 0, 255);
      ledcWrite(_MotorA_ch, 0);
      ledcWrite(_MotorB_ch, m1);

      m3 = 100;
      m3 = map(m3, 0, 100, 0, 255);
      ledcWrite(_MotorC_ch, 0);
      ledcWrite(_MotorD_ch, m3);
    } else {
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
    }
  }

          return;

}
void _E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_8B_E0_B8_AD_E0_B8_A3_E0_B9_8C_E0_B9_82_E0_B8_A7(){
          while(1) {
    Servo1.write(0);
    delay(1000);
    Servo1.write(180);
    delay(1000);
  }

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(int _E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2){
          _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
  delay(_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2);
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
  delay(200);
  _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  delay(250);
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      delay(200);
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
      delay(120);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      delay(200);
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      delay(200);
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
      delay(120);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      delay(200);
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87(){
          Servo1.write(170);
  delay(500);
  Servo1.write(180);
  delay(500);
  Servo1.write(90);
  delay(500);

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B8_81_E0_B8_A5_E0_B8_B1_E0_B8_9A_E0_B8_95_E0_B8_B1_E0_B8_A7(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(300);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
      delay(300);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99(){
          while (true) {

    m2 = 40;
    m2 = map(m2, 0, 100, 0, 255);
    ledcWrite(_MotorA_ch, m2);
    ledcWrite(_MotorB_ch, 0);

    m4 = 40;
    m4 = map(m4, 0, 100, 0, 255);
    ledcWrite(_MotorC_ch, m4);
    ledcWrite(_MotorD_ch, 0);
    while (true) {
      if (((analogRead(27)) < light) || ((analogRead(36)) < light)) {
        break;
      }
    }
    if ((analogRead(27)) < light) {
      while ((analogRead(36)) > light) {

        m4 = 40;
        m4 = map(m4, 0, 100, 0, 255);
        ledcWrite(_MotorC_ch, m4);
        ledcWrite(_MotorD_ch, 0);

        m1 = 20;
        m1 = map(m1, 0, 100, 0, 255);
        ledcWrite(_MotorA_ch, 0);
        ledcWrite(_MotorB_ch, m1);
      }
      break;
    } else if ((analogRead(36)) < light) {
      while ((analogRead(27)) > light) {

        m2 = 40;
        m2 = map(m2, 0, 100, 0, 255);
        ledcWrite(_MotorA_ch, m2);
        ledcWrite(_MotorB_ch, 0);

        m3 = 20;
        m3 = map(m3, 0, 100, 0, 255);
        ledcWrite(_MotorC_ch, 0);
        ledcWrite(_MotorD_ch, m3);
      }
      break;
    }
  }
  delay(20);
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
  delay(100);
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      _E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
      delay(300);
      _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_872(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      _E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
      delay(300);
      _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B8_AB_E0_B8_A5_E0_B8_B8_E0_B8_A1_E0_B8_94_E0_B8_B3_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(200);
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      delay(200);
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B8_AB_E0_B8_A5_E0_B8_B8_E0_B8_94_E0_B8_94_E0_B8_B3_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(){
          while (true) {
    _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2();
    if ((analogRead(34)) < light) {
      _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87();
      delay(200);
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
      delay(150);
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      delay(200);
      break;
    } else if ((analogRead(39)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
    } else if ((analogRead(26)) < light) {
      _E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_8B_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99(){
          while (true) {

    m1 = 30;
    m1 = map(m1, 0, 100, 0, 255);
    ledcWrite(_MotorA_ch, 0);
    ledcWrite(_MotorB_ch, m1);

    m3 = 30;
    m3 = map(m3, 0, 100, 0, 255);
    ledcWrite(_MotorC_ch, 0);
    ledcWrite(_MotorD_ch, m3);
    if (((analogRead(39)) < light) || ((analogRead(26)) < light)) {
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      break;
    }
  }
  if ((analogRead(26)) < light) {
    while ((analogRead(39)) > light) {

      m2 = 0;
      m2 = map(m2, 0, 100, 0, 255);
      ledcWrite(_MotorA_ch, m2);
      ledcWrite(_MotorB_ch, 0);

      m3 = 40;
      m3 = map(m3, 0, 100, 0, 255);
      ledcWrite(_MotorC_ch, 0);
      ledcWrite(_MotorD_ch, m3);
    }
  } else if ((analogRead(39)) < light) {
    while ((analogRead(26)) > light) {

      m4 = 0;
      m4 = map(m4, 0, 100, 0, 255);
      ledcWrite(_MotorC_ch, m4);
      ledcWrite(_MotorD_ch, 0);

      m1 = 40;
      m1 = map(m1, 0, 100, 0, 255);
      ledcWrite(_MotorA_ch, 0);
      ledcWrite(_MotorB_ch, m1);
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}
void _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_8B_E0_B9_87_E0_B8_84_E0_B8_AA_E0_B8_B5_E0_B9_81_E0_B8_94_E0_B8_87(){
          while (true) {

    m1 = 30;
    m1 = map(m1, 0, 100, 0, 255);
    ledcWrite(_MotorA_ch, 0);
    ledcWrite(_MotorB_ch, m1);

    m3 = 30;
    m3 = map(m3, 0, 100, 0, 255);
    ledcWrite(_MotorC_ch, 0);
    ledcWrite(_MotorD_ch, m3);
    if (((analogRead(39)) == red) || ((analogRead(26)) == red)) {
      _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();
      break;
    }
  }
  if ((analogRead(26)) == red) {
    while ((analogRead(39)) == red) {

      m2 = 0;
      m2 = map(m2, 0, 100, 0, 255);
      ledcWrite(_MotorA_ch, m2);
      ledcWrite(_MotorB_ch, 0);

      m3 = 40;
      m3 = map(m3, 0, 100, 0, 255);
      ledcWrite(_MotorC_ch, 0);
      ledcWrite(_MotorD_ch, m3);
    }
  } else if ((analogRead(39)) == red) {
    while ((analogRead(26)) == red) {

      m4 = 0;
      m4 = map(m4, 0, 100, 0, 255);
      ledcWrite(_MotorC_ch, m4);
      ledcWrite(_MotorD_ch, 0);

      m1 = 40;
      m1 = map(m1, 0, 100, 0, 255);
      ledcWrite(_MotorA_ch, 0);
      ledcWrite(_MotorB_ch, m1);
    }
  }
  _E0_B8_AB_E0_B8_A2_E0_B8_B8_E0_B8_94();

          return;

}


void setup()
{
ledcSetup(_MotorA_ch, 75, 8);
ledcAttachPin(_EN_A, _MotorA_ch);
ledcSetup(_MotorB_ch, 75, 8);
ledcAttachPin(_EN_B, _MotorB_ch);
ledcSetup(_MotorC_ch, 75, 8);
ledcAttachPin(_EN_C, _MotorC_ch);
ledcSetup(_MotorD_ch, 75, 8);
ledcAttachPin(_EN_D, _MotorD_ch);
  
  Serial.begin(115200);
  pinMode(25,INPUT);
  light = 1600;
  red = 2700;
  
  
  Servo1.attach(15);
  Servo1.write(90);
  _E0_B8_AD_E0_B9_88_E0_B8_B2_E0_B8_99_E0_B8_84_E0_B9_88_E0_B8_B2_E0_B9_81_E0_B8_AA_E0_B8_87();
  _E0_B8_AD_E0_B8_AD_E0_B8_81_E0_B8_88_E0_B8_B2_E0_B8_81_E0_B8_88_E0_B8_B8_E0_B8_94_E0_B8_AA_E0_B8_95_E0_B8_B2_E0_B8_A3_E0_B9_8C_E0_B8_97();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(400);
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(1000);
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B8_81_E0_B8_A5_E0_B8_B1_E0_B8_9A_E0_B8_95_E0_B8_B1_E0_B8_A7();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(500);
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_872();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2(400);
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B8_81_E0_B8_A5_E0_B8_B1_E0_B8_9A_E0_B8_95_E0_B8_B1_E0_B8_A7();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_9B_E0_B8_A5_E0_B9_88_E0_B8_AD_E0_B8_A2_E0_B8_82_E0_B8_AD_E0_B8_87();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(500);
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B8_99_E0_B8_B1_E0_B8_9A_E0_B9_80_E0_B8_A7_E0_B8_A5_E0_B8_B2_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2(400);
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_82_E0_B8_A7_E0_B8_B2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_88_E0_B8_AD_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99_E0_B9_81_E0_B8_A5_E0_B9_89_E0_B8_A7_E0_B9_80_E0_B8_A5_E0_B8_B5_E0_B9_89_E0_B8_A2_E0_B8_A7_E0_B8_8B_E0_B9_89_E0_B8_B2_E0_B8_A2();
  _E0_B8_96_E0_B8_AD_E0_B8_A2_E0_B8_AB_E0_B8_A5_E0_B8_B1_E0_B8_87_E0_B9_80_E0_B8_8A_E0_B9_87_E0_B8_84_E0_B9_80_E0_B8_AA_E0_B9_89_E0_B8_99();
  _E0_B9_80_E0_B8_94_E0_B8_B4_E0_B8_99_E0_B8_AB_E0_B8_99_E0_B9_89_E0_B8_B2_E0_B9_80_E0_B8_8B_E0_B9_87_E0_B8_84_E0_B8_AA_E0_B8_B5_E0_B9_81_E0_B8_94_E0_B8_87();
}
void loop()
{
  /**
 * Describe this function...
 */
/**
 * ฟังชั่นก์เดินหน้า
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */
/**
 * Describe this function...
 */

  
}