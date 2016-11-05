#!/bin/bash

program=$1;
g++ -o $program -g -Wall $program.cc;
./$program < $program.in
