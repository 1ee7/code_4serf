#ifndef TASK2_VIDEODATA_H
#define TASK2_VIDEODATA_H

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