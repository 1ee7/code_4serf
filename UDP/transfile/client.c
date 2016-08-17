/************************************************************************* 
 > File Name: client.c 
 > Author: SongLee 
 
 ************************************************************************/
#include <sys/types.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <netdb.h> 
#include <stdarg.h> 
#include <string.h> 
#include <fcntl.h>
//#include "./mavlink-custom/1.0/tx1control/mavlink.h"

#include <sys/stat.h>  
  
#define SERVER_PORT 14550 
#define SERVER_PORT_BIND 14550 
#define BUFFER_SIZE 256 
//#define FILE_NAME_MAX_SIZE 512 
//#define BUFFER_LENGTH 512 
//#define BUFFER_LENGTH 2041
unsigned long get_file_size(const char *);


typedef struct
{
   int sendId;
   int recvId;
   uint8_t StartFlag;
   uint8_t EndFlag;
   
   unsigned long UnitSize;
   unsigned long FileSize;
   unsigned long RecvSize;
 }  HeadReg;

typedef struct
{
       HeadReg headInfo;
       uint8_t buff[BUFFER_SIZE];
       uint8_t buff_recv[BUFFER_SIZE];
} DataReg;

typedef struct
{
    int  flag_start;
    int flag_end;
 } FlagReg;

int main() 
{ 
    DataReg PackData;
    FlagReg FlagMark;
    int LocalSendID=0;
    unsigned long LocalSendSize=0;
    const char *FilePath="./config.tar.gz";

    FILE *stream;
    int  numread, numwritten;

    ssize_t len;
    int bytes_sent;
   
    int temp;
    int i;
    ssize_t recsize;
    
    struct sockaddr_in server_addr; 
    struct sockaddr_in server_addr_bind; 
    bzero(&server_addr, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr("192.168.137.13"); //change the ip with your sever pc 
    server_addr.sin_port = htons(SERVER_PORT); 

    bzero(&server_addr_bind, sizeof(server_addr_bind)); 
    server_addr_bind.sin_family = AF_INET; 
    server_addr_bind.sin_addr.s_addr = INADDR_ANY; 
    server_addr_bind.sin_port = htons(SERVER_PORT_BIND); 
  
    socklen_t fromlen=sizeof(server_addr);
 /* create socket */
     int client_socket_fd = socket(AF_INET, SOCK_DGRAM, 0); 
    if(client_socket_fd < 0) 
    { 
        perror("Create Socket Failed:"); 
        exit(1); 
    } 
  
    if(-1 == bind(client_socket_fd,(struct sockaddr *)&server_addr_bind,sizeof(struct sockaddr)))
   { 
      perror("error bind failed");
      close(client_socket_fd);
      exit(EXIT_FAILURE);
   } 

    PackData.headInfo.FileSize= get_file_size(FilePath);
    //===================================================================
    if( (stream = fopen( "config.tar.gz", "r" )) == NULL )  // 文件读取
    {
      printf( "File could not be opened\n" );
	    exit(1);
    }

     printf("the file config.tar.gz is %d \n",PackData.headInfo.FileSize);
     FlagMark.flag_start= 0;
     PackData.headInfo.sendId=0;
	   PackData.headInfo.recvId=0;
	   PackData.headInfo.StartFlag=1;
	   PackData.headInfo.EndFlag=0;
	   PackData.headInfo.UnitSize=256;
     bzero(PackData.buff,BUFFER_SIZE);
     bzero(PackData.buff_recv,BUFFER_SIZE);

  while(1)
 {
   if(FlagMark.flag_start == 0) {
     bytes_sent = sendto(client_socket_fd,&(PackData), sizeof(PackData), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
     if((len = recvfrom(client_socket_fd, &(PackData) ,sizeof(PackData) , 0, (struct sockaddr*)&server_addr,&fromlen)) > 0) 
     {
	  //  printf("the len is %d \n",len);
       printf("statFlag  is %d\n",PackData.headInfo.StartFlag);
     }
     if(PackData.headInfo.StartFlag == 2)  
        FlagMark.flag_start=1;
    }
   //========================================= 
    if(FlagMark.flag_start == 1)  { 

     //if(PackData.headInfo.sendId == PackData.headInfo.recvId)
     if( LocalSendID == PackData.headInfo.recvId)
     {
     //初始化，发送包头
      /*bytes_sent = sendto(client_socket_fd,&(PackData), sizeof(PackData), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
      printf("sendId is %d\n",PackData.headInfo.sendId);
*/
      bzero(PackData.buff,BUFFER_SIZE);
 
      PackData.headInfo.UnitSize = fread( PackData.buff, sizeof( char ), BUFFER_SIZE, stream );

      LocalSendID++;
      PackData.headInfo.sendId=LocalSendID;
      LocalSendSize+= PackData.headInfo.UnitSize;

	    bytes_sent = sendto(client_socket_fd,&PackData, sizeof(PackData), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    /*  LocalSendID++;
      PackData.headInfo.sendId=LocalSendID;*/
    //  LocalSendSize+= PackData.headInfo.UnitSize;
         printf(" this the unitsize is %d,send bytes is %d,SendId is %d  \n",PackData.headInfo.UnitSize,LocalSendSize,PackData.headInfo.sendId);
         if((len = recvfrom(client_socket_fd, &(PackData.headInfo) ,sizeof(HeadReg) , 0, (struct sockaddr*)&server_addr,&fromlen)) > 0) 
        {
	         printf("recvId is %d\n",PackData.headInfo.recvId);
		       if (PackData.headInfo.EndFlag==1)
		       {
             printf("transfer over ,close the stream.\n");
		         fclose(stream);
             close(client_socket_fd); 
		         return 0;
		       }
        }
           sleep(1);
      }  /* end   if (LocalSendID == PackData.headInfo.recvId)  */
  }
  else
      printf("send again ! \n");
  } /* end while(1)*/
    
    
 
  fclose( stream );
  close(client_socket_fd); 
  printf("ternimate by you! \n");
  return 0; 
}

  
  unsigned long get_file_size(const char *path)  
  {  
     unsigned long filesize = -1;      
     struct stat statbuff;  
     if(stat(path, &statbuff) < 0){  
            return filesize;  
     }
     else
     {  
         filesize = statbuff.st_size;  
     }  
        return filesize;  
  }  
