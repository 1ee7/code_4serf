/*******************************************************************************
 Copyright (C) 2010  Bryan Godbolt godbolt ( a t ) ualberta.ca
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 ****************************************************************************/
/*
 This program sends some data to qgroundcontrol using the mavlink protocol.  The sent packets
 cause qgroundcontrol to respond with heartbeats.  Any settings or custom commands sent from
 qgroundcontrol are printed by this program along with the heartbeats.
 
 
 I compiled this program sucessfully on Ubuntu 10.04 with the following command
 
 gcc -I ../../pixhawk/mavlink/include -o udp-server udp-server-test.c
 
 the rt library is needed for the clock_gettime on linux
 */
/* These headers are for QNX, but should all be standard on unix/linux */
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

#include "udpinit.h"

//#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

//uint64_t microsSinceEpoch();

int udpinit(char *target_addr,struct sockaddr_in *a, struct sockaddr_in *b)  //a---gcAddr   b---locAddr
{
   char target_ip[100];
   int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
 
  ssize_t recsize;
  socklen_t fromlen;  
  
  // Change the target ip if parameter was given
  strcpy(target_ip, target_addr);
  
  memset(b, 0, sizeof(*b));
  b->sin_family = AF_INET;
  b->sin_addr.s_addr = INADDR_ANY;
  b->sin_port = htons(14551);
  
  /* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */ 
  if (-1 == bind(sock,(struct sockaddr *)b, sizeof(struct sockaddr)))
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
  
  
  memset(a, 0, sizeof(*a));
  a->sin_family = AF_INET;
  a->sin_addr.s_addr = inet_addr(target_ip);
  a->sin_port = htons(14550);
  return sock;  

}