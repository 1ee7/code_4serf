#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int GetNetStat()
{
char buffer[BUFSIZ];
FILE *read_fp;
int chars_read;
int ret;
memset(buffer, 0, BUFSIZ);
read_fp = popen("ifconfig eth0 | grep RUNNING", "r");
if(read_fp != NULL)
{
chars_read = fread(buffer, sizeof(char), BUFSIZ-1, read_fp);
if(chars_read > 0)
ret = 1;
else
ret = 0;
}
pclose(read_fp);
return ret;
}
int main()
{
int i=0;
i = GetNetStat();
printf("\nNetStat=%d\n",i);
return 0;
}