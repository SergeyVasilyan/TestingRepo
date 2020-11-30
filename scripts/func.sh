#!/bin/bash
  function sum {
 echo "$(( $1 + $2 ))" 
}
  function main {
if [[ ! $# == 2 ]]; then
    echo "invalid number of arguments" 
elif ! [[ $1 =~ ^[0-9]+$ ]];  then
   echo "your first argument is a latter"   
elif ! [[ $2 =~ ^[0-9]+$ ]];  then
   echo "your second argument is a latter"   
else 
    sum $1 $2 
fi
}
main $@


