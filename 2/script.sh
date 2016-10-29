#!/bin/bash

echo "10^8, 1, dynamic, 100000, 804"
./first 100000000 1 2 100000 804

echo "10^8, 2, dynamic, 100000, 52"
./first 100000000 2 2 100000 52

echo "10^8, 4, dynamic, 100000, 605"
./first 100000000 4 2 100000 605

echo "10^8, 8, dynamic, 100000, 891"
./reduce 100000000 8 2 100000 891

echo "10^8, 16, dynamic, 100000, 1520"
./first 100000000 16 2 100000 1520

 exec 1>$PBS_O_WORKDIR/out  2>$PBS_O_WORKDIR/err