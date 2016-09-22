
#include "task3_mavpddl.h"
// #include "global.h"
#include "../lib/mavlink/1.0/common/mavlink.h"
#include "../lib/mavlink/1.0/mavlink_helpers.h"

// //================
// mavlink_message_t mav_smesg;
// mavlink_status_t mav_sstat;


   static uint8_t sendbuf_task3[512];
   static  uint16_t status_pddl;
//============tgl


unsigned int task3_Ping(const char *path)
{
    fp3=popen(path,"r");
    fgets(&command_id_char,sizeof(&command_id_char),fp3);
    pclose(fp3);
//    printf("the value id_cahr is %c\n",command_id_char);
    return atoi(&command_id_char);
 //   printf("the value id is %d\n",command_id);

}

void task3_MavPack(mavlink_message_t* msg,uint8_t ind)
{
//mavlink_msg_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint32_t time_boot_ms, uint8_t ind, float value)
  mavlink_msg_debug_pack(250,100, msg, 0,  ind, 0);

}

 
void task3_SendSerial(const char *buf, uint16_t len)
{
     int i;
     if (len > 0)
      {
          for ( i = 0; i < len; ++i)
          {
        //     temp = recbuf[i];
             serialPutchar(fd1, (unsigned char)buf[i]) ;
          }
           
       }
     else 
        printf("SendSerial is nothing\n");
 
}



void task3_MavPddl(mavlink_message_t mav_smesg, mavlink_status_t mav_sstat)
{

    if(task3_Ping(path[0]))
    {

      if(task3_Ping(path[1]))
      {
        if(task3_Ping(path[2]))
          command_id=0;
         else 
          command_id=3;
      }
      else command_id=2;
    }
  else command_id=1;
    //printf("command_id is %d\n ",command_id);

    switch((unsigned int)command_id) {
      case 0:
     //       printf(" not linked to pddl\n");
           task3_MavPack(&mav_smesg,128); //1000 0000
           status_pddl=128;
           break;
      case 1:   /* send  the system status  */        
         
     //      printf(" linked with camera \n");       
           task3_MavPack(&mav_smesg,240); //1111 0000      
           status_pddl=240;     
           break;
      case 2:   /* send  the system status  */        
         
       //    printf(" linked with master \n");       
           task3_MavPack(&mav_smesg,176); //1011 0000          
           status_pddl=176;
            break;
      case 3:   /* send  the system status  */        
        
      //     printf(" linked with slave\n");       
           task3_MavPack(&mav_smesg,144); //1001 0000           
           status_pddl=144;
            break;

      default:
              //nothing
          status_pddl=0;
          printf("nothing to be done\n");
          break;
        }

          
       len_task3 = mavlink_msg_to_send_buffer(send_Task3_MavBuf,&mav_smesg);
      task3_SendSerial(send_Task3_MavBuf,len_task3);

      //===============
   // static inline uint16_t mavlink_msg_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint32_t time_boot_ms, uint8_t ind, float value)

     mavlink_msg_debug_pack(250,100, &mav_smesg, 0, status_pddl, 0);
      
      len_task3 = mavlink_msg_to_send_buffer(sendbuf_task3, &mav_smesg);
     sendto(udpsock, sendbuf_task3, len_task3, 0, (struct sockaddr*)&gcAddr, sizeof (struct sockaddr_in));
      //==============
     //  task3_SendUdp(send_Task3_MavBuf,len_task3);
}


#if 0
void task3_Ping()
{
    fp3=popen("../shell/pingtarget.sh","r");
    fgets(&flag,sizeof(&flag),fp3);
    command_id=atoi(&flag);

}

void task3_MavPack(mavlink_message_t* msg,uint8_t ind)
{
//mavlink_msg_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint32_t time_boot_ms, uint8_t ind, float value)
  mavlink_msg_debug_pack(100,100, msg, 0,  ind, 0);

}

 
void task3_SendSerial(const char *buf, uint16_t len)
{
  int i;
     if (len > 0)
      {
          for ( i = 0; i < len; ++i)
          {
        //     temp = recbuf[i];
             serialPutchar(fd1, (unsigned char)buf[i]) ;
          }

           
       }
    else 
        printf("SendSerial is nothing\n");
 
}






void task3_MavPddl(mavlink_message_t mav_smesg, mavlink_status_t mav_sstat)
{
     
     task3_Ping();
printf("command_id is %d\n ");

   switch((unsigned int)command_id) {
      case 0:
           printf("send the linked with maseter mark to rc\n");
           task3_MavPack(&mav_smesg,7);
        //   len_task3 = mavlink_msg_to_send_buffer(send_Taks3_MavBuf,&mav_smesg);
        //   task3_SendSerial(send_Taks3_MavBuf,len_task3);
         //  mavlink_msg_debug_send(0, 0, 0, 0);
        
           break;
      case 1:   /* send  the system status  */
          printf("send the not link to master mark to rc\n");
           task3_MavPack(&mav_smesg,8);
 //         mavlink_msg_debug_send(0, 0, 1, 0);

           break;

      default:
              //nothing
          printf("nothing to be done\n");
          break;
        }

       len_task3 = mavlink_msg_to_send_buffer(send_Task3_MavBuf,&mav_smesg);
       task3_SendSerial(send_Task3_MavBuf,len_task3);
}






  #if 0


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



    int i;
    while (serialDataAvail (fd1))      
    {
         uint8_t byte=serialGetchar(fd1);
         //printf("tgl debug the char is %x \n",byte);
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
#endif
#endif
