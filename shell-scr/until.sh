#!/bin/bash
i=1
j=1 
ans=0
for i in {2..6..2}
do
	for j in {1..3}
	do
		echo $i*$j
		let ans=$i*$j
		echo $ans
	done
	if [ $i -eq 4 ]
	then
		break;
	fi
done
