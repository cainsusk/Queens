#!/bin/bash
#
# bad_dirs.sh: List incorrectly named directories

# list directories with spaces
spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]] 
then
  echo "Filenames with spaces:"
  echo "$spaces"
fi

echo # for newline
unusual=$(ls | cut -d / -f 2 | grep -E '.*[^_[:blank:][:alnum:]\-].*' | sort | sed 's/^/.\//')
if [[ -n $unusual ]]
then 
	echo "Filenames with unusual characters:"
	echo "$unusual"
fi

echo # for newline
seperation=$(ls | cut -d / -f 2 | grep -E '.*[[:lower:]][[:upper:]][[:lower:]].*' | sort | sed 's/^/.\//')
if [[ -n $seperation ]]
then
	echo "Filenames that might have incorrectly separated names:"
	echo "$seperation"
fi

echo # for newline
rename=$(echo "$spaces" "$unusual" | sort | cut -d / -f 2 | cut -d / -f 2 | uniq | sed 's/^/.\//') 
if [[ -n $rename ]]
then 
	echo "Directories that should be renamed:"
	echo "$rename"
else
	echo 'none'
fi 