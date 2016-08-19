#include "task2_videodata.h"
void task2_init()
{
/*
  struct ethtool_value edata;
  int fd2=-1,err=0;
  struct ifreq ifr;
  int flag=0,flag1=0;
*/

  memset(&ifr,0,sizeof(ifr));
  strcpy(ifr.ifr_name,"usb0");
  fd2=socket(AF_INET,SOCK_DGRAM,0);
  if(fd2<0)
  {
    perror("cannot get control socket");
  }
  edata.cmd = 0x0000000a;
  ifr.ifr_data = (caddr_t)&edata;
}

int task2_videdata()    
{    
  for(;;)
 { 
   err=ioctl(fd2,0x8946,&ifr);
   if (err == 0)
   {
      if(edata.data && flag == 0)
      {
          printf("usb0 is up \n");
          flag=1; flag1=0;
          status=system("br1down");
	  status=system("br0up") ;
      }
     else if (edata.data == 0 && flag1 == 0 )
      {
         printf("usb0 is not up \n");
         flag1=1; flag=0;
      }
   }
   else if(errno != EOPNOTSUPP && flag1 ==0 )
   {
      printf("cannot get link status\n");
      flag1=1; flag=0;
   }
   sleep(2);

  }
 return 0;
}    
