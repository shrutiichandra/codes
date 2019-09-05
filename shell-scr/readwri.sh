#!/bin/bash

#take input
echo "1. type something: "
read text
echo "1.you wrote: "$text

#timeout
echo "2. type again- (3s timeout) "
read -t 3 ans
echo " 2. you wrote: "$ans

#password
echo "3. type password- "
read -s pass
echo "3. you wrote: "$pass

#prompt
read -p "4. Again name: " pass2
echo "4. your name is: "$pass2

#default var reply
read -p "5. Age: " 
echo "5. age is: "$REPLY

#reading in array
echo "6. type a sentence- "
read -a array
echo "6. your sentence is: "${array[*]}
echo "6. index 2 is: "${array[2]}
