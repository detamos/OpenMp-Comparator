#include "fibonacci.h"

long fibonacci(long n)
{
	long i;
	long long fibi = 0,fibi_1 = 1,fibi_2 = 0;
	if(n <= 1)
		return 0;
	if(n == 2)
		return 1;
	for(i=3;i<=n;i++)
	{
		fibi = fibi_1 + fibi_2;
		fibi_2 = fibi_1;
		fibi_1 = fibi;
	}
	return fibi;
}