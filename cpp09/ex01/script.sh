#!/usr/bin/env bash
list=(
	" 1 1 + "
	" 8 9 * 9 - 9 - 9 - 4 - 1 +"
	"1 1 1 1 + + + 2 4 * *" # 32
	"7 7 * 7 -"
	"1 2 * 2 / 2 * 2 4 - +"
)

for op in "${list[@]}"
do
	./RPN "$op"
done
