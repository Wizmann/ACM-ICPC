#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

int array[50100];
int pre[50100];
int last[50100];


int main()
{
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(array,0,sizeof(array));
		memset(pre,0,sizeof(pre));
		memset(last,0,sizeof(last));
		int n,sum;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&array[i]);
		sum=-1<<20;
		for(int i=1;i<=n;i++)
		{
			if(sum<0) sum=0;
			sum+=array[i];
			pre[i]=sum;
		}
		
		sum=-1<<20;
		for(int i=1;i<=n;i++)
		{
			sum=std::max(sum,pre[i]);
			pre[i]=sum;
		}
		
		sum=-1<<20;
		for(int i=n;i>=1;i--)
		{
			if(sum<0) sum=0;
			sum+=array[i];
			last[i]=sum;
		}
		
		sum=-1<<20;
		for(int i=n;i>=1;i--)
		{
			sum=std::max(sum,last[i]);
			last[i]=sum;
		}
		
		sum=-1<<20;
		for(int i=1;i<n;i++)
		{
			if(pre[i]+last[i+1]>sum) sum=pre[i]+last[i+1];
		}			
		printf("%d\n",sum);
	}
	return 0;
}
	
