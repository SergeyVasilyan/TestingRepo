#!/bin/bash

while true ; do

 df -t ext4 | awk '+$5 >=15 { print $1 "  " $5}' > f1
 cat f1
 sort -k 2nr f1 | head >f2
 while read line ; do echo "$line" | awk '{print $1}' ; done < f2 >f3
 while read line ; do ls -l "$line" ; done < f3

 sleep 360
  done
