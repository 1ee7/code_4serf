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

char * target_ip="192.168.42.129";
//#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)
//uint64_t microsSinceEpoch();

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

  unsigned int temp = 0;
 //  float position[6] = {};
   uint8_t buf[BUFFER_LENGTH];
   int bytes_sent;
   uint16_t len;
   int i = 0;
   mavlink_message_t msg;
   mavlink_status_t mstatus;
   unsigned int temp = 0;
   int chan = 0;
   int udpsock=udpinit(target_ip,&gcAddr,&locAddr);
  //===============================

  if ((fd = serialOpen ("/dev/ttyAMA0", 57600)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  } 

 for(;;) 
 { 
    while (serialDataAvail (fd))
   {
       uint8_t byte=serialGetchar(fd);
       if(mavlink_parse_char(chan,byte,&msg,&mstatus))
       {
         len = mavlink_msg_to_send_buffer(buf, &msg);
         bytes_sent = sendto(udpsock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));

        /* bytes_sent = sendto(udpsock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
          printf("Received message with ID %d, sequence: %d from component %d of system %d \n", msg.msgid, msg.seq, msg.compid, msg.sysid);*/
        }
    }    
     
       memset(buf, 0, BUFFER_LENGTH);

       recsize = recvfrom(sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen);
    if (recsize > 0)
        {
           // Something received - print out all bytes and parse packet
           mavlink_message_t msg;
           mavlink_status_t status;
      
          printf("Bytes Received: %d\nDatagram: ", (int)recsize);
          for (i = 0; i < recsize; ++i)
           {
             temp = buf[i];
             serialPutchar   ( fd, (unsigned char)temp) ;
             printf("%02x ", (unsigned char)temp);
            /*     if (mavlink_parse_char(chan, buf[i], &msg, &status))
           {
              // Packet received
              printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
            }*/
          }
            memset(buf, 0, BUFFER_LENGTH);
         // printf("\n");
        }
     
       /*if(byte == 254)
       {
         mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
         len = mavlink_msg_to_send_buffer(buf, &msg);
         bytes_sent = sendto(udpsock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
       }*/

  
    }
 }

  return 0 ;
}
