#!/bin/bash
int=10
while [ $int -gt 0]
do
   if read -p "Please tell me what you want to do : " command
   then
	   case "$command" in
	   br0)  ./br0up.sh
		      echo "br0up is done "   ;;
	   dbr0) ./br0down.sh
			  echo  "br0down is done" ;;
	   br1)  ./br1up.sh
			  echo "br1up is done"    ;;
	   dbr1) ./br1down.sh
			   echo  "br1down is down" ;;
	   exit)  echo "bye bye "
				exit 0;
	     *)    echo "$1 is not an option" ;;
		esac
	else
	    echo "some wrong with the read "
   fi
 done
 