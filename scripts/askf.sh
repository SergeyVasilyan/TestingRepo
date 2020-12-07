#!/bin/bash
echo -n  "Do you wish to save string to file(y/n)? "
read answer

if [ "$answer" != "${answer#[Yy]}" ] ;then 
    echo $str > $filename
    echo -n "Do you wish to output file(y/n)? "
    read answer1

if  [[ "$answer1" == "y" ]] || [[  "$answer1" == "Y" ]] ; then
         cat $filename
fi

elif [ "$answer" != "${answer#[Nn]}" ] ; then
    exit 1
else
    echo "You are brought out the wrong letter:" $answer
    exit 1
fi

