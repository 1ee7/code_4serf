#! /bin/bash
# to add bridge shell into the Path

# to run main
curdir=`pwd`
dir=`dirname ${curdir}`
run=${dir}/main
if [ -x ${run} ]
then
	${run}
else 
	echo "can not run file"
fi
unset curdir
unset dir
unset run
