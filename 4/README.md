For strassen.c, there are 4 command line arguments. Arg1 is the number of threads, arg2 will be the scheduling type,
and arg3 is the number of iterations if the schedule is dynamic.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o strassen strassen.c

I was not able to figure out scheduling in this case, so it has not been implimented.

The program also would not compile, for reasons that confuse me.

Output from script.sh on Mamba: