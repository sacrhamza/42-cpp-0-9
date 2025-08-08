#!/bin/bash

for direcotry in cpp0*
do
	for subdirectory in ${direcotry}/ex0*
	do
		make -f ${subdirectory}/Makefile 2> log.log
		cat log.log
	done
done
