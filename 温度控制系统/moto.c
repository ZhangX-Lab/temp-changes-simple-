#include"moto.h"
#include "temp.h"




int pwm_control(int set_temp)
{
       int PWM;
	   int temp;
	   temp=Ds18b20ReadTemp()*0.0625;
	   if(set_temp<temp)
	   {
	   PWM=(temp-set_temp);
		}

		else  PWM=0;

	   return PWM;

}
	 







