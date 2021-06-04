/*
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
 */
#include "arduino_motor.h"
#pragma once

//void motor::motor() {
//  
//}

void motor::SetMode(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0) { // задаем пины для работы с шилдом мотора
  char dir = 0, pwm = 0;

  // проверка на корректность ввода
  if      (a=="DIR") dir++;
  else if (a=="PWM") pwm++;
  else dir-=10;
  if      (b=="DIR") dir++;
  else if (b=="PWM") pwm++;
  else if (b!="")  dir-=10;
  if      (c=="DIR") dir++;
  else if (c=="PWM") pwm++;
  else if (c!="")  dir-=10;
  
  if (dir>0) { // если нет ошибок в вводе, задаем режим работы
    if      (dir==1 && pwm==0) mode = 1;
    else if (dir==2 && pwm==0) mode = 2;
    else if (dir==1 && pwm==1) mode = 3;
    else if (dir==2 && pwm==1) mode = 4;
    else mode = 0; // такого режима нет
  }
  
  if (mode>0) { // такой режим работы существует
    // обнуляем переменные
    pwm_pin = 0;
    dir_1_pin = 0;
    dir_2_pin = 0;

    // задаем им новые значения
    if      (a=="DIR") dir_1_pin = a_pin;
    else if (a=="PWM") pwm_pin = a_pin;
    else dir-=10;
    if      (b=="DIR") if (dir_1_pin==0) dir_1_pin = b_pin; else dir_2_pin = b_pin;
    else if (b=="PWM") pwm_pin = b_pin;
    else dir-=10;
    if      (c=="DIR") dir_2_pin = c_pin;
    else if (c=="PWM") pwm_pin = c_pin;
    else dir-=10;

    // запускаем их
    pinMode(dir_1_pin, OUTPUT);
    if (dir_2_pin>0) pinMode(dir_2_pin, OUTPUT);
  }
  else { // вывод ошибки (неправильно задан мотор)
    mode = 0;
    Serial.println("motor SetMode - ERROR!!!");
  }
}

int motor::TestMode() { return mode; } // проверяем режим работы
