#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <fcntl.h>  
#include <sys/socket.h>  
#include <linux/netlink.h>  
#define UEVENT_BUFFER_SIZE 2048  
  
 int main(void)
 10 {
 11     int i;
 12     static int flag=0;
 13     static int flag1=0;
 14     struct sockaddr_nl client;
 15     struct timeval tv;
 16     int CppLive, rcvlen, ret;
 17     fd_set fds;
 18     int buffersize = 1024;
 19     CppLive = socket(AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
 20     memset(&client, 0, sizeof(client));
 21     client.nl_family = AF_NETLINK;
 22     client.nl_pid = getpid();
 23     client.nl_groups = 1; /* receive broadcast message*/
 24     setsockopt(CppLive, SOL_SOCKET, SO_RCVBUF, &buffersize, sizeof(buffersize))    ;
 25     bind(CppLive, (struct sockaddr*)&client, sizeof(client));
 26     while (1) {
 27         char buf[UEVENT_BUFFER_SIZE] = { 0 };
 28         FD_ZERO(&fds);
 29         FD_SET(CppLive, &fds);
 30         tv.tv_sec = 0;
 31         tv.tv_usec = 100 * 1000;
 32         ret = select(CppLive + 1, &fds, NULL, NULL, &tv);
 33         if(ret < 0)
 34             continue;
 35         if(!(ret > 0 && FD_ISSET(CppLive, &fds)))
 36             continue;
 37         /* receive data */
 38         rcvlen = recv(CppLive, &buf, sizeof(buf), 0);
 39         if (rcvlen > 0) {
 40             printf("%s\n", buf);
 41
 42 //      while(strstr(buf,"add")!= NULL)
 43         if(strstr(buf,"add")!=NULL )
 44         {
 45             if(strstr(buf,"usb0")!=NULL) flag=1;
 46         }
      if(strstr(buf,"remove")!=NULL)
 48         {
 49             if(strstr(buf,"usb0")!=NULL) flag=2;
 50         }
 51
 52         if (flag ==1 && flag1 !=1 )
 53         {
 54                 printf("\n ====================\n  usb0 is plugin \n");
 55                 system("/etc/init.d/networking restart");
 56                 flag1=1;
 57
 58         }
 59         if (flag ==2 && flag1 !=2)
 60         {
 61                  printf("\n ====================\n  usb0 not plugin \n");
 62                  flag1=2;
 63         }
 64        }
 65
 66 //              if(strstr(buf,"remvove")!=NULL) flag=0;
 67
 68 }
 69     close(CppLive);
 70     return 0;
 71 }
 72
 73
