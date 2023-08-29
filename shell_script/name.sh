#!/bin/bash

filepath=$0
dirname=$(dirname $filepath)
basename=$(basename $filepath)
filename="${basename%.*}"
extension="${basename##*.}"

echo path = $path
echo dirname = $dirname
echo basename = $basename
echo filename = $filename
echo extension = $extension
