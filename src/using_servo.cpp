/*
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
 */
#include "using_servo.h"
#pragma once

servo_motor_data_cell *_servo_motor_data_my = 0;

ServoMotor::ServoMotor(int pin, servo_motor_data_cell* &data = _servo_motor_data_my) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  if (!data) {
    data = new servo_motor_data_cell;
    data->pin = pin;
    data->angle = -1000;
    data->next_cell = 0;
  }
  else if (data->pin != pin) ServoMotor::ServoMotor(pin, data->next_cell);
  else Serial.println("ERROR: this servo has already been initialized");
}

void ServoMotor::write(int angle, servo_motor_data_cell* &data = _servo_motor_data_my) {
  if (!data) {
    Serial.print("ERROR: no servo on pin ");
    Serial.println(_pin);
  }
  else {
    if (_pin==data->pin) {
      ServoMotor_my_write(_pin, angle);
      data->angle=angle;
    }
    else ServoMotor::write(angle, data->next_cell);
  }
}

void ServoMotor::writeMicroseconds(int timer) {
  timer = map(timer,544,2400,0,180);
  ServoMotor::write(timer);
}

int ServoMotor::read(servo_motor_data_cell* data = _servo_motor_data_my) {
  if (data->pin==_pin) return data->angle;
  if (data) return ServoMotor::read(data->next_cell);
  Serial.print("ERROR: no servo on pin ");
  Serial.println(_pin);
  return -1;
}

void ServoMotor_my_write(int pin, int angle) {
  if (angle==-1000) return;
  angle = map(angle,0,180,544,2400);
  digitalWrite(pin, 1);
  delayMicroseconds(angle);
  digitalWrite(pin, 0);
  delayMicroseconds(20000-angle);
}

void print_servo_data(servo_motor_data_cell* data = _servo_motor_data_my) {
  if (data) {
    Serial.print("pin: ");
    Serial.print(data->pin);
    Serial.print("; angle: ");
    Serial.print(data->angle);
    if (data->next_cell) Serial.print(";");
    else Serial.print(".");
    Serial.println();
    print_servo_data(data->next_cell);
  }
}

void ServoUpdate(servo_motor_data_cell* data = _servo_motor_data_my) {
  if (data) {
    ServoMotor_my_write(data->pin, data->angle);
    ServoUpdate(data->next_cell);
  }
}
