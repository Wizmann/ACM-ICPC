#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 100+10

int price[N];
int need[N];
long long ans[N];

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(price,0,sizeof(price));
		memset(need,0,sizeof(need));
		memset(ans,0,sizeof(ans));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",need+i,price+i);
			need[i]+=need[i-1];
		}
		
		for(int i=1;i<=n;i++)
		{
			long long min=1<<30;
			for(int j=0;j<i;j++)
			{
				long long t=ans[j]+price[i]*(need[i]-need[j]+10);
				if(t<min) min=t;
			}
			ans[i]=min;
		}
		
		printf("%lld\n",ans[n]);
	}
	return 0;
}
			
