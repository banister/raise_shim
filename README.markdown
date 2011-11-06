# Compiling

`gcc -Wall -O2 -fpic -shared -ldl -o raise_shim.so raise_shim.c`

# Running

`LD_PRELOAD=./raise_shim.so pry`
