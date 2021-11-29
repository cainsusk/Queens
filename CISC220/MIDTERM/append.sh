#!/bin/bash
#
#append.sh
#
#usage: append.sh str-to-append file-to-append-to

chmod u+w $2

echo "$1" >> "$2" 

cat $2 