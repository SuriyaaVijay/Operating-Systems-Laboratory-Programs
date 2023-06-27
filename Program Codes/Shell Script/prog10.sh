#!/bin/bash/
declare -A arr
echo "Enter number of rows : "
read m
echo "Enter number of column : "
read n
for (( i=0;i<$m;i++ ))
	do
		for (( j=0;j<$n;j++ ))
		do
			echo "Enter the data about $(($i+1)) and $(($j+1)) : "
			read arr[$i,$j]
		done
	done
echo "The matrix : "	
for (( i=0;i<$m;i++ ))
	do
		for (( j=0;j<$n;j++ ))
		do
			echo -n "${arr[$i,$j]} "
		done
	echo "\n"
	done
for (( i=0;i<$m;i++ ))
	do
		for (( j=0;j<$n;j++ ))
		do
			if [ ${arr[$i,$j]} == 0 ]; then
				echo "The absent student Roll number is : $(($((i*$n))+$((j+1))))"
			fi
		done
	done
