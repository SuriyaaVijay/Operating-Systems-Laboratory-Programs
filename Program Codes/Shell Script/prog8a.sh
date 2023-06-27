#!/bin/bash
arr=("hello" "lol" "roman" "12321" "toppot")
isPalindrome() {
        local s=$1
        local len=${#s}
        for (( i=0;i<len/2;i+=1 )); do
                if [[ ${s:i:1} != ${s:len-i-1:1} ]]; then
                        return 1 
                fi
        done
        return 0 # 
}
 
for word in "${arr[@]}"; 
do
        isPalindrome $word
        if [[ $? -eq 0 ]]; then
                echo $word
        fi
done
