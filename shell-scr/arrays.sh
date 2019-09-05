#!/bin/bash

ar=(1 2 abc) #0 index
echo ${ar[*]}
echo ${ar[2]}
ar[2]=shruti
echo ${ar[*]}