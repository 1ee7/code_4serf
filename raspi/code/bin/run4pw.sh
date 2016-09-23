#! /bin/bash
# to add bridge shell into the Path

# to run main
dir=/home/pi/mode1/

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

run=/home/pi/mode1/src/main
if [ -x ${run} ]
then
	${run} 
else 
	echo "can not run file"
     sudo chmod 755 ${run}
     ${run} 
fi
