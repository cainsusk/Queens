#!/bin/bash
#
# method_name.sh: attempts to extract the name of a public static method from a specified Java file.
#
# Usage: method_name.sh java-file

if [[ $1 == "" ]]
then 
	echo "Usage: method_name.sh java-file">&2
	exit 2
elif [[ $# > 1 ]]
then 
	echo "method_name.sh: only accepts one arument">&2
	exit 1
fi
answer=$( grep -E "public *static *void" $1 | awk '{print $4}' )
if [[ $answer == *"("* ]]
then 
	answer=$( echo $answer | cut -d "(" -f 1 )
fi
echo $answer
exit 0