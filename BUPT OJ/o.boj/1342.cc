#include <cstdio>
#include <cmath>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	long long sum;
	scanf("%d",&n);
	while(n--)
	{
		int num;
		long long temp;
		long long mod;
		mod=0;
		scanf("%d",&num);
		sum=0;
		for(int i=0;i<num;i++)
		{
			scanf("%lld",&temp);
			sum+=(mod+temp)/num;
			mod=(mod+temp)%num;
		}
		if(mod<0) sum--;
		printf("%lld\n",sum);
	}
	return 0;
}
