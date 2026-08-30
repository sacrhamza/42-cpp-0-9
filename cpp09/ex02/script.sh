#!/usr/bin/env bash

while true
do
	./PmergeMe $(shuf --head-count=3 --input-range=1-10000)
done
