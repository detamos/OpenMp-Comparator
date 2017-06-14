#include "fibonacci.h"
#include <omp.h>
#include <stdio.h>

#define N 100000

long fibonacci(long n)
{
	 long i, j;
    if (n<2)
    {
      return n;
    }
    else
    {
         i=fibonacci(n-1);
         j=fibonacci(n-2);
         return i+j;
    }
}

long fibonacci_omp(long n)
{
	long i, j;
  	if (n<2)
  	{
	    return n;
  	}
  	else if(n < 20)
  	{
	    return fibonacci_omp(n-1)+fibonacci_omp(n-2);
  	}
  	else
    {
       #pragma omp task shared(i) firstprivate(n)
	       i=fibonacci_omp(n-1);

       #pragma omp task shared(j) firstprivate(n)
	       j=fibonacci_omp(n-2);

       #pragma omp taskwait
    	   return i+j;
    }
}
