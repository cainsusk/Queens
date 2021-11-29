#!/bin/bash
#
# has_package.sh: checks if a given java file is in given java package
#
# Usage: has_package.sh java-file package-name

file=$1
package=$2

if [[ $file == "" ]]
then
	echo "Usage: has_package.sh java-file package-name">&2
	exit 2
fi
if [[ $package == *[0-9]* ]]
then 
	echo "$package is not a conventional Java package name">&2
	exit 2
fi
while read line 
do
	if  [[ $line == "package $package;"* ]]
	then
		echo "$file is in package $package"
		exit 0
	fi
done < $file
echo "package $package not found in $file">&2
exit 3


