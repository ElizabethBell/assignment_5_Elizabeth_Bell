#!/bin/bash

echo "1"
./strassen 1

echo "2"
./strassen 2

echo "4"
./strassen 4

echo "8"
./strassen 8

echo "16"
./strassen 16

 exec 1>$PBS_O_WORKDIR/out  2>$PBS_O_WORKDIR/err