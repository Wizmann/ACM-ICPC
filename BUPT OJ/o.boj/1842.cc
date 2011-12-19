#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int len(long long n)
{
	int res=0;
	while(n)
	{
		res++;
		n/=10;
	}
	return res;
}

long long elf(int i)
{
	long long res=(long long)pow(10,i);
	res=(res-1)/9;
	return res;
}
	
	
int main()
{
	long long n;
	while(scanf("%lld",&n),n)
	{
		int i=len(n)+1;
		while(i--)
		{
			if(n%elf(i)==0)
			{
				printf("%lld\n",n/elf(i));
				break;
			}
		}
	}
	return 0;
}
			
			
