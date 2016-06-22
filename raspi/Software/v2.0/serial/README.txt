global.h        -----  存放全局变量跟宏定义  考虑放一些公用的头文件 #include comon.h



mavlinkParse.c  ------ 实现mavlink数据的解析并发送  目前考虑的接口函数有: 从串口获取一个字符
                       解析，然后通过调用udp接口函数发送出去。



udpinit.c
 / udpinit.h   ------  实现udp的初始化，接口函数 
                      int udpinit(char *target_addr,struct sockaddr_in *a, struct sockaddr_in *b) ;


 wiringSerial.c 
/ wiringSeria.h -----  串口驱动的封装