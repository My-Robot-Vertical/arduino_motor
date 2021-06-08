#include <Arduino.h>
#pragma once

//#define motor_lib_version  1.0

struct servo_motor_data_cell //Структура одной яцейки "массива"
{
    //byte number;  // номер сервы (номер в "массиве")
    byte pin;     // номер пина
    int angle;    // угол этой сервы
    servo_motor_data_cell *next_cell; // указатель на следующий элемент "массива"
};

/*#ifdef kakaya_to_randomnaya_peremenaya_potomy_chto_kompilator_rygaetsya
#define kakaya_to_randomnaya_peremenaya_potomy_chto_kompilator_rygaetsya
extern servo_motor_data_cell *_servo_motor_data_my = 0;
#endif*/

//int sodhgjvn = 0;

//extern servo_motor_data_cell _servo_motor_data_my;
//void print_servo_data(servo_motor_data_cell* data = &_servo_motor_data_my);

extern servo_motor_data_cell *_servo_motor_data_my;

void print_servo_data(servo_motor_data_cell* data = _servo_motor_data_my);

void teeeeeeeeeeeeeeeest();

class ServoMotor {
  
  public:

    //#define AUTOMATIC  1
    
    ServoMotor(int pin, servo_motor_data_cell* &data = _servo_motor_data_my); 
    //void write(int angle, servo_motor_data_cell* data = _servo_motor_data_my); // 
    
  private:

    //void admin_write(int angle);
    byte _pin; // номер пина и идентификационный номер в servo_motor_data_cell
    void my_write(int angle);
    
};
