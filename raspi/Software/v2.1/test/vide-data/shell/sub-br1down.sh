#!/bin/bash
exec 2> /home/pi/log/erro.log
exec 1> /home/pi/log/info.log
function br1down
{
  ifconfig br1 down
  brctl delbr br1
  }

  if br1down
  then 
	  echo br1down has done
  else
	  echo br1down erro

  fi
