#ifndef GLOBAL_H
#define GLOBAL_H
#if 0

/*  define  */
#include "../lib/mavlink/1.0/common/mavlink.h"
#include "../lib/mavlink/1.0/mavlink_helpers.h"

#define BUFFER_LENGTH 2041

/*   var   */ 
extern int udpsock;
//extern char * target_ip;
//extern int fd;
//extern int chan;


/* function */
extern int init(char *ip,struct sockaddr_in *a, struct sockaddr_in *b);
extern int udpinit(char *target_addr,struct sockaddr_in *a, struct sockaddr_in *b) ; //a---gcAddr   b---locAddr
extern void task1_MavData(mavlink_message_t mav_smesg, mavlink_status_t mav_sstat);


#endif

 //extern const int fd1;
 extern int fd1;
 extern int udpsock;
 extern struct sockaddr_in gcAddr;
 extern struct sockaddr_in locAddr;
 extern int udpsock;
#endif
