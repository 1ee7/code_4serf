#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int  main()
{

  int rssi;
  FILE *fp;

	
if((fp=fopen("/home/pi/project/raspi-code-v1.8/share/val.dat","w"))==NULL)
  exit(0);

  rssi=system("/home/pi/project/raspi-code-v1.8/shell/expect_ssh.sh > /dev/null");

  rssi=rssi>>8;
  fprintf(fp,"%d\n",rssi); 
  sleep(1);
//  printf("t the reuslt is %d  \n",rssi);
  fclose(fp);
//  sleep(1);
  return 0;
}
