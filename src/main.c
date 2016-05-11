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


 //  float position[6] = {};
   uint8_t buf[BUFFER_LENGTH];
   int bytes_sent;
   uint16_t len;
   int i = 0;
   mavlink_message_t msg;
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


     if (mavlink_parse_char(chan, byte, &msg))
      {
       printf("Received message with ID %d, sequence: %d from component %d of system %d", msg.msgid, msg.seq, msg.compid, msg.sysid);
      }
 
       if(byte == 254)
       {
         mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
         len = mavlink_msg_to_send_buffer(buf, &msg);
         bytes_sent = sendto(udpsock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
       }

  
    }
 }

  return 0 ;
}
