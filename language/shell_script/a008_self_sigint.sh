handler() {
  echo handling SIGINT
}

trap handler SIGINT

echo terminating

kill -2 $$

echo last line
