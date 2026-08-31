#!/usr/bin/env bash
set -e

for (( i=0; $i<=100000; ++i ))
do

	for (( j=0; $j<=10; ++j ))
	do
		if ./PmergeMe $(shuf -r --head-count="$i" --input-range=1-1000000)
		then
			exit 20
		fi
	done
done
