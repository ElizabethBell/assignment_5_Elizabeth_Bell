For first.c, there are 3 command line arguments. Arg1 is the length of the array, arg2 is the number of threads, arg3 will be the scheduling type,
arg4 is the number of iterations if the schedule is dynamic, and arg5 is the number to search for.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o first first.c

All my data was compiled with a scheduling type of dynamic,100000, but if you want, you can still use static or a different number of iterations.

Output from script.sh on Mamba:

