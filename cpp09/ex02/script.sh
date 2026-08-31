#!/usr/bin/env bash
set -e

for (( i=$1; $i<=100000; ++i ))
do
		echo "size = $i";
	for (( j=0; j<=4; ++j ))
	do
		nums=$(shuf -r --head-count="$i" --input-range=1-1000000)
		if ! ./PmergeMe $nums
		then
			echo "$nums"
			exit 20
		fi
	done
done
