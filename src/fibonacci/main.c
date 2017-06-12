#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{	
	int *arr,n,i;
	scanf("%d",&n);
	arr = (int*)(malloc(sizeof(int)*n));
	
	clock_t start,end;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	start = clock();
	mergeSort(arr,0,n-1);
	end = clock();

	printf(" Time : %f\n",(float)(end-start)/CLOCKS_PER_SEC);

	return 0;
}