    #include <linux/sockios.h>  
    #include <sys/socket.h>  
    #include <sys/ioctl.h>  
    #include <linux/if.h>  
    #include <string.h>  
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <unistd.h>  
      
    #define ETHTOOL_GLINK        0x0000000a /* Get link status (ethtool_value) */  
      
    typedef enum { IFSTATUS_UP, IFSTATUS_DOWN, IFSTATUS_ERR } interface_status_t;  
      
    typedef signed int u32;  
      
    /* for passing single values */  
    struct ethtool_value  
    {  
        u32    cmd;  
        u32    data;  
    };  
      
    interface_status_t interface_detect_beat_ethtool(int fd, char *iface)  
    {  
        struct ifreq ifr;  
        struct ethtool_value edata;  
         
        memset(&ifr, 0, sizeof(ifr));  
        strncpy(ifr.ifr_name, iface, sizeof(ifr.ifr_name)-1);  
      
        edata.cmd = ETHTOOL_GLINK;  
        ifr.ifr_data = (caddr_t) &edata;  
      
        if (ioctl(fd, SIOCETHTOOL, &ifr) == -1)  
        {  
            perror("ETHTOOL_GLINK failed ");  
            return IFSTATUS_ERR;  
        }  
      
        return edata.data ? IFSTATUS_UP : IFSTATUS_DOWN;  
    }  
      
    int main (int argc, char *argv[])  
    {  
        FILE *fp;  
        interface_status_t status;  
        char buf[512] = {'\0'};  
        char hw_name[10] = {'\0'};  
        char *token = NULL;  
      
        /* 获取网卡名称 */  
        if ((fp = fopen("/proc/net/dev", "r")) != NULL)  
        {  
            while (fgets(buf, sizeof(buf), fp) != NULL)  
            {  
                if(strstr(buf, "eth") != NULL)  
                {         
                    token = strtok(buf, ":");  
                    while (*token == ' ') ++token;  
                    strncpy(hw_name, token, strlen(token));  
                }  
            }  
        }  
        fclose(fp);  
    //方法一：查看一个文件文件，相对来说比较简单  
    #if 1  
        char carrier_path[512] = {'\0'};  
          
        memset(buf, 0, sizeof(buf));   
        snprintf(carrier_path, sizeof(carrier_path), "/sys/class/net/%s/carrier", hw_name);  
        if ((fp = fopen(carrier_path, "r")) != NULL)  
        {  
            while (fgets(buf, sizeof(buf), fp) != NULL)  
            {  
                if (buf[0] == '0')  
                {  
                    status = IFSTATUS_DOWN;  
                }  
                else  
                {  
                    status = IFSTATUS_UP;  
                }  
            }  
        }  
        else  
        {  
            perror("Open carrier ");  
        }  
        fclose(fp);  
    #endif  
      
    //方法二：用函数吧！有点复杂，但是也是一种有效的办法  
    #if 1  
        int fd;  
          
        if((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)  
        {  
            perror("socket ");  
            exit(0);  
        }  
        status = interface_detect_beat_ethtool(fd, hw_name);  
        close(fd);  
    #endif  
      
        switch (status)  
        {  
            case IFSTATUS_UP:  
                printf("%s : link up\n", hw_name);  
                break;  
              
            case IFSTATUS_DOWN:  
                printf("%s : link down\n", hw_name);  
                break;  
              
            default:  
                printf("Detect Error\n");  
                break;  
        }  
      
        return 0;  
    }  