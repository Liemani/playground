#!/bin/bash

for (( i = 0 ; i < 50 ; i++ )) ; do
  ./test | tail -n 1 >> .temp
done
