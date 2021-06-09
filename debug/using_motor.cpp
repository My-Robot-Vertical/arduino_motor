/*
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
 */
#include "using_motor.h"
#pragma once

//void motor::motor() {
//  
//}

// #include <filters/alfaBeta.h>

void Motor::SetMode(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0) { // задаем пины для работы с шилдом мотора
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
    if      (dir==1 && pwm==0) _mode = 1;
    else if (dir==2 && pwm==0) _mode = 2;
    else if (dir==1 && pwm==1) _mode = 3;
    else if (dir==2 && pwm==1) _mode = 4;
    else _mode = 0; // такого режима нет
  }
  
  if (_mode>0) { // такой режим работы существует
    // обнуляем переменные
    _pwm_pin = 0;
    _dir_1_pin = 0;
    _dir_2_pin = 0;

    // задаем им новые значения
    if      (a=="DIR") _dir_1_pin = a_pin;
    else if (a=="PWM") _pwm_pin = a_pin;
    else dir-=10;
    if      (b=="DIR") if (_dir_1_pin==0) _dir_1_pin = b_pin; else _dir_2_pin = b_pin;
    else if (b=="PWM") _pwm_pin = b_pin;
    else dir-=10;
    if      (c=="DIR") _dir_2_pin = c_pin;
    else if (c=="PWM") _pwm_pin = c_pin;
    else dir-=10;

    // запускаем их
    pinMode(_dir_1_pin, OUTPUT);
    if (_dir_2_pin>0) pinMode(_dir_2_pin, OUTPUT);
  }
  else { // вывод ошибки (неправильно задан мотор)
    _mode = 0;
    Serial.println("motor SetMode - ERROR!!!");
  }

  // константы
  _max_speed = 100; // значение скорости по умолчанию
}

void Motor::SetSpeed(int predel) { // настраиваем новые значения, которые будут масштабироваться в 255 на мотор
  if (predel<1) Serial.println("ERROR: <SetSpeed> - invalid value");
  else _max_speed = predel; 
} 

int Motor::TestMode() { return _mode; } // проверяем режим работы

void Motor::run(int speed) {
  if (_mode==0) return;
  if (_mode==3 || _mode==4) analogWrite(_pwm_pin, map(constrain(abs(speed),0,_max_speed),0,_max_speed,0,255));
  digitalWrite(_dir_1_pin,speed>0);
  if (_mode==2 || _mode==4) digitalWrite(_dir_2_pin,speed<0);
}

void Motor::stop() { Motor::run(0); }

void Motor::block() {
  if (_mode==3 || _mode==4) analogWrite(_pwm_pin, 0);
  if (_mode==2 || _mode==4) {
    digitalWrite(_dir_1_pin,1);
    digitalWrite(_dir_2_pin,1);
  }
  else {
    digitalWrite(_dir_1_pin,0);
  }
}

/*float Motor::version(float a=0) {
   if (a==0) return motor_lib_version;
   if (a==motor_lib_version) return 1;
   Serial.println("WARNING: lib <arduino_motor> have more version!");
   return 0;
}*/
