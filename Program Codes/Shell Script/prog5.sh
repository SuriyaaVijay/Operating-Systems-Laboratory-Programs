#!/bin/bash
arr1=("1223" "2134" "45" "56")
arr2=("1223" "2134" "45" "56")
i=0
f=0
while [ $f -ne 0 ]
do
    if [ $arr1[$i] -eq $arr2[$i] ]
    then
        i=$i+1
        continue
    else
        f=1
        break
    fi
done
if [ $f -eq 0 ]
then
    echo "Equal"
else
    echo "Not Equal"
fi
exit

