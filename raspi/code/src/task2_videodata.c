#include "task2_videodata.h"


void task2_init()
{

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

}   



//============task 3
// void task3_Ping1()
// {
//     fp3=popen("/home/pi/mode1/shell/pingtarget.sh","r");
//     fgets(&command_id_char,sizeof(&command_id_char),fp3);
// //    printf("the value id_cahr is %c\n",command_id_char);
//     command_id=atoi(&command_id_char);
//  //   printf("the value id is %d\n",command_id);

// }


// void task3_Ping2()
// {
//     fp3=popen("/home/pi/mode1/shell/pingMaster.sh","r");
//     fgets(&command_id_char,sizeof(&command_id_char),fp3);
// //    printf("the value id_cahr is %c\n",command_id_char);
//     command_id=atoi(&command_id_char);
//  //   printf("the value id is %d\n",command_id);

// }

// void task3_Ping3()
// {
//     fp3=popen("/home/pi/mode1/shell/pingSlave.sh","r");
//     fgets(&command_id_char,sizeof(&command_id_char),fp3);
// //    printf("the value id_cahr is %c\n",command_id_char);
//     command_id=atoi(&command_id_char);
//  //   printf("the value id is %d\n",command_id);

// }

// unsigned int task3_Ping(const char *path)
// {
//     fp3=popen(path,"r");
//     fgets(&command_id_char,sizeof(&command_id_char),fp3);
// //    printf("the value id_cahr is %c\n",command_id_char);
//     return atoi(&command_id_char);
//  //   printf("the value id is %d\n",command_id);

// }

// void task3_MavPack(mavlink_message_t* msg,uint8_t ind)
// {
// //mavlink_msg_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint32_t time_boot_ms, uint8_t ind, float value)
//   mavlink_msg_debug_pack(250,100, msg, 0,  ind, 0);

// }

 
// void task3_SendSerial(const char *buf, uint16_t len)
// {
//      int i;
//      if (len > 0)
//       {
//           for ( i = 0; i < len; ++i)
//           {
//         //     temp = recbuf[i];
//              serialPutchar(fd1, (unsigned char)buf[i]) ;
//           }
           
//        }
//      else 
//         printf("SendSerial is nothing\n");
 
// }



// void task3_MavPddl(mavlink_message_t mav_smesg, mavlink_status_t mav_sstat)
// {

//     if(task3_Ping(path[0]))
//     {

//       if(task3_Ping(path[1]))
//       {
//         if(task3_Ping(path[2]))
//           command_id=0;
//          else 
//           command_id=3;
//       }
//       else command_id=2;
//     }
//   else command_id=1;
//     //printf("command_id is %d\n ",command_id);

//     switch((unsigned int)command_id) {
//       case 0:
//             printf(" not linked to pddl\n");
//            task3_MavPack(&mav_smesg,128); //1000 0000
//            break;
//       case 1:   /* send  the system status  */        
         
//            printf(" linked with camera \n");       
//            task3_MavPack(&mav_smesg,192); //1100 0000           
//            break;
//       case 2:   /* send  the system status  */        
         
//            printf(" linked with master \n");       
//            task3_MavPack(&mav_smesg,224); //1110 0000           
//             break;
//       case 3:   /* send  the system status  */        
        
//            printf(" linked with slave\n");       
//            task3_MavPack(&mav_smesg,240); //1111 0000           
//             break;

//       default:
//               //nothing
//           printf("nothing to be done\n");
//           break;
//         }

          
//        len_task3 = mavlink_msg_to_send_buffer(send_Task3_MavBuf,&mav_smesg);
//        task3_SendSerial(send_Task3_MavBuf,len_task3);
// }