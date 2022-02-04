#C:\Users\cain\Documents\GitHub\Queens\y2.2\CISC221\Notes\W1!/bin/bash
#
# a script for decoding vim snippets and returning a text file documenting how each of them work
#
# Usage: readsnip snipfile

file=$1

cat $file | grep -E "^snippet" > snippets.txt


while read line;
do
       echo "$line" | grep  
done < snippets.txt





