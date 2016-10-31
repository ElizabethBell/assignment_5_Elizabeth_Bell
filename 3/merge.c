// arg 1 will be the array length, and arg 2 will be the number of threads
//to avoid issues, the scheduling policy will have assigned numbers for each one (1 is static, 2 is dynamic)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

void merge(int *arr, int length, int *temp);
void mergesort(int *arr, int length, int *temp);

void merge(int *arr, int length, int *temp){
    int i = 0;
    int j = length/2;
    int k = 0;
    int mid = length/2;
    int n;
    
    while(i < mid && j < length){
      if(arr[i] < arr[j]){
        temp[k] = arr[i];
        i++;
      }
      else {
        temp[k] = arr[j];
        j++;
      }
      k++;
    }
    
    while(i < mid){
      temp[k] = arr[i];
      k++;
      i++;
    }
    
    while(j < length){
      temp[k] = arr[j];
      k++;
      j++;
    }
    
    for(n=0; n<length; n++){
      arr[n] = temp[n];
    }
    
    return;
}

void mergesort(int *arr, int length, int *temp){
    int mid, i;
    
    if(length < 2){
      return;
    }
    
    mid = length/2;
    
    #pragma omp task firstprivate (arr, mid, temp)
    mergesort(arr, mid, temp);
    #pragma omp task firstprivate (arr, mid, temp, length)
    mergesort(arr+mid, length-mid, temp);
    #pragma omp taskwait
    
    merge(arr, length, temp);
    
    return;
}        

int main (int argc, char *argv[]) {
  srand(time(NULL));
  
  if(argc < 3) {
    printf("Incorrect number of arguments. Program terminated.\n");
  }
  else {
    int length = atoi(argv[1]);
    int threads = atoi(argv[2]);
    int i;
    int *arr = malloc(length * sizeof(int));
    int *temp = malloc(length * sizeof(int));
    struct timeval start, end;
    
    for(i=0; i<length; i++) {
      arr[i] = rand();
    }
    
    gettimeofday(&start, NULL);
    #pragma omp parallel num_threads(threads)
      mergesort(arr, length, temp);
    gettimeofday(&end, NULL);
    printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
    
    free(arr);
    free(temp);
  }
  return 0;
}