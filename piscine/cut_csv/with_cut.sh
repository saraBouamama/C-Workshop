#!/bin/sh

i=0
if [ "$#" -ne 2 ]; then
    exit 1
fi


while read line
do
      i=$((i+1))
      if [ "$i" -eq "$2" ]; then
          word1=$(echo  "$line" |cut -d ";" -f 2)
          word2=$(echo "$line" |cut -d ";" -f 3)
          echo "$word1 is $word2"

      fi
done <  "$1"
