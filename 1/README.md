For reduce.c, there are 4 command line arguments. Arg1 is the length of the array, arg2 is the number of threads, arg3 will be the scheduling type,
and arg4 is the number of iterations if the schedule is dynamic.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o reduce reduce.c

Output from script.sh on Mamba:

10^8, 1, static, 1
Time: 9714936
10^8, 1, dynamic, 1000
Time: 9671746
10^8, 1, dynamic, 100000
Time: 9677114
10^8, 2, static, 1
Time: 42737613
10^8, 2, dynamic, 1000
Time: 43245945
10^8, 2, dynamic, 100000
Time: 43355027
10^8, 4, static, 1
Time: 86269807
10^8, 4, dynamic, 1000
Time: 83985220
10^8, 4, dynamic, 100000
Time: 83523799
10^8, 8, static, 1
Time: 106468755
10^8, 8, dynamic, 1000
Time: 109043306
10^8, 8, dynamic, 100000
Time: 109557318
10^8, 16, static, 1
Time: 104542300
10^8, 16, dynamic, 1000
Time: 105366380
10^8, 16, dynamic, 100000
Time: 105129511