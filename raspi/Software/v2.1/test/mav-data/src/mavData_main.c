#include <stdio.h>
#include <string.h>
#include <errno.h>

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
//#include "mavlinkParse.h"

#include "udpinit.h"
#include "global.h"

//char * target_ip="192.168.42.129";
char * target_ip="192.168.137.122";
//#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)
//uint64_t microsSinceEpoch();
//
//msleep()
//===============================
int msleep(unsigned long milisec,int temp)
{
	struct timespec req={0},rem={0};
	time_t sec=(int)(milisec/1000);
	milisec=milisec-(sec*1000);
	req.tv_sec=sec;
	req.tv_nsec=milisec*1000000L;
	while(nanosleep(&req,&req)==-1 && errno==EINTR){
		continue;
	}
	return 1;
}



int main ()
{
  int fd ;
  int count ;

  //========================
  struct sockaddr_in gcAddr; 
  struct sockaddr_in locAddr;
   uint8_t sendbuf[BUFFER_LENGTH];
   uint8_t recbuf[BUFFER_LENGTH];
   int bytes_sent;
   ssize_t recsize;
   socklen_t fromlen;
   uint16_t len;
   int i = 0;
   mavlink_message_t sendmsg;
   mavlink_status_t sendstatus;
   // mavlink_message_t recmsg;
   // mavlink_status_t recstatus;
   unsigned int temp = 0;
  
   int udpsock=udpinit(target_ip,&gcAddr,&locAddr);
  //===============================

  if ((fd = serialOpen ("/dev/ttyAMA0", 57600)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }   
  while(1)
  {
     while (serialDataAvail (fd))
     {
	     uint8_t byte=serialGetchar(fd);
	     if(mavlink_parse_char(0,byte,&sendmsg,&sendstatus))
	       {
		 len = mavlink_msg_to_send_buffer(sendbuf, &sendmsg);
		 bytes_sent = sendto(udpsock, sendbuf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));

	       }
     }
     //sleep(1);
      memset(sendbuf, 0, BUFFER_LENGTH);
      
      recsize = recvfrom(udpsock, (void *)recbuf, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen);
      if (recsize > 0)
      {
        for (i = 0; i < recsize; ++i)
           {
             temp = recbuf[i];
             serialPutchar(fd, (unsigned char)temp) ;
            // printf("%02x ", (unsigned char)temp);
         
          }

           memset(recbuf, 0, BUFFER_LENGTH);
          
       }
      usleep(100);

  } 


  return 0 ;
}
