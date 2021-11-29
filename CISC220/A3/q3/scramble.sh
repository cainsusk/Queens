#!/bin/bash
#
#scramble.sh scrambles a given string of characters according to the Fisher-Yates shuffling algorithim
#
#usage: scramble.sh string-of-characters

function to_array {
	declare -a arr
	str=$1
	for (( i = 0; i < ${#str}; i++ ))
	do
		arr+=(${str:i:1})
	done
	echo "${arr[@]}"
}

function to_string {
	arr=($@)
	echo $( printf '%s' "${arr[@]}" )
}

function rand {
	inrange=0
	until [[ inrange == 1 ]]
	do
		val=$(($RANDOM % $2 + $1))
		if [[ $val = $2 ]]
		then
			inrange=0
		else
			inrange=1
			echo $val
			exit
		fi
	done
}

function shuffle {
	arr=($@)
	for (( i=${#arr[@]}; i > 0; i-- ))
	do 	
		j=$(rand 0 $i)
		tmp=${arr[j]}
		arr[j]=${arr[i]}
		arr[i]=$tmp
	done
	echo ${arr[@]}
}

if [[ $# == 0 ]]
then 
	exit 0
else
	string=$1
	array=$(to_array $string); shuffled_array=$(shuffle $array); to_string $shuffled_array
fi 