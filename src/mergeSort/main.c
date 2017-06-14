#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int main(int argc,char *argv[])
{	
	if(argc < 2)
	{
		printf("Wrong number of arguments\n");
		return 0;
	}

	long n,i;
	scanf("%ld",&n);
	
	long *arr;
	arr = (long*)(malloc(sizeof(long)*n));
	for(i=0;i<n;i++)
		scanf("%ld\n",&arr[i]);
	if(argv[1][0] == 'o')
	{
		omp_set_dynamic(0);
		omp_set_num_threads(4);

		#pragma omp parallel shared(n)
		{
			#pragma omp single
			mergeSort_omp(arr,0,n-1);
		}
	}
	else
	{
		mergeSort(arr,0,n-1);
	}
	return 0;
	return 0;
}