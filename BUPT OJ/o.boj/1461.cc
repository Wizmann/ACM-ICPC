#include <stdio.h>

int n,p;
int array[210];

int count(int g)
{
	int ans=0;
	int pn=0,i;
	for(i=1;i<=n;i++)
	{
		ans+=array[i];
		if(ans>=g)
		{
			if(ans>g) i--;
			ans=0;
			pn++;
			if(pn==p) break;
		}
	}
	
	if(i==n||i==n+1) return 0;
	else return 1;	
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&p))
	{
		if(n==0&&p==0) break;
		int high=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&array[i]);
			high+=array[i];
		}
		int low=high/n;
		int mid;
		while(low<=high)
		{
			mid=(high+low)/2;
			if(0==count(mid)) high=mid-1;
			else low=mid+1;
		}

		printf("%d\n",low);	
					
	}
	return 0;
}
