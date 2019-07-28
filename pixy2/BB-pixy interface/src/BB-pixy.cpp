#include <iostream>
#include"Pixy2BBB.h"
#include"uart.h"

using namespace std;

Uart Lpc_link;
Uart Bt_link;
Pixy2BBB pixy;


int x;
int y;
int signature;
int x_min=70;
int x_max=200;
int maxArea=0;
int minArea=0;
unsigned int width;
unsigned int height;
unsigned int area;
unsigned int newarea;
int i=0;


unsigned char bt_data[100];


int getpixydata()
{
	 uint16_t blocks;
	  blocks = pixy.ccc.getBlocks();  //receive data from pixy
	  sig = pixy.ccc.blocks[i].m_signature;    //get object's signature
	  x = pixy.ccc.blocks[i].m_x;                    //get x position
	  y = pixy.ccc.blocks[i].m_y;                    //get y position
	  width = pixy.ccc.blocks[i].m_width;            //get width
	  height = pixy.ccc.blocks[i].m_height;          //get height


	return 0;
}





int track(int tsignature)
{
	if(signature==tsignature)
	{

		newarea= width * height;

		if(x<x_min)
		{
			Lpc_link.send("L");
		}
		if(x>x_max)
		{
			Lpc_link.send("R");
		}
		else if(newarea<minArea)
		{
			Lpc_link.send("F");
		}
		else if (newarea>maxArea)
		{
			Lpc_link.send("B");
		}

	}

	else
	{
		Lpc_link.send("S");
	}






	return 0;


}


int main()
{

	unsigned char z[1];
	//lpc_link.Init(Uart01,115200);c
	Bt_link.Init(Uart04,115200);
	//memset(&bt_data,0,sizeof(char));

	while(1)
	{

		//cin>>z[1];
		//kBt_link.send("j");
		usleep(1000);
	if(	Bt_link.recieve(bt_data)==1){
		printf("data is %s\n",bt_data);}
	}
return 0;
}
