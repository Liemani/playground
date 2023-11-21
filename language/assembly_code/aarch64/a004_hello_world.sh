as a004_hello_world.s -o a004_hello_world.o
ld a004_hello_world.o -o a004_hello_world -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch arm64
