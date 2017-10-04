#! /bin/bash
progname="program"

if [[ $# -ge 1 ]]; then
	progname=$1
fi

g++ *.cpp -o $progname

if [[ $? -eq 0 ]]; then
	./$progname
fi

