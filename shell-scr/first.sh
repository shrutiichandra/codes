#!/bin/bash
#run on terminal as ./first.sh
echo "Hello World"
echo "HI"
var="3"
echo $var
echo "value of var: "${var}
export VAR="value" 
echo "VAR: "$VAR
echo "shell is: "${SHELL}
echo "path is: "${PATH}
echo "path is: "${HOME}
echo "user is: "${USER}
echo "ps1 is: "${PS1}
echo "oldpwd is: "${OLDPWD}
echo "process id of shell script: "$$

