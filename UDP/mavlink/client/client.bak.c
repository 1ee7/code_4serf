/************************************************************************* 
 > File Name: client.c 
 > Author: SongLee 
 ************************************************************************/
#include<sys/types.h> 
#include<sys/socket.h> 
#include<unistd.h> 
#include<netinet/in.h> 
#include<arpa/inet.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<netdb.h> 
#include<stdarg.h> 
#include<string.h> 
#include "./mavlink-custom/1.0/common/mavlink.h"

  
#define SERVER_PORT 14550 
#define SERVER_PORT_BIND 14550 
#define BUFFER_SIZE 1024 
//#define FILE_NAME_MAX_SIZE 512 
//#define BUFFER_LENGTH 512 
#define BUFFER_LENGTH 2041

static inline void  handleMessage(mavlink_message_t * p_msg,mavlink_sys_status_t* p_status)
{
  switch(p_msg->msgid)
  {
   case MAVLINK_MSG_ID_SYS_STATUS: 
        mavlink_msg_sys_status_decode(p_msg,p_status);
        printf("the sys_status.voltage_battery is %d, sys_status.current_battery is %d,sys_status.drop_rate_comm is %d/n",p_status->voltage_battery,p_status->current_battery,p_status->drop_rate_comm);
        break;
   default: //nothing
        break;
  }
  
}
int main() 
{ 
/* val for send */
    mavlink_message_t msg;
    uint16_t len;
    int bytes_sent;
    uint8_t buff[BUFFER_LENGTH];
    
/* val for receive */
    int temp;
    int i;
    mavlink_sys_status_t sys_status;
    ssize_t recsize;
    char buffer_recv[BUFFER_LENGTH];
    socklen_t fromlen;
    mavlink_message_t recv_msg;
    mavlink_status_t recv_status;

 /* 服务端地址 */
    struct sockaddr_in server_addr; 
    struct sockaddr_in server_addr_bind; 
    bzero(&server_addr, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr("192.168.137.13"); 
    server_addr.sin_port = htons(SERVER_PORT); 

    bzero(&server_addr_bind, sizeof(server_addr_bind)); 
    server_addr_bind.sin_family = AF_INET; 
    server_addr_bind.sin_addr.s_addr = INADDR_ANY; 
    server_addr_bind.sin_port = htons(SERVER_PORT_BIND); 
  
 /* 创建socket */
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

 for(;;) { 
 /* 输入文件名到缓冲区 */
/*
    char file_name[FILE_NAME_MAX_SIZE+1]; 
    bzero(file_name, FILE_NAME_MAX_SIZE+1); 
    printf("Please Input File Name On Server:\t"); 

    scanf("%s", file_name); 
  
    char buffer[BUFFER_SIZE]; 
    bzero(buffer, BUFFER_SIZE); 
    strncpy(buffer, file_name, strlen(file_name)>BUFFER_SIZE?BUFFER_SIZE:strlen(file_name)); 
*/ 
 /* 发送文件名 */

 /*   if(sendto(client_socket_fd, buffer, BUFFER_SIZE,0,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0) 
    { 
       perror("Send File Name Failed:"); 
       exit(1); 
    } 
*/
/* 发送Mavlinks信息 */
   // Hearbeat message id

    bzero(buff,BUFFER_LENGTH);
    mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
    len = mavlink_msg_to_send_buffer(buff, &msg);
    bytes_sent = sendto(client_socket_fd, buff, len, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("send after debug\n");
   
    
 //   sleep(1);

/*  接收信息 */
    
    bzero(buffer_recv,BUFFER_LENGTH);
    recsize=recvfrom(client_socket_fd,buffer_recv,BUFFER_LENGTH,0,(struct sockaddr*)&server_addr,&fromlen); 
    if(recsize>0)
    {
     printf("byte received: %d \n Datagram: ",(int)recsize);
     for( i=0;i<recsize; ++i)
     {
        temp=buffer_recv[i];
        printf("%02x ",(unsigned char)temp);
        if(mavlink_parse_char(0,buffer_recv[i],&recv_msg,&recv_status))
        {
          printf("\n Receive packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n",recv_msg.sysid,recv_msg.compid,recv_msg.len,recv_msg.msgid);
          handleMessage(&recv_msg,&sys_status);    
        }

     }

    }   
sleep(1);
}
     close(client_socket_fd); 
     return 0; 
} 
