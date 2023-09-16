#!/bin/sh

dirname=$(dirname $0)
basename=$(basename $0)
filename=${basename%.*}
extension=${basename##*.}

echo $dirname
echo $basename
echo $filename
echo $extension
