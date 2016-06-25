#!/bin/bash

program=$1;
g++ -o $program -g -Wall $program.cc;
#g++ -o $program -g -Wall -lm -lcrypt -O2 -std=c++11 -pipe $program.cc;
./$program < $program.in
