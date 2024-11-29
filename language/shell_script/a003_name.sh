#!/bin/sh

dirname=$(dirname $0)
basename=$(basename $0)
fileName=${basename%.*}
extension=${basename##*.}

echo dirname = $dirname
echo basename = $basename
echo fileName = $fileName
echo extension = $extension
