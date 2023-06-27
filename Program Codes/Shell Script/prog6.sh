echo -n "Enter number of elements in array : "
read n
i=0
echo "Enter the elements : "
while [ $i -lt $n ]
do
    read arr[$i]
    ((i++))
done
j=0
for str in ${arr[@]};
do
    result=""
    while [ $str -gt 0 ];
    do
        result="$(($str%2))"$result
        str=$(($str/2))
    done
    bin[$j]=$result
    ((j++))
done
echo -n "Binary equivalents are : "
for str in ${bin[@]}
do
    echo $str
done
exit
