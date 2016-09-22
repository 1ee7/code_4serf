#ifndef TASK2_VIDEODATA_H
#define TASK2_VIDEODATA_H

 #include <linux/sockios.h>  
    #include <sys/socket.h>  
    #include <sys/ioctl.h>  
    #include <linux/if.h>  
    #include <string.h>  
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <unistd.h>  
      
    #define ETHTOOL_GLINK        0x0000000a /* Get link status (ethtool_value) */  

    #define ETH0_UP 1
    #define USB0_UP 2
    #define NOT_LINK 3

    #define IFSTATUS_UP 0
    #define IFSTATUS_DOWN 1
      
    typedef signed int u32;  

  // const unsigned  int ETH0_UP=2;
  // const unsigned int USB0_UP=3;
  // const unsigned int NOT_LINK=4;
 
        FILE *fp0_task2;  
        FILE *fp1_task2;  
//        interface_status_t status;  
        char buf_task2[512] = {'\0'};  
        char buf0_task2[512] = {'\0'};  
      //  char hw_name[10] = {'\0'};       char buf_task2[512] = {'\0'};   
      //  char *token = NULL;  

       char carrier_path[512] = {'\0'};  
 // ==========
    int FlagEth0Uped=0;
    int FlagUsb0Uped=0;
      
    /* for passing single values */  
    struct ethtool_value  
    {  
        u32    cmd;  
        u32    data;  
    };  

      unsigned  int flag_eth0=0xcc;
      unsigned int  flag_usb0=0xcc;
      unsigned int flag_network;

#endif
