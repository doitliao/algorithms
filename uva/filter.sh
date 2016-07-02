#!/bin/bash

grep -A 1 com_onlinejudge $1 |awk '{if($8 != ""){print $8;}else{print $0;}}' |sed 's/&amp;/\&/g' |grep -v "\-" |awk -F '"' '{if($2 != ""){print $2;}else{print $0;}}'
