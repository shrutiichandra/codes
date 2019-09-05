#!/bin/bash
x=5
echo $x
export Y='Hello'
echo $Y
echo x{1,2,3}y
echo x{1..3}z
echo $(pwd)
echo `pwd`
ps;ls;finger #multiple commands

a=4
b=6
echo $((a+=b))
#or,
let c=$a+$b
echo $c
expr $c + $b
expr $c / 2
expr $c \> $a #requires escaping >
#x is local, y is env var
#make a child
#bash
#echo $x
#echo $Y