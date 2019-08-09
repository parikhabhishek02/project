/*
 * uart.h
 *
 *  Created on: Jul 5, 2019
 *      Author: root
 */

#ifndef UART_H_
#define UART_H_


#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // using the termios.h library
#include<string.h>
#include <vector>
#include<string.h>
using namespace std;


#define Uart01 "/dev/ttyO1"
#define Uart02 "/dev/ttyO2"
#define Uart03 "/dev/ttyO3"
#define Uart04 "/dev/ttyO4"
#define Uart05 "/dev/ttyO5"

class Uart
{

public:

//----------------------Api is used to initate the uart port----------------------


 int Init(char port[],int baudrate)
   {
	  if ((file = open(port, O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Failed to open the file.\n");
      return -1;
   }
   struct termios options;               //The termios structure is vital
   tcgetattr(file, &options);            //Sets the parameters associated with file

   // Set up the communications options:
   //   9600 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;    //ignore partity errors, CR -> newline
   tcflush(file, TCIFLUSH);             //discard file information not transmitted
   tcsetattr(file, TCSANOW, &options);  //changes occur immmediately
   return 1;
   }


 //---------Api is used to send data-----------------------------

 int send(char p[])
 {
	// printf("%d",strlen(p));
	if ((count = write(file,p,strlen(p)))<0){        //send the string
	       perror("Failed to write to the output\n");
	       return -1;
	    }
 return 1;
 }



 //-----------Api is used to recieve data-----------------------------


  int recieve(unsigned char *receive)
  {
	  //memset(&receive,0,sizeof(char));

	/* if ((count = read(file,(void*)receive,10))<0){   //receive the data
	      perror("Failed to read from the input\n");
	      return -1;
	   }
	   if (count==0)
		   printf("There was no data available to read!\n");
	   else {
	      printf("The following was read in [%d]: %s\n",count,receive);
	   }*/

	  if(read(file,&receive,100)>0)
	  {
		printf("data = %s\n",receive);

	  }

	return 1;
 }
private:
 int file, count;
 };

#endif /* UART_H_ */
