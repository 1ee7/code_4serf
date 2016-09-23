#ifndef TASK3_MAVPDDL_H
#define TASK3_MAVPDDL_H

#include <stdio.h>

#include <sys/types.h>
#include <stdlib.h>
#include "global.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "../lib/mavlink/1.0/common/mavlink.h"
#include "../lib/mavlink/1.0/mavlink_helpers.h"
// #include "task1_mavdata.h"

//=================tgl add
// #define   MAVLINK_SEND_UART_BYTES   task3_SendSerial;

// unsigned int command_id;
// char command_id_char;
// FILE *fp3;
// char flag;

unsigned int command_id;
char command_id_char;
FILE *fp3;

 #define BUFFER_LENGTH_TASK3 2041
 static uint8_t send_Task3_MavBuf[BUFFER_LENGTH_TASK3];
 uint16_t  len_task3;
 const char path[3][38]={
 	"/home/pi/mode1/shell/pingtarget.sh",
 	"/home/pi/mode1/shell/pingMaster.sh",
 	"/home/pi/mode1/shell/pingSlave.sh",
 };
#endif 
