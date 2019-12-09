#include"import.h"


int KeyValue[2];	//用来存放读取到的键值
int  b=2;
int  x=0;
int  change=2;
int code smgduanx[17]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
					0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};//显示0~F的值

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，i=1时，大约延时10us
*******************************************************************************/
void delayus(int i)
{
	while(i--);	
}

/*******************************************************************************
* 函 数 名         : KeyDown
* 函数功能		   : 检测有按键按下并读取键值
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void KeyDown(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//读取按键是否按下
	{
		delay(1000);//延时10ms进行消抖
		if(GPIO_KEY!=0x0f)//再次检测键盘是否按下
		{	
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue[x]=0;break;
				case(0X0b):	KeyValue[x]=1;break;
				case(0X0d): KeyValue[x]=2;break;
				case(0X0e):	KeyValue[x]=3;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue[x]=KeyValue[x];break;
				case(0Xb0):	KeyValue[x]=KeyValue[x]+4;break;
				case(0Xd0): KeyValue[x]=KeyValue[x]+8;break;
				case(0Xe0):	KeyValue[x]=KeyValue[x]+12;break;
			}
			 change--;
			 
		}
	}
	while((a<50)&&(GPIO_KEY!=0xf0))	 //检测按键松手检测
	{
		delayus(100);
		a++;
	}
}
int set_initnumber()
{	
   int sum;
   while(b>0)
   {
     while(b==change)
	 {
     KeyDown();
		delayus(500);
	 }
	 	b--;
	    x++;
	}
   sum=KeyValue[0]*10+KeyValue[1];
   return sum;


}




 
