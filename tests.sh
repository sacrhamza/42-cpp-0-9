#!/bin/bash

finished=(0 1 2 3 4 5)

for direcotry in "cpp0${finished[@]}"
do
	for subdirectory in ${direcotry}/ex0*
	do
		if make -C ${subdirectory} test #1> /dev/null 
		then
			echo "$subdirectory valid"
		else
			echo "$subdirectory not valid"
			exit 20
		fi
		# cat log.log
	done
done
