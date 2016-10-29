For reduce.c, there are 4 command line arguments. Arg1 is the length of the array, arg2 is the number of threads, arg3 will be the scheduling type,
and arg4 is the number of iterations if the schedule is dynamic.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o reduce reduce.c

Output from script.sh on Mamba:

10^8, 1, static, 1
Time: 9949106
Min: 159766272
10^8, 1, dynamic, 1000
Time: 9780178
Min: 6795616
10^8, 1, dynamic, 100000
Time: 9674449
Min: 30450016
10^8, 2, static, 1
Time: 44113308
Min: 0
10^8, 2, dynamic, 1000
Time: 38563316
Min: 52105824
10^8, 2, dynamic, 100000
Time: 43631811
Min: 7749984
10^8, 4, static, 1
Time: 87652667
Min: 0
10^8, 4, dynamic, 1000
Time: 86060028
Min: 402936416
10^8, 4, dynamic, 100000
Time: 82062263
Min: 32657760
10^8, 8, static, 1
Time: 108855293
Min: 0
10^8, 8, dynamic, 1000
Time: 108936562
Min: 0
10^8, 8, dynamic, 100000
Time: 108774866
Min: 38613344
10^8, 16, static, 1
Time: 105347916
Min: 0
10^8, 16, dynamic, 1000
Time: 104676010
Min: 0
10^8, 16, dynamic, 100000
Time: 105097540
Min: 32784736