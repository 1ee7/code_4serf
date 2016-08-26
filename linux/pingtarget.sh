#!/bin/bash
ping -c 2 192.168.1.129 | grep ttl > /dev/null
echo $?


#--------------获取返回值的c代码
void task3_Ping()
{   
    char flag;
	int command_id;
    fp3=popen("../shell/pingtarget.sh","r");
    fgets(&flag,sizeof(&flag),fp3);   
    command_id=atoi(&flag);

}