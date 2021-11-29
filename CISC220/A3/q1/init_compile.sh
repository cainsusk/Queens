#!/bin/bash
#
#init_compile takes a java package name and finds its corresponding
#file within the $CWD and places it in a dir. heirarchy mirroring th package name
#
#usage: innit_compile.sh package-name

pkgname=$1
if [[ $# > 0 ]]
then
	javafiles=$(find . -maxdepth 1 -type f -regex '.*\.java$' -print | sort)
	file=$(grep -E "$pkgname" $javafiles | cut -d : -f 1)
	if [[ !(-n $file) ]]
	then
		echo "$(echo $pkgname | rev | cut -d '.' -f 1 | rev).java missing in current directory">&2
		exit 2
	fi
	dirpath=$(echo src/$pkgname | tr '.' '/')
	dirpath=${dirpath%/*}
	mkdir -p $dirpath
	mv $file $dirpath
else
	echo "usage: innit_compile.sh package-name">&2
	exit 1
fi 