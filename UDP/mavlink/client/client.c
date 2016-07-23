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
#include<fcntl.h>
#include "./mavlink-custom/1.0/tx1control/mavlink.h"

  
#define SERVER_PORT 14550 
#define SERVER_PORT_BIND 14550 
#define BUFFER_SIZE 1024 
//#define FILE_NAME_MAX_SIZE 512 
//#define BUFFER_LENGTH 512 
#define BUFFER_LENGTH 2041

 mavlink_sys_status_t sys_status;
 mavlink_tx1_control_stream_t tx1_stream;
 mavlink_tx1_control_position_t control_position;
 static uint8_t flags_send_tracked=0;
 uint16_t recv_top_left_x=0, recv_top_left_y=0, recv_bottom_right_x=0, recv_bottom_left_y=0;
 
 
static inline void  handleMessage(mavlink_message_t* p_msg)
{
// printf("tgl debug \n");
  switch(p_msg->msgid)
  {
   case MAVLINK_MSG_ID_SYS_STATUS: 
        mavlink_msg_sys_status_decode(p_msg,&sys_status);
        printf("\nthe sys_status.voltage_battery is %d, sys_status.current_battery is %d,sys_status.drop_rate_comm is %d\n",sys_status.voltage_battery,sys_status.current_battery,sys_status.drop_rate_comm);
        break;
   case MAVLINK_MSG_ID_TX1_CONTROL_STREAM:
       mavlink_msg_tx1_control_stream_decode(p_msg,&tx1_stream);
      if((unsigned int)tx1_stream.stream_on_off == 1)
        printf("\nthe tx1: accept the cmd is :start the stream\n");
      if(tx1_stream.stream_on_off == 0)
        printf("\nthe tx1: accept the cmd is :stop the stream\n");
       break;
   case MAVLINK_MSG_ID_TX1_CONTROL_POSITION:
       mavlink_msg_tx1_control_position_decode(p_msg, &control_position);
       recv_top_left_x = control_position.top_left_x;
       recv_top_left_y = control_position.top_left_y;
       recv_bottom_right_x = control_position.bottom_right_x;
       recv_bottom_left_y = control_position.bottom_left_y;
       printf("\nreceived from server(qgc) the position is (%d,%d),(%d,%d) \n",control_position.top_left_x,control_position.top_left_y,
       control_position.bottom_right_x,control_position.bottom_left_y);  
       flags_send_tracked=0xcc;
      break;
     
   default: //nothing
       printf("nothing to be done \n");
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
    ssize_t recsize;
    char buffer_recv[BUFFER_LENGTH];
    socklen_t fromlen;
    mavlink_message_t recv_msg;
    mavlink_status_t recv_status;

 /* server ip */
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
/* Attemp to make it non blocking  */
    if(fcntl(client_socket_fd,F_SETFL,O_NONBLOCK | FASYNC) < 0)
    {
      fprintf(stderr,"error setting nonblocking: %s \n",strerror(errno));
      close(client_socket_fd);
      exit(EXIT_FAILURE);
    } 
  
   for(;;) 
   { 
 /* SEND MESSAGE */	 
    // Hearbeat message id
    bzero(buff,BUFFER_LENGTH);
    mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
    len = mavlink_msg_to_send_buffer(buff, &msg);
    bytes_sent = sendto(client_socket_fd, buff, len, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
   // Tracked position message id
    if(flags_send_tracked == 0xcc)
    {
      mavlink_msg_tx1_tracked_position_pack(1, 200 , &msg,recv_top_left_x, recv_top_left_y, recv_bottom_right_x, recv_bottom_left_y,1);
      len = mavlink_msg_to_send_buffer(buff, &msg);
      bytes_sent = sendto(client_socket_fd, buff, len, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    } 
    
 

 /*RECEIVE MESSAGE */
    
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
          handleMessage(&recv_msg);    
		  }
      }/* end for( i=0;i<recsize; ++i)  */
    }   
    sleep(1);
  }  /* end for(;;)  */
  close(client_socket_fd); 
  return 0; 
} /* end main*/
