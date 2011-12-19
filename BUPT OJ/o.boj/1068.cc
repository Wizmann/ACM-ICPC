#include <cstdio>

long long digit[20]={0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889};

int dig(int n)
{
	int res=0;
	while(n>0)
	{
		res++;
		n/=10;
	}
	return res;
}

int zehn(int n)
{
	int res=1;
	while(--n)
	{
		res*=10;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	int d=dig(n);
	printf("%lld\n",digit[d-1]+(long long)(n+1-zehn(d))*d);
	return 0;
}
	
