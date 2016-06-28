#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <signal.h>
//=======================================  network
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#if (defined __QNX__) | (defined __QNXNTO__)
/* QNX specific headers */
#include <unix.h>
#else
/* Linux / MacOS POSIX timer headers */
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>
#endif
//=======================================
#include <inttypes.h> // For fixed-width uint8_t type
//#include <wiringPi.h>

//============================================
#include "wiringSerial.h"
#include "../lib/mavlink/1.0/common/mavlink.h"
#include "../lib/mavlink/1.0/mavlink_helpers.h"

#include "config.h"

//=====================
// #include "global.h"
//========================

struct sockaddr_in gcAddr; 
struct sockaddr_in locAddr;
//char * target_ip="192.168.42.129";

//============config read
  char target_ip[16];
  char baudrate[8];

//=====================

mavlink_message_t sendmsg1;
mavlink_status_t sendstatus;
 
//==========================  

int main(int argc,char *argv[])
{
   pid_t pid;

//===get value from configure.ini
   GetProfileString("./configure.ini", "src", "ip", target_ip); 
   GetProfileString("./configure.ini", "src", "baud", baudrate); 

   printf("the target_ip is %s\n",target_ip);
   printf("the baudrate is %s\n",baudrate);


  if(argc > 1)
  {
    switch(atoi(argv[1]) {
      case 1:
          system("sed -i 's/\(baudrate=\)\S\S*/\1115200/' configure.ini' ");
          break;
      case 2:
           system("sed -i 's/\(baudrate=\)\S\S*/\57600/' configure.ini' ");
           break;
      default:
           break;
    } 
    printf("after the target_ip is %s\n",target_ip);
    printf("after the baudrate is %s\n",baudrate);
  }

//==================
   if(init(target_ip,&gcAddr,&locAddr) != 0 )
   {
	//TODO print some error info.
   	return 1;
   }
   //for fork child no hangup 
    if(signal(SIGCHLD,SIG_IGN) == SIG_ERR)
    {
        perror("signal error");
        exit(EXIT_FAILURE);
    }
//TODO fork maybe 	
  if((pid=fork())==-1)
  {
    perror("fork");  
    exit(EXIT_FAILURE);	  
  }

	
   if(pid==0)
    {
      for(;;)
      {
        task1_MavData(sendmsg1,sendstatus); 

      }
      exit(0);
    }  
   else
    {
     if(task2_videdata()!=0) //return 1;
//k        task2_videdata();
	     exit(1);
    }

	
}
