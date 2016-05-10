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

#include <wiringPi.h>
#include <wiringSerial.h>


//============================================
#include "../lib/mavlink/1.0/common/mavlink.h"
#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)
uint64_t microsSinceEpoch();
//======================================
// struct sockaddr_in gcAddr; 

int udpinit(char *target_addr,struct sockaddr_in &a, struct sockaddr_in &b)  //a---gcAddr   b---locAddr
{
   char target_ip[100];
   //===
  int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  //struct sockaddr_in gcAddr; 
 // struct sockaddr_in locAddr;
  //==s
 //===== 
  ssize_t recsize;
  socklen_t fromlen;
  //int bytes_sent;
 // mavlink_message_t msg;
 // uint16_t len;
  //int i = 0;
  //int success = 0;
  //unsigned int temp = 0;
  
  // Check if --help flag was used
 /* if ((argc == 2) && (strcmp(argv[1], help) == 0))
    {
    printf("\n");
    printf("\tUsage:\n\n");
    printf("\t");
    printf("%s", argv[0]);
    printf(" <ip address of QGroundControl>\n");
    printf("\tDefault for localhost: udp-server 127.0.0.1\n\n");
    exit(EXIT_FAILURE);
    }*/
  
  
  // Change the target ip if parameter was given
  strcpy(target_ip, target_addr);
 /* if (argc == 2)
    {
    strcpy(target_ip, argv[1]);
    }*/
  
  
  memset(&b, 0, sizeof(b));
  b.sin_family = AF_INET;
  b.sin_addr.s_addr = INADDR_ANY;
  b.sin_port = htons(14551);
  
  /* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */ 
  if (-1 == bind(sock,(struct sockaddr *)&b, sizeof(struct sockaddr)))
    {
    perror("error bind failed");
    close(sock);
    exit(EXIT_FAILURE);
  //  return -1;
    } 
  
  /* Attempt to make it non blocking */
  if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    {
    fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
    close(sock);
    exit(EXIT_FAILURE);
   //  return -1;
    }
  
  
  memset(&a, 0, sizeof(a));
  a.sin_family = AF_INET;
  a.sin_addr.s_addr = inet_addr(target_ip);
  a.sin_port = htons(14550);


  return sock;
  

}




int main ()
{
  int fd ;
  int count ;
  unsigned int nextTime ;
  unsigned int rec;

  //========================
  struct sockaddr_in gcAddr; 
  struct sockaddr_in locAddr;
//struct sockaddr_in fromAddr;


   float position[6] = {};
   uint8_t buf[BUFFER_LENGTH];
   int bytes_sent;
   uint16_t len;
   int i = 0;
   mavlink_message_t msg;
   unsigned int temp = 0;

  int udpsock=udpinit("192.168.42.129",&gcAddr,&locAddr);
  //===============================

  if ((fd = serialOpen ("/dev/ttyAMA0", 57600)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }

  /*if (wiringPiSetup () == -1)
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }
*/
  //nextTime = millis () + 300 ;

 /* for (count = 0 ; count < 256 ; )
  {
    if (millis () > nextTime)
    {
      printf ("\nOut: %3d: ", count) ;
      fflush (stdout) ;
      serialPutchar (fd, count) ;
      nextTime += 300 ;
      ++count ;
    }*/

     for(;;) 
     { 

    // delay (3) ;

       while (serialDataAvail (fd))
       {
         rec=serialGetchar(fd);
         if( 254 == rec )
         {
          mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
          len = mavlink_msg_to_send_buffer(buf, &msg);
          bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
        }

//         printf (" -> %3x", serialGetchar (fd)) ;
 //        fflush (stdout) ;
       }
    }

  printf ("\n") ;
  return 0 ;
}