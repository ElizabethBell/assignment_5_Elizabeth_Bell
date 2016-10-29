For reduce.c, there are 4 command line arguments. Arg1 is the length of the array, arg2 is the number of threads, arg3 will be the scheduling type,
and arg4 is the number of iterations if the schedule is dynamic.

The scheduling types used in this project will both have a number associated with them, 1 being static and 2 being dynamic. If the scheduling type is static,
you will still need to enter a number for the iteration argument.

To compile without errors, you will need to use:

gcc -fopenmp -o reduce reduce.c

Output from script.sh on Mamba:

10^8, 1, static, 1
Time: 9693890
Min: -888691200
10^8, 1, dynamic, 1000
Time: 9677411
Min: 21434720
10^8, 1, dynamic, 100000
Time: 9680360
Min: 7295328
10^8, 2, static, 1
Time: 42991001
Min: 0
10^8, 2, dynamic, 1000
Time: 42505745
Min: 902582880
10^8, 2, dynamic, 100000
Time: 45436900
Min: 102855264
10^8, 4, static, 1
Time: 86946917
Min: 0
10^8, 4, dynamic, 1000
Time: 83402915
Min: 27152736
10^8, 4, dynamic, 100000
Time: 83429288
Min: 0
10^8, 8, static, 1
Time: 109254694
Min: 0
10^8, 8, dynamic, 1000
Time: 109273491
Min: -154283424
10^8, 8, dynamic, 100000
Time: 108697149
Min: 0
10^8, 16, static, 1
Time: 105586937
Min: 0
10^8, 16, dynamic, 1000
Time: 105663060
Min: -2147472793
10^8, 16, dynamic, 100000
Time: 106298403
Min: 0