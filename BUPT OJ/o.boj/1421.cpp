#include <stdio.h>

int isprim(int n)
{
	if(n==2) return 1;
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=3;i<=n/2;i++)
	{
		if(isprim(i)==1&&isprim(n-i)==1&&i%2!=0)
		{
			printf("%d = %d + %d\n",n,i,n-i);
			break;
		}
	}
	return 0;
}