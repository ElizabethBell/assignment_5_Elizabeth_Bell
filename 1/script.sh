#!/bin/bash

echo "10^8, 1, static, 1"
./reduce 100000000 1 1 1

echo "10^8, 1, dynamic, 1000"
./reduce 100000000 1 2 1000

echo "10^8, 1, dynamic, 100000"
./reduce 100000000 1 2 100000

echo "10^8, 2, static, 1"
./reduce 100000000 2 1 1

echo "10^8, 2, dynamic, 1000"
./reduce 100000000 2 2 1000

echo "10^8, 2, dynamic, 100000"
./reduce 100000000 2 2 100000

echo "10^8, 4, static, 1"
./reduce 100000000 4 1 1

echo "10^8, 4, dynamic, 1000"
./reduce 100000000 4 2 1000

echo "10^8, 4, dynamic, 100000"
./reduce 100000000 4 2 100000

echo "10^8, 8, static, 1"
./reduce 100000000 8 1 1

echo "10^8, 8, dynamic, 1000"
./reduce 100000000 8 2 1000

echo "10^8, 8, dynamic, 100000"
./reduce 100000000 8 2 100000

echo "10^8, 16, static, 1"
./reduce 100000000 16 1 1

echo "10^8, 16, dynamic, 1000"
./reduce 100000000 16 2 1000

echo "10^8, 16, dynamic, 100000"
./reduce 100000000 16 2 100000

 exec 1>$PBS_O_WORKDIR/out  2>$PBS_O_WORKDIR/err