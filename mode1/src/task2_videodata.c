#include "task2_videodata.h"

void task2_init()
{
    fd2 = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);    
    setsockopt(fd2, SOL_SOCKET, SO_RCVBUF, &len2, sizeof(len2));    
    memset(&addr, 0, sizeof(addr));    
    addr.nl_family = AF_NETLINK;    
    addr.nl_groups = RTNLGRP_LINK;    
    bind(fd2, (struct sockaddr*)&addr, sizeof(addr));    
}
    

    
int task2_videdata()    
{    
  for(;;){ 
    while ((retval = read(fd2, buf, BUFLEN)) > 0)    
    {    
        for (nh = (struct nlmsghdr *)buf; NLMSG_OK(nh, retval); nh = NLMSG_NEXT(nh, retval))    
        {    
            if (nh->nlmsg_type == NLMSG_DONE)    
                break;    
            else if (nh->nlmsg_type == NLMSG_ERROR)    
            {
		printf("erro when task2\n");
                return -1;    
             }
            else if (nh->nlmsg_type != RTM_NEWLINK)    
                continue;    
            ifinfo = NLMSG_DATA(nh);    
     //      printf("%u: %s", ifinfo->ifi_index,    
       //             (ifinfo->ifi_flags & IFF_LOWER_UP) ? "up" : "down" );    
            attr = (struct rtattr*)(((char*)nh) + NLMSG_SPACE(sizeof(*ifinfo)));    
            len2 = nh->nlmsg_len - NLMSG_SPACE(sizeof(*ifinfo));    
            for (; RTA_OK(attr, len2); attr = RTA_NEXT(attr, len2))    
            {    
                if (attr->rta_type == IFLA_IFNAME)    
                {
					if(strstr((char *)RTA_DATA(attr),"usb0")!=NULL)
					{
						if(ifinfo->ifi_flags & IFF_LOWER_UP)
						{
							if(flag==0){
								flag++;
								printf("usb0 is up\n");
								status=system("br1down");
				//				if(status < 0) printf("br1down is wrong \n");
								 status=system("br0up") ;
				//				 if(status < 0) printf("br0up is wrong \n");
							}
						}
						else flag=0;
					}
					
/*					if(strstr((char *)RTA_DATA(attr),"eth1")!=NULL)
					{
						if(ifinfo->ifi_flags & IFF_LOWER_UP)
						{
							if(flag1==0){
								flag1++;
								printf("eth1 is up\n");
								 status=system("br0down");
				//				 if(status < 0) printf("br0down is wrong \n");
								 status=system("br1up"); 
				//				 if(status < 0) printf("br1up is wrong \n");
							}
						}
						else flag1=0;
					}
*/
              //      printf(" %s", (char*)RTA_DATA(attr));    
                    break;    
                }    
            }    
//            printf("\n");    
            sleep(2);
        }    
    }    
 //    printf("debug task2\n");
//    task2_init();
    }
    return 0;    
}   
