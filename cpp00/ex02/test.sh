#!/bin/bash

IFS=$'\n'

log_lines=($(cat log.log | awk '{printf $2"\n"}'))
lines=($(cat file.log))
len="$(cat log.log | wc -l)"

for ((i=0; i < len; i++))
do
	if [[ "${log_lines[$i]}" !=  "${lines[$i]}" ]]
	then
		printf "line $i: diff: expect: ${log_lines[$i]}\n"
		printf "got: ${lines[$i]}\n"
		exit 1
	fi
done

printf "all is good!!\n";
