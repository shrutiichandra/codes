#!/bin/bash

for file in ~/Documents/codes/l* 
do
	echo -n $file
	if [ -f $file ]
	then
		echo “ is a file”
	elif [ -d $file ]
	then
		echo “ is a directory”
	else
		echo “ is special”
	fi
done