For reduce.c, there are 4 command line arguments. Arg1 is the length of the array, arg2 is the number of threads, arg3 will be the scheduling type,
and arg4 is the number of iterations if the schedule is dynamic.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o reduce reduce.c

Output from script.sh on Mamba:

10^8, 1, static, 1
Time: 9715145
Min: -407169435
10^8, 1, dynamic, 1000
Time: 9689065
Min: 0
10^8, 1, dynamic, 100000
Time: 9809734
Min: 0
10^8, 2, static, 1
Time: 42052800
Min: 0
10^8, 2, dynamic, 1000
Time: 42324291
Min: 0
10^8, 2, dynamic, 100000
Time: 45759540
Min: 16
10^8, 4, static, 1
Time: 85826847
Min: 0
10^8, 4, dynamic, 1000
Time: 83238516
Min: 0
10^8, 4, dynamic, 100000
Time: 83225950
Min: 0
10^8, 8, static, 1
Time: 109003977
Min: 0
10^8, 8, dynamic, 1000
Time: 109102538
Min: 0
10^8, 8, dynamic, 100000
Time: 108699803
Min: 0
10^8, 16, static, 1
Time: 104927447
Min: 0
10^8, 16, dynamic, 1000
Time: 105377069
Min: 0
10^8, 16, dynamic, 100000
Time: 104651485
Min: 0