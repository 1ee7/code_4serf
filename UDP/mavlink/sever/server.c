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
#include "./mavlink-custom/1.0/tx1control/mavlink.h"
  
#define SERVER_PORT 14550
#define BUFFER_SIZE 1024 
//#define FILE_NAME_MAX_SIZE 512 
#define BUFFER_LENGTH 2041
#define ON  1
#define OFF 0


//================
mavlink_tx1_tracked_position_t tx1_track_position;

 static inline void handleMessage( mavlink_message_t* p_msg)
{
   switch(p_msg->msgid)
   {
     case MAVLINK_MSG_ID_TX1_TRACKED_POSITION:
          mavlink_msg_tx1_tracked_position_decode(p_msg, &tx1_track_position);
          printf("tracked is %d  the track posiotion is (%d,%d) (%d,%d)\n",
            tx1_track_position.tracked_positon,
            tx1_track_position.track_top_left_x,tx1_track_position.track_top_left_y,
            tx1_track_position.track_bottom_right_x,tx1_track_position.track_bottom_left_y);

          break;
      default :  //nothing to be done
         break;

   }
}
//============================

int main() 
{ 
  int bytes_sent;
  uint16_t len;
  ssize_t recsize;
  int i=0;
  unsigned int temp=0;

  unsigned int command_id=0;
  char cmd;
  uint8_t buff[BUFFER_LENGTH];
  uint8_t buf_send[BUFFER_LENGTH];

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
  

   while(1) 
  {  
     bzero(buff,  BUFFER_LENGTH);
    printf("tgl debug recvfrom\n");
    recsize = recvfrom(server_socket_fd, (void *)buff, BUFFER_LENGTH, 0, (struct sockaddr *)&client_addr, &client_addr_length);
    //  recsize = recvfrom(server_socket_fd, (void *)buff, BUFFER_LENGTH, 0, (struct sockaddr *)&client_addr, &fromelen);
    if (recsize > 0)
    {
      // Something received - print out all bytes and parse packet
      mavlink_message_t msg;
      mavlink_status_t status;
 
      printf("Bytes Received: %d\nDatagram: ", (int)recsize);
      for (i = 0; i < recsize; ++i)
      {
        temp = buff[i];
        printf("%02x ", (unsigned char)temp);
        if (mavlink_parse_char(MAVLINK_COMM_0, buff[i], &msg, &status))
        {
          printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
          handleMessage(&msg);//tgl add
          // Packet received
          if( msg.msgid == MAVLINK_MSG_ID_HEARTBEAT)
          {
               mavlink_message_t msg_send;
			   
               scanf("%d",&command_id); 
			   
               switch((unsigned int)command_id) {
                case 1 :   /* send  the system status  */
                 printf("start send the sys status to tx1...\n");
                   mavlink_msg_sys_status_pack(2, 201, &msg_send, 0, 0, 0, 500, 11000, 4, -1, 0, 0, 0, 0, 0, 0);
                   len = mavlink_msg_to_send_buffer(buf_send, &msg_send);
                   bytes_sent = sendto(server_socket_fd, buf_send, len, 0, (struct sockaddr*)&client_addr, sizeof (struct sockaddr_in));
                
                   break;
                case 2 :    /* send the control start video stream cmd  */
               
				 printf("start the videeo stream to tx1...\n");
                   mavlink_msg_tx1_control_stream_pack(2, 201, &msg_send,ON);
                   len = mavlink_msg_to_send_buffer(buf_send, &msg_send);
                   bytes_sent = sendto(server_socket_fd, buf_send, len, 0, (struct sockaddr*)&client_addr, sizeof (struct sockaddr_in));
                   break;
               case 3 :    /* send the control stop video stream cmd  */
                
				  printf("stop the videeo stream to tx1...\n");
                   mavlink_msg_tx1_control_stream_pack(2, 201, &msg_send,OFF);
                   len = mavlink_msg_to_send_buffer(buf_send, &msg_send);
                   bytes_sent = sendto(server_socket_fd, buf_send, len, 0, (struct sockaddr*)&client_addr, sizeof (struct sockaddr_in));
                   break;
              case 4 :   /* send the control position cmd  */
			     printf("send control position cmd to tx1...\n");
                  mavlink_msg_tx1_control_position_pack(2, 201, &msg_send,12,12,36,36);
                  len = mavlink_msg_to_send_buffer(buf_send, &msg_send);
                  bytes_sent = sendto(server_socket_fd, buf_send, len, 0, (struct sockaddr*)&client_addr, sizeof (struct sockaddr_in));
                  break;
              default:  /* help */
                   printf("\n************************** help *****************************\n");
                   printf("command: 1 -------   send the system status                   \n");
                   printf("command: 2 -------   send the video ON to control tx1         \n");
                   printf("command: 3 -------   send the video OFF to control tx1        \n");
                   printf("command: 4 -------   send the control posiotion to  tx1       \n");
                   printf("command: others--- SHOW HELP                                  \n");
                   printf("************************  help end ****************************\n");
                  break;
               }  /* end swith */
           }
          else 
          {
            printf("not reveived the heartbeat\n");
            break;
          }  /* end if(msg.id == MAVLINK_MSG_ID_HEARTBEAT) */
        } /* end if(mavlink_parse_char..) */
      }  /* end for() */
      printf("\n");
    }
    memset(buff, 0, BUFFER_LENGTH);
   
  } /* end while(1) */
    close(server_socket_fd); 
    return 0; 
} 

