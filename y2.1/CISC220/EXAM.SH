#!/bin/bash

if ! [ -r $1 ] | [ -r $2 ]
then
	echo "file not readable">&2
	exit 1
fi

if ! [ -f $1 ] | [ -f $2 ]
then
	echo "file doesnt exist">&2
	exit 2
fi

grep -Fxf $1 $2 > out2
