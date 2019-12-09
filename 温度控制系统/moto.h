#ifndef _moto_h
#define _moto_h


#include "reg51.h"

sbit pwm=P3^0;
sbit AIN1=P3^1;
sbit AIN2=P3^2;




int pwm_control(int set_temp);



#endif