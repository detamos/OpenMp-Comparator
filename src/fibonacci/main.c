#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{	
	long n;
	scanf("%ld",&n);
	clock_t start,end;

	start = clock();
	fibonacci(n);
	end = clock();

	printf("Time : %f\n",(float)(end-start)/CLOCKS_PER_SEC);

	return 0;
}