#!/bin/bash

make
for i in `ls exec*.out`
do
	echo "Running $i"
	./$i
done
