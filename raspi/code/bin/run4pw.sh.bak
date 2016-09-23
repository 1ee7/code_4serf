#! /bin/bash
# to add bridge shell into the Path

# to run main
dir=/home/pi/mode1/
if [ -x /home/pi/mode1/shell/br0up ]
then 
    echo that is ok
else
    sudo chmod 755 /home/pi/mode1/shell/*
fi

if [ -f /usr/bin/sub-br0up.sh -a -f /usr/bin/br0up ]

then 
    echo do not need copy
else
    sudo cp /home/pi/mode1/shell/* /usr/bin/
fi

run=/home/pi/mode1/src/main
if [ -x ${run} ]
then
	${run}
else 
	echo "can not run file"
     sudo chmod 755 ${run}
     ${run}
fi
