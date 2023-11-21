#!/bin/zsh

# echo truc: $truc

if [ $PWD = $HOME* ]; then
    echo true
else
    echo false
fi
