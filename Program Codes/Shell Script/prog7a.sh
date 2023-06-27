#!/bin/bash/
val=0
flag=1
while [ 1 ]
do
op=""
echo -n "Enter the operation : "
read op
if [ $op == '|' ]
then
echo "$val"
break
else
if [ $flag -eq 1 ]
then
echo -n "Enter the number 1 : "
read n1
echo -n "Enter the  number 2 : "
read n2
case $op in
    "+")
    val=$((n1+n2))
    ;;
    "-")
    val=$((n1-n2))
    ;;
    "*")
    val=$((n1*n2))
    ;;
    "/")
    val=$((n1/n2))
    ;;
esac
n1=0
n2=0
flag=$((flag+1))
else
echo -n "Enter the number : "
read n3
case $op in
    "+")
    val=$((n1+val))
    ;;
    "-")
    val=$((val-n3))
    ;;
    "*")
    val=$((val*n3))
    ;;
    "/")
    val=$((val/n3))
    ;;
esac
n3=0
fi
fi
op=''
done
