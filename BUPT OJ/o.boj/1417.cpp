#include <stdio.h>

long long fab(int n)
{
	if(n==1||n==2) return 1;
	else return fab(n-1)+fab(n-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",fab(n));
	return 0;
}