#!/bin/bash

a=1;
while [ $a -lt 4 ];
	do
		expr $a \* 2 #mind the spacing
		let a=$a+1
	done