#include"reg51.h"
#include "show.h"
#include"temp.h"
#include"moto.h"
#include"import.h"

u16 i,PWM;
int set_temp=15;
int temp0;  
void time0init()
{
  TMOD=0x01|TMOD;
  TH0=0xfc;	//定时1ms
  TL0=0x18;
  ET0=1;
  EA=1;
  TR0=1;
}

void  main()
{
	 set_temp=set_initnumber();//输入目标温度
	 time0init();//定时器初始化
     while(1)
	 {	    
	    PWM=pwm_control(set_temp);//控制PWM输出
	    temp0=Ds18b20ReadTemp();//实际温度
		  datapros(temp0);	 //数据处理函数	
    	DigDisplay();//数码管显示函数 
	  }

}
 void time0 ()interrupt 1			
{
	 
      
    TH0=0xfc;	//定时1ms
    TL0=0x18;
	i++;
     AIN1=1;
     AIN2=0;
    if(i>=10)
      i=0;
	if(i<PWM)
	  pwm=1;
	else
	  pwm=0;
	
}


