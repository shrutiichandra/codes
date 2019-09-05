#!/bin/bash

case $# in
	0) echo "zero argument passed";;
	1) echo "one argument passed "$1;;
	2) echo "two arguments passed "$1,$2;;
	*) echo "more than 2 arguments passed "$*;;
esac