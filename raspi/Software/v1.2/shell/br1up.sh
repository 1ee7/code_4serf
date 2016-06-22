#!/bin/bash
 brctl addbr br1
 brctl addif br1 eth1
 brctl addif br1 eth0
 ifconfig br1 192.168.42.122 netmask 255.255.255.0 up
