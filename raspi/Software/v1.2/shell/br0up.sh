#!/bin/bash
 brctl addbr br0
 brctl addif br0 eth1
 brctl addif br0 usb0
 ifconfig br0 192.168.42.122 netmask 255.255.255.0 up