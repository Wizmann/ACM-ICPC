#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	long long sum=( (long long)(1+n)*n )/2;
	for(int i=0;i<n+1;i++)
	{
		int temp;
		scanf("%d",&temp);
		sum-=temp;
	}
	printf("%lld\n",-sum);
	return 0;
}