#include <cstdio>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	long long ans;
	while(scanf("%d",&n),n)
	{
		int input;
		ans=0;
		for(int i=0;i<n*2-1;i++)
		{
			scanf("%d",&input);
			ans^=input;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
