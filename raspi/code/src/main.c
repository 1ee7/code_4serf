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
//=====================
// #include "global.h"
//========================

struct sockaddr_in gcAddr; 
struct sockaddr_in locAddr;
char * target_ip="192.168.42.129";

mavlink_message_t sendmsg1;
mavlink_status_t sendstatus1;
mavlink_message_t sendmsg2;
mavlink_status_t sendstatus2;
 
//==========================  

int main()
{
   pid_t pid;
   pid_t pid1;

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

     if((pid1=fork())==-1)
    {
      perror("fork");  
      exit(EXIT_FAILURE);   
    }
//进程1
    if(pid1 ==0)
    {

     printf("task 1 will be running \n");
      while(1)
      {
        task1_MavData(sendmsg1,sendstatus1); 
//        sleep(1);

      }
      printf("task 1 over \n");
      exit(0);
   }
//进程3
   else
   {
         printf("task 3 will be running \n");
      while(1)
      {
          task3_MavPddl(sendmsg2,sendstatus2);
           sleep(1);
      }
        printf("task 3 over \n");
         exit(0);

   }

 }

    //进程2
  else
   {
      printf("task 2 will be running \n");
      while(1){

       task2_videdata();
       task3_MavPddl(sendmsg2,sendstatus2);
       sleep(1);

    }
       printf("task 2 over \n");
         exit(0);
      
      

  }

}

