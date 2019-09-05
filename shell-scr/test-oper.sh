#!/bin/bash
echo "0 means true 1 is false"
echo "11>2?"
[ 11 > 2 ]
echo $?
echo "11==11?"
[ 11 -eq 11 ]
echo $?
echo "11!=11?"
[ 11 -ne 11 ]
echo $?
echo "11>31?"
[ 11 -gt 31 ]
echo $?
echo "11<31?"
[ 11 -lt 31 ]
echo $?

a=4
[ $a -eq 3 ]&&echo hii!
[ $a -eq 3 ]||echo hii!









