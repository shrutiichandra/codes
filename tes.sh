#!/bin/bash

sed -e  ' s/\[/\{/g' -e 's/\]/\}/g' -e s/\"/\'/g  sud.txt > sud2.txt
