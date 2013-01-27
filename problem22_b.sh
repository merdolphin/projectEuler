#!/bin/bash

## written by lina on Sun Jan 27 13:43:27 SGT 2013
## my brust-force way to solve problem 22.

for i in {A..Z}; do echo "s/$i/"; done | awk '{print $0,NR}'|sed 's/ //g'| sed 's/$/\/g/g' > dict

more names.txt  | tr "," "\n"  | sed 's/[""]//g' | awk -F '' '{for(i=1;i<=NF;i++){printf("%c ",$i)};printf("\n")}' | sort | sed -f dict  | awk '{a=0;for(i=1;i<=NF;i++){a+=$i}; print a;}' | awk '{print NR*$0}'  | awk 'BEGIN{sum=0}{sum+=$0}END{print sum}'
