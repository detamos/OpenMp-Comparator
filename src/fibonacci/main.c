#include "fibonacci.h"
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("Wrong number of arguments\n");
		return 0;
	}	
	long ans;
	char *ptr;
	long n = strtol(argv[2],&ptr,10);
	if(argv[1][0] == 'o')
	{
		omp_set_dynamic(0);
		omp_set_num_threads(4);

		#pragma omp parallel shared(n)
		{
			#pragma omp single
			ans = fibonacci_omp(n);
		}
	}
	else
	{
		ans = fibonacci(n);
	}
	return 0;
}