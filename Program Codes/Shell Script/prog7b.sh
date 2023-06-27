#!/bin/bash/
val=0
echo "	1.Addition"
echo "	2.subtraction"
echo "	3.Multiplication"
echo "	4.Division"
echo "	= -> To show the result"
while [ 1 ] 
do
	if [ $val == 0 ]
	then
		echo -n "Enter the number 1 : "
		read val
	fi
	echo -n "Enter the operation choice no : "
	read op
	if [ ${op} == '=' ]
	then
		echo "The value of the expression : $val"
		break
		else
			echo -n "Enter the number : "
			read n3
			echo
			case $op in
				1)
				val=$((n3+val))
				;;
				2)
				val=$((val-n3))
				;;
				3)
				val=$((val*n3))
				;;
				4)
				val=$((val/n3))
				;;
			esac
			n3=0
	fi
	op=''
done
