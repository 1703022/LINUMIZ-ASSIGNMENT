#!/bin/bash

if [ -z "$fname" ]
then 
    exit
fi


exec < $fname



counter=0

while read line 
do
        isEvenNo=$( expr $counter % 2 )
 
	if [ $isEvenNo -ne 1 ] 
	then
	     echo $line
             source /path/to/scripteven.sh
        fi
  
        (( counter++ ))

done





