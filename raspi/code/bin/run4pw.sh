#! /bin/bash
# to add bridge shell into the Path

# to run main
dir=/home/pi/mode1/
<<<<<<< HEAD

for file in `ls $dir/shell`
do 
   echo $file
 #  if [ -x $file ]
 #  then
 #     echo that is execuable
 #   else
 #      sudo chmod 755 $file
 # fi
   

  if [ -f /usr/bin/$file ]
     then
        if [ $file -nt /usr/bin/$file ]
        then
           sudo cp $file /usr/bin/$file
        else
          echo  do not need copy
        fi
   else
       sudo cp $file /usr/bin/$file
 
   fi  
done    

##########################################
=======
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
>>>>>>> 0429d90f6be441e1edc9ec3f218817a101bd5619

run=/home/pi/mode1/src/main
if [ -x ${run} ]
then
<<<<<<< HEAD
	${run} 
else 
	echo "can not run file"
     sudo chmod 755 ${run}
     ${run} 
=======
	${run}
else 
	echo "can not run file"
>>>>>>> 0429d90f6be441e1edc9ec3f218817a101bd5619
fi
