#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld",&n);
	while(n!=0)
	{
		printf("%lld\n",n-n/2);
		scanf("%lld",&n);
	}
	return 0;
}
