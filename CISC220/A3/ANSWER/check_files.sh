#!/bin/bash
#
#chech_files.sh takes in a specfile of names and compares this list to the files in the $CWD. the files that rent present are listed in stderr
#
#usage: check_files.sh specfile

specfile=$1
missing=0
if [[ $# = 0 ]]
then
	echo "usage: check_files.sh specfile" >&2
	exit 1
elif [[ !(-f $specfile) || !(-r $specfile) ]]
then
	echo "$specfile is missing or could not be read">&2
	exit 2
else
	specnames=$(cat $specfile | grep -v -E '^#')
	specs=($specnames)
	cwd=$(ls)
	files=($cwd)
	for spec in ${specs[@]}
	do
		match=0
		for file in ${files[@]}
		do
			if [[ $spec == $file ]]
			then
				match=1
			fi
		done
		if [[ $match == 0 ]]
		then
			echo "$spec missing">&2
			missing=1
		fi		
	done
fi 
if (( missing = 1 ))
then 
	exit 3
fi 