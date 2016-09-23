
#include "task1_mavdata.h"
// #include "global.h"
#include "../lib/mavlink/1.0/common/mavlink.h"
#include "../lib/mavlink/1.0/mavlink_helpers.h"



int udpinit(char *target_addr,struct sockaddr_in *a, struct sockaddr_in *b)  //a---gcAddr   b---locAddr
{
   char toip[100];
   int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
 
  ssize_t recsize;
  socklen_t fromlen;  
  
  // Change the target ip if parameter was given
  strcpy(toip, target_addr);
  
  memset(b, 0, sizeof(*b));
  b->sin_family = AF_INET;
  b->sin_addr.s_addr = INADDR_ANY;
  b->sin_port = htons(14551);
  
  /* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */ 
  if (-1 == bind(sock,(struct sockaddr *)b, sizeof(struct sockaddr)))
    {
    perror("error bind failed");
    close(sock);
    exit(EXIT_FAILURE);
  //  return -1;
    } 
  
  /* Attempt to make it non blocking */
  if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    {
    fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
    close(sock);
    exit(EXIT_FAILURE);
   //  return -1;
    }
  
  
  memset(a, 0, sizeof(*a));
  a->sin_family = AF_INET;
  a->sin_addr.s_addr = inet_addr(toip);
  a->sin_port = htons(14550);
  return sock;  

}


void task1_MavData(mavlink_message_t mav_smesg, mavlink_status_t mav_sstat)
{
    int i;
    //=====================
      // mavlink_msg_heartbeat_pack(1, 200, &mav_smesg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
      //   uint16_t  len_debug= mavlink_msg_to_send_buffer(sendbuf, &mav_smesg);
      //      sendto(udpsock, sendbuf, len_debug, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    
//    printf("tgl debug task1 is runing\n");
    while (serialDataAvail (fd1))      
    {
         uint8_t byte=serialGetchar(fd1);
//         printf("tgl debug the char is %x \n",byte);
        // if(mavlink_parse_char(chan,byte,&mav_smesg,&mav_sstat))
          if(mavlink_parse_char(0,byte,&mav_smesg,&mav_sstat))
         {
           uint16_t  len = mavlink_msg_to_send_buffer(sendbuf, &mav_smesg);
           sendto(udpsock, sendbuf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));

         }
     }

      memset(sendbuf, 0, BUFFER_LENGTH); 
      int recsize = recvfrom(udpsock, (void *)recbuf, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen);
       
     if (recsize > 0)
      {
          for ( i = 0; i < recsize; ++i)
          {
        //     temp = recbuf[i];
             serialPutchar(fd1, (unsigned char)recbuf[i]) ;
          }

            memset(recbuf, 0, BUFFER_LENGTH);
       }

      usleep(100);

}
