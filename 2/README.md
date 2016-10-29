For first.c, there are 3 command line arguments. Arg1 is the length of the array, arg2 is the number of threads, arg3 will be the scheduling type,
arg4 is the number of iterations if the schedule is dynamic, and arg5 is the number to search for.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o first first.c

All my data was compiled with a scheduling type of dynamic,100000, but if you want, you can still use static or a different number of iterations.

Output from script.sh on Mamba:

10^8, 1, dynamic, 100000, 804
Time: 9763462
Number 804 found at position: 32903520
10^8, 2, dynamic, 100000, 52
Time: 43014137
Number 52 found at position: 1328570976
10^8, 4, dynamic, 100000, 605
Time: 83228951
Number 605 found at position: 0
10^8, 8, dynamic, 100000, 891
Time: 109205564
Number 891 found at position: 0
10^8, 16, dynamic, 100000, 1520
Time: 104899901
Number 1520 found at position: 0