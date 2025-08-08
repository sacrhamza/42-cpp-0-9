#!/bin/bash

for direcotry in cpp0*
do
	for subdirectory in ${direcotry}/ex0*
	do
		make -f ${subdirectory}/Makefile
	done
done
