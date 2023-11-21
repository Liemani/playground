handler() {
  kill $child_pid
}

trap handler SIGINT

./../../library/a003_infinite_printer/a.out &

child_pid=$!

wait $child_pid

echo terminating
