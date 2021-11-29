#!/bin/bash
#
# compile.sh: fake compilation of a Java source code file
#
# Usage: compile.sh java-filename

java="$1"

if (($# > 1))
then 
	echo "compile.sh can only take one argument" >&2
	exit 1
fi

if test -f $java 
then
	case "$java" in
	  Test1.java | Test2.java)
		echo "${java} compiled successfully"
		exit 0
		;;
	  Test3.java)
		echo "${java} does not compile" >&2
		echo "Test3.java: error: ';' expected" >&2
		exit 3
		;;
	  *)
		status=$(( $RANDOM % 2 ))
		if (( status != 0 )); then
		  echo "${java} does not compile" >&2
		fi
		exit $status
		;;
	esac
else
	echo "${java} does not exist" >&2
	exit 2
fi 