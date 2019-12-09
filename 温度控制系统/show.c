#include"show.h"

char num=0;
u8 DisplayData[8];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
u8 code smgduan1[10]={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};

void delay(u16 i)
{
	while(i--);	
}


void datapros(int temp) 	 
{
      
   	float tp;  
	if(temp< 0)				//���¶�ֵΪ����
  	{
		DisplayData[0] = 0x40; 	  //   -
		//��Ϊ��ȡ���¶���ʵ���¶ȵĲ��룬���Լ�1����ȡ�����ԭ��
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
 
  	}
 	else
  	{			
		DisplayData[0] = 0x00;
		tp=temp;//��Ϊ���ݴ�����С�������Խ��¶ȸ���һ�������ͱ���
		//����¶���������ô����ô������ԭ����ǲ���������
		temp=tp*0.0625*100+0.5;	
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
	}
	DisplayData[1] = smgduan[temp % 10000 / 1000];
	DisplayData[2] = smgduan1[temp % 1000 / 100];
	DisplayData[3] = smgduan[temp %  100 / 10];
	DisplayData[4] = smgduan[temp %  10 / 1];

}



void DigDisplay()
{
	u8 i;
	u8 sum;
	sum=set_initnumber();
	DisplayData[6]=smgduan[sum/10];
	DisplayData[7]=smgduan[sum%10];
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			 case(0):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��0λ
			case(1):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��1λ
			case(2):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��2λ
			case(3):	
				LSA=0;LSB=0;LSC=1; break;//��ʾ��3λ
			case(4):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��4λ
			case(5):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��5λ
			case(6):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��6λ
			case(7):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��7λ	
		}
		P0=DisplayData[i];//��������
		delay(100); //���һ��ʱ��ɨ��	
		P0=0x00;//����
	}		
}











