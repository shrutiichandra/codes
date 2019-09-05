#!/bin/bash

[ -e variables.sh ]
echo "file exists: "$?
[ -r variables.sh ]
echo "file readable: "$?
[ -w variables.sh ]
echo "file writable: "$?
[ -d variables.sh ]
echo "file a directory: "$?
[ first.sh -nt variables.sh ]
echo "first.sh newer than variables.sh: "$?


