#!/bin/bash
#
#nextodd.sh finds the next odd int after a given int
#
#usage: nextodd.sh int

nxtnum=$1
while [[ $(($nxtnum%2)) = 0 || $nxtnum = $1 ]]
do
	nxtnum=$(( $nxtnum + 1 ))
done

echo $nxtnum