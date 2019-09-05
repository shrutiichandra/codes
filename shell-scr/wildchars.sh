#!/bin/bash
echo "ls r*"
ls r*
echo "ls r?verseingrop.c*"
ls r?verseingrop.c*
echo "ls l[a-o]st*"
ls l[a-o]st
echo "??st*"
ls ??st*
echo "ls [amwp]*"
ls [amwp]*
echo "ls [amwp][ai]*"
ls [amwp][ai]*
echo "ls [amwp][ai]*s.*"
ls [amwp][ai]*s.*
echo "ls *-??-*"
ls *-??-aug
echo "ls [a-c]*-[0-3]*"
ls [a-c]*-[0-3]*
echo "ls [0-3]*-[0-3]*-[0-3]*"
ls [0-3]*-[0-3]*-[0-3]*
echo "ls [a-cp-r]*-[a-cp-r]*-[a-cp-r]*"
ls [a-cp-r]*-[a-cp-r]*-[a-cp-r]*
echo "ls [0-3a-cp-r]*-[!0-3]*-[a-cp-r0-3]*"
ls [0-3a-cp-r]*-[!0-3]*-[0-3a-cp-r]*



