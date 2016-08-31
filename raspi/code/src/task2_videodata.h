#ifndef TASK2_VIDEODATA_H
#define TASK2_VIDEODATA_H
#if 0
#include <sys/types.h>    
#include <sys/socket.h>    
#include <asm/types.h>    
#include <linux/netlink.h>    
#include <linux/rtnetlink.h>    
#include <unistd.h>  
#include <stdlib.h>    
#include <stdio.h>    
#include <sys/ioctl.h>    
#include <linux/if.h>    
#include <string.h>    
#define BUFLEN 20480    

    int fd2, retval,status;    
    char buf[BUFLEN] = {0};    
    int len2 = BUFLEN;    
    struct sockaddr_nl addr;    
    struct nlmsghdr *nh;    
    struct ifinfomsg *ifinfo;    
    struct rtattr *attr;
	static flag=0;
	static flag1=0;
   
 #endif
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <errno.h>
#include <net/if.h>

struct ethtool_value {
     __uint32_t cmd;
     __uint32_t data;
 };
struct ethtool_value edata;
int fd2=-1,err=0;
struct ifreq ifr;
int flag=0,flag1=0,status=0;
 
#endif
