#!/bin/bash

filename="sortfile"
export $filename
read string
strlenght=${#string}
for ((i = 0 ; i < $strlenght; i++)); do
     str_array+=("${string:i:1}")
done

s1=""
s2=""
s3=""
s4=""

for i in ${str_array[@]}; do 
    num=`echo "$i" | tr -d "\n" | od -An -t dC`
    if  [[ $num -ge 97 ]] && [[ $num -le 122 ]] ; then
        s1="${s1}$i"
    elif  [[ $num -ge 65 ]] && [[ $num -le 90 ]] ; then
        s2="${s2}$i"
    elif  [[ $num -ge 48 ]] && [[ $num -le 57 ]]; then
        s3="${s3}$i"
    else
        s4="${s4}$i"
    fi
done

export str="${s1}${s2}${s3}${s4}"

source  ./askf.sh
