#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void merge(long *,long ,long ,long );
void mergeSort(long *,long ,long );

void mergeSort_omp(long *arr,long l,long r);

#endif