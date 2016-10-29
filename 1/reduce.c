// arg 1 will be the array length, arg 2 will be the number of threads, arg 3 will be the scheduling type, and arg 4 will be the number of iterations
//to avoid issues, the scheduling policy will have assigned numbers for each one (1 is static, 2 is dynamic)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

int main (int argc, char *argv[]) {
  srand(time(NULL));
  
  if(argc < 5) {
    printf("Incorrect number of arguments. Program terminated.");
  }
  else {
    int length = atoi(argv[1]);
    int threads = atoi(argv[2]);
    int sched = atoi(argv[3]);
    int iter = atoi(argv[4]);
    int i;
    int min;
    int *arr = malloc(length * sizeof(int));
    struct timeval start, end;
    omp_sched_t kind;
    
    omp_set_num_threads(threads);
    
    if(sched == 2){
      kind = omp_sched_dynamic;
      omp_set_schedule(kind, iter);
    }
    else if(sched != 1 && sched != 2){
      printf("Incorrect scheduling type entered. 1 for static, and 2 for dynamic.\n");
      return 0;
    }
    
    
    
    for(i=0; i<length; i++) {
      arr[i] = rand();
    }
    
    min = arr[0];
    
    if(sched == 1){
      gettimeofday(&start, NULL);
      #pragma omp parallel for schedule(static) lastprivate(min)
        for(i=0; i<length; i++){
          #pragma omp task shared(min)
            if(arr[i] < min){
              min = arr[i];
            }
          #pragma omp taskwait
        }
      gettimeofday(&end, NULL);
      printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
      printf("Min: %d\n", min);
    }
    else {
      gettimeofday(&start, NULL);
      #pragma omp parallel for schedule(runtime) lastprivate(min)
        for(i=0; i<length; i++){
          #pragma omp task shared(min)
            if(arr[i] < min){
              min = arr[i];
            }
          #pragma omp taskwait
        }
      gettimeofday(&end, NULL);
      printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
      printf("Min: %d\n", min);
    }
    free(arr);
  }
  return 0;
}