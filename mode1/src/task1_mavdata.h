#ifndef TASK1_MAVDATA_H
#define TASK1_MAVDATA_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
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

#define BUFFER_LENGTH 2041
   extern const int fd1;
   extern struct sockaddr_in gcAddr;
   extern struct sockaddr_in locAddr;
   extern int udpsock;

   static uint8_t sendbuf[BUFFER_LENGTH];
   static uint8_t recbuf[BUFFER_LENGTH];
   static socklen_t fromlen;
  
//int chan=0;
#endif 
