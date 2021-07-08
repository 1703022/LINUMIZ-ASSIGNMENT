#!/bin/bash
echo -e "enter file name:\c"
read "fname"
if [ -z "$fname" ]
then 
    exit
fi

exec < $fname

export fname
./scriptodd.sh

counter=0

while read line 
do
        isEvenNo=$( expr $counter % 2 )
 
	if [ $isEvenNo -ne 0 ] 
	then
        
	     echo $line
             source /path/to/scriptodda.sh
           
        fi
  
        (( counter++ ))
  
done
 


