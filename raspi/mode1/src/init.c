#include <stdio.h>
#include <string.h>
#include <errno.h>
//=============== net ==========================
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
#include <inttypes.h> // For fixed-width uint8_t type
#include "global.h"
//===========================================================

#include "wiringSerial.h"
#include "init.h"
#include "global.h"



int init(char *ip,struct sockaddr_in *a, struct sockaddr_in *b)
{
    udpsock=udpinit(ip,a,b);

    //================read value from configure 
    int baud=atoi(baudrate);
    //sscanf(baud,"%d",baudrate);

    printf("baud is %d",baud);

   if ((fd1 = serialOpen ("/dev/ttyS0", baud)) < 0)
   {
     fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
     return 1 ;
   } 

   task2_init();

    //someelse will add following ...

   return 0;

}
