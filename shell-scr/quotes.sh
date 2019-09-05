#!/bin/bash

echo "no quotes:  "$SHELL
echo "double quotes: ""$SHELL"

echo "no quoutes: "/a/*b
echo "double quotes: ""/a/*b"

echo "no quotes: "$(pwd)
echo "double quotes: ""$(pwd)"

echo "single quotes: "'$SHELL'

echo "single quotes: "'/a/*b'


echo "single quotes: "'$(pwd)'

echo "backtick: "$`pwd`