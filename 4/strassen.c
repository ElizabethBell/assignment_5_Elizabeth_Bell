// arg 1 will be the number of threads
//to avoid issues, the scheduling policy will have assigned numbers for each one (1 is static, 2 is dynamic)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

void maintask();

void maintask(){
  int m1, m2, m3, m4, m5, m6, m7;
  int n1, n2, n3, n4, n5, n6, n7;
  int p1, p2, p3, p4, p5, p6, p7;
  int t1, t2, t3;
  int c11, c12, c21, c22;
  
  #pragma omp task depend(out: m1)
    m1 = 1;
  #pragma omp task depend(out: m2)
    m2 = 1;
  #pragma omp task depend(out: m3)
    m3 = 1;
  #pragma omp task depend(out: m4)
    m4 = 1;
  #pragma omp task depend(out: m5)
    m5 = 1;
  #pragma omp task depend(out: m6)
    m6 = 1;
  #pragma omp task depend(out: m7)
    m7 = 1;
  #pragma omp taskwait
  
  #pragma omp task depend(out: n1)
    n1 = 1;
  #pragma omp task depend(out: n2)
    n2 = 1;
  #pragma omp task depend(out: n3)
    n3 = 1;
  #pragma omp task depend(out: n4)
    n4 = 1;
  #pragma omp task depend(out: n5)
    n5 = 1;
  #pragma omp task depend(out: n6)
    n6 = 1;
  #pragma omp task depend(out: n7)
    n7 = 1;
  #pragma omp taskwait
    
  #pragma omp task depend(in:m1, n1) depend(out: p1)
    p1 = m1 * n1 *5;
  #pragma omp task depend(in:m2, n2) depend(out: p2)
    p2 = m2 * n2 *5;
  #pragma omp task depend(in:m3, n3) depend(out: p3)
    p3 = m3 * n3 *5;
  #pragma omp task depend(in:m4, n4) depend(out: p4)
    p4 = m4 * n4 *5;
  #pragma omp task depend(in:m5, n5) depend(out: p5)
    p5 = m5 * n5 *5;
  #pragma omp task depend(in:m6, n6) depend(out: p6)
    p6 = m6 * n6 *5;
  #pragma omp task depend(in:m7, n7) depend(out: p7)
    p7 = m7 * n7 *5;
  #pragma omp taskwait
    
  #pragma omp task depend(in:p1, p4) depend(out: t1)
    t1 = p1 + p4 +1;
  #pragma omp task depend(in:p5, t1) depend(out: t2)
    t2 = t1 * 1 + p5;
  #pragma omp task depend(in:p3, t1) depend(out: t3)
    t3 = p3 + t1 +1;
  #pragma omp taskwait
    
  #pragma omp task depend(in:p1, p2) depend(out: c11)
    c11 = p1 + p2 +1;
  #pragma omp task depend(in:p6, t3) depend(out: c12)
    c12 = p6 + t3 +1;
  #pragma omp task depend(in:t2, p7) depend(out: c21)
    c21 = p1 + p4 +1;
  #pragma omp task depend(in:t2, p3) depend(out: c22)
    c22 = p3 + t2 +1;
  #pragma omp taskwait
  
  return;
}

int main (int argc, char *argv[]) {
  srand(time(NULL));
  
  if(argc < 2) {
    printf("Incorrect number of arguments. Program terminated.\n");
  }
  else {
    int threads = atoi(argv[1]);
    struct timeval start, end;
    
    omp_set_num_threads(threads);
    
    gettimeofday(&start, NULL);
    #pragma omp parallel
    {
      maintask();
    }
    gettimeofday(&end, NULL);
    printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
  }
  return 0;
}