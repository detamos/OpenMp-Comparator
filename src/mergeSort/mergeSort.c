#include "mergeSort.h"

void merge(int *arr,int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	int a1[n1+1],a2[n2+1];
	int i,j,k;
	for(i=0;i<n1;i++)
	{
		a1[i] = arr[l+i];
	}
	for(i=0;i<n2;i++)
	{
		a2[i] = arr[m+i+1];
	}
	a1[n1] = a2[n2] = INT_MAX;
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

void mergeSort(int *arr,int l,int r)
{
	if(l < r)
	{
		int mid = l + (r-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
