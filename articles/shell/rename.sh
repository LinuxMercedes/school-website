#! /bin/bash

for file in *.sh; do
	echo "Copying $file to $file.bak"
	cp $file $file.bak
done
