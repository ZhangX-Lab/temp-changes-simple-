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
  TH0=0xfc;	//��ʱ1ms
  TL0=0x18;
  ET0=1;
  EA=1;
  TR0=1;
}

void  main()
{
	 set_temp=set_initnumber();//����Ŀ���¶�
	 time0init();//��ʱ����ʼ��
     while(1)
	 {	    
	    PWM=pwm_control(set_temp);//����PWM���
	    temp0=Ds18b20ReadTemp();//ʵ���¶�
		  datapros(temp0);	 //���ݴ�����	
    	DigDisplay();//�������ʾ���� 
	  }

}
 void time0 ()interrupt 1			
{
	 
      
    TH0=0xfc;	//��ʱ1ms
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


