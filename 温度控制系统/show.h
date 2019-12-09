#ifndef  _show_h
#define _show_h


#include "reg51.h"
#include "import.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;


void delay(u16 i);
void datapros(int temp);
void DigDisplay();




#endif