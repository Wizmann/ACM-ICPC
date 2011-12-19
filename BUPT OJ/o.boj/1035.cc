#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long catalan(int n)
{
	long long res=1;
	for(int i=1;i<=n;i++) res=res*(n+i)/i;
	return res/(n+1);
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int input;
		scanf("%d",&input);
		printf("%lld\n",catalan(input));
	}
	return 0;
}