#include "mergeSort.h"

void merge(long *arr,long l,long m,long r)
{

	long n1 = m-l+1;
	long n2 = r-m;
	long i,j,k;
	long *a1,*a2;
	a1 = (long*)(malloc(sizeof(long)*(n1+1)));
	a2 = (long*)(malloc(sizeof(long)*(n2+1)));
	for(i=0;i<n1;i++)
	{
		a1[i] = arr[l+i];
	}
	for(i=0;i<n2;i++)
	{
		a2[i] = arr[m+i+1];
	}

	a1[n1] = a2[n2] = 1e18;
	i = j = 0,k=l;
	while(k <= r)
	{
		if(a1[i] < a2[j])
		{
			arr[k] = a1[i];
			i++;
		}
		else
		{
			arr[k] = a2[j];
			j++;
		}
		k++;
	}
}

void mergeSort(long *arr,long l,long r)
{
	if(l < r)
	{
		long mid = l + (r-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void mergeSort_omp(long *arr,long l,long r)
{
	if(l < r)
	{
		long mid = l + (r-l)/2;
		if(abs(l-r) >= 50)
		{
	
			#pragma omp task shared(arr,mid) 
			mergeSort_omp(arr,l,mid);
			#pragma omp task shared(arr,mid) 
			mergeSort_omp(arr,mid+1,r);
			#pragma omp taskwait
			merge(arr,l,mid,r);
		}
		else
		{
			mergeSort_omp(arr,l,mid);
			mergeSort_omp(arr,mid+1,r);
			merge(arr,l,mid,r);
		}
	}
}