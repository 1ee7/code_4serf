#!/bin/bash
ping -c 2 192.168.0.129 | grep ttl > /dev/null
echo $?
