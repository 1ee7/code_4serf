/************************************************************************* 
 > File Name: server.c 
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
//#include "./mavlink-custom/1.0/tx1control/mavlink.h"
  
#define SERVER_PORT 14550
#define BUFFER_SIZE 256 

typedef struct
{
	int sendId;
	int recvId;
	uint8_t StartFlag;
	uint8_t EndFlag;
	
	unsigned long UnitSize;
	unsigned long FileSize;
	unsigned long RecvSize;
} HeadReg;


typedef struct
{
	HeadReg headInfo;
	uint8_t buff[BUFFER_SIZE];
	char buff_recv[BUFFER_SIZE];
} DataReg;

typedef struct
{
	int flag_start;
	int flag_end;
} FlagReg;

int main() 
{  
	FlagReg FlagMark;
   DataReg PackData;
   int LocalRecvID=0;
   unsigned long LocalRecvSize=0;
  // Data ClietPackData;
   ssize_t recsize;
   int i=0;
   int numwritten;
   FILE *stream;
   char list[30];
   //===============
   unsigned long receiedSize=0;
   //===============

  // uint8_t buff[BUFFER_SIZE];
  // uint8_t buf_send[BUFFER_SIZE];

    socklen_t fromelen;

    struct sockaddr_in client_addr; 
    socklen_t client_addr_length = sizeof(client_addr); 
  
 /* server ip */
    struct sockaddr_in server_addr; 
    bzero(&server_addr, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    server_addr.sin_port = htons(SERVER_PORT); 
  
/* create socket */
    int server_socket_fd = socket(AF_INET, SOCK_DGRAM, 0); 
    if(server_socket_fd == -1) 
   { 
     perror("Create Socket Failed:"); 
     exit(1); 
   } 
  
/* bind the sock with port */
    if(-1 == (bind(server_socket_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)))) 
   { 
     perror("Server Bind Failed:"); 
     exit(1); 
   } 

  /* Attempt to make it non blocking */
  if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    {
    fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
    close(sock);
    exit(EXIT_FAILURE);
   //  return -1;
    }


   
   if( (stream = fopen( "config.tar.gz","w")) == NULL )  // 如果读取无误
   {
	   printf("open error \n");
	   exit(-1);
   }
/* 变量初始化  */
   FlagMark.flag_end=0;
   FlagMark.flag_start=0;
   PackData.headInfo.recvId=0;
   PackData.headInfo.sendId=0;
   PackData.headInfo.StartFlag=0;
   PackData.headInfo.EndFlag=0;
   PackData.headInfo.UnitSize=256;
   bzero(PackData.buff,  BUFFER_SIZE);
   bzero(PackData.buff_recv,  BUFFER_SIZE);
   
     
   //recsize = recvfrom(server_socket_fd, (void *)PackData.headInfo.FileSize, sizeof(unsigned long), 0, (struct sockaddr *)&client_addr, &client_addr_length);
   //printf("the file size is %d\n",PackData.headInfo.FileSize);
   
   
   while(1) 
  {  
      bzero(PackData.buff,  BUFFER_SIZE);
      if(FlagMark.flag_start==0)  {
		
	  	 recsize = recvfrom(server_socket_fd, &PackData, sizeof(PackData), 0, (struct sockaddr *)&client_addr, &client_addr_length);
		   printf("startFlag is %d ;",PackData.headInfo.StartFlag);
		   printf("the file will be received is %d\n",PackData.headInfo.FileSize);
		   if(PackData.headInfo.StartFlag==1)
		  {
			   PackData.headInfo.StartFlag =2;
			   sendto(server_socket_fd, &PackData, sizeof(PackData), 0, (struct sockaddr*)&client_addr, client_addr_length); 
			   FlagMark.flag_start =1;
		  }
	}
	
	if(FlagMark.flag_start==1)
	{    
        printf("tgl debug recvfrom\n");
    
       if(LocalRecvID == (PackData.headInfo.sendId))
      {
   		
		    recsize = recvfrom(server_socket_fd, &PackData, sizeof(PackData), 0, (struct sockaddr *)&client_addr, &client_addr_length);
		
        if (recsize > 0)
        {
		
		     printf("Bytes Received: %d  Datagram:  UnitSize is %d  , sendId is %d\n", (int)recsize,PackData.headInfo.UnitSize,PackData.headInfo.sendId);
		 
			   numwritten =  fwrite( (char *)PackData.buff, sizeof( char ), PackData.headInfo.UnitSize, stream );
			   printf( "Wrote %d items\n", numwritten );
			   LocalRecvID++;
			   PackData.headInfo.recvId=LocalRecvID;
			   LocalRecvSize += PackData.headInfo.UnitSize;
		
			   printf("receied size is %d \n",LocalRecvSize);
		     if(LocalRecvSize >= PackData.headInfo.FileSize) 
			   {
				    PackData.headInfo.EndFlag=1;
				    FlagMark.flag_end=1;
			   }
			   else
				   PackData.headInfo.EndFlag=0;
						 
			   sendto(server_socket_fd, &(PackData), sizeof(PackData), 0, (struct sockaddr*)&client_addr, client_addr_length);
			   printf("server recvId is %d\n",PackData.headInfo.recvId);
			   if(FlagMark.flag_end == 1 && PackData.headInfo.EndFlag == 1)
			   {
				   printf("transfer done\n");
				   fclose( stream );
           close(server_socket_fd); 
				   return 0; 
				  }
			 
		     sleep(1);
		
	     }
	 
     }  
     else
     {  
       	// fclose( stream );
        printf("recv again  \n");
     }
  }
   // memset(buff, 0, BUFFER_SIZE);
  printf("recv again  \n");
  } /* end while(1) */
     printf("transfer done\n");
     fclose( stream );
    close(server_socket_fd); 
    return 0; 
} 

