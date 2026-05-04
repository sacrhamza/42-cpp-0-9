#!/usr/bin/env bash

set -e

make NAME="bin" re

expected="a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2"

output="$(./bin)"

if [[ "$output" != "$expected" ]]
then
	echo "\"$output\""
	echo "\"$expected\""
	exit 2
fi
