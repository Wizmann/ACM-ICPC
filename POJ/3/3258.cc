#include <cstdio>
#include <cstdlib>
#include <cstring>

int g[50010];

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	freopen("input.txt","r",stdin);
	int dis,n,rem;
	int low=0,high=0;
	scanf("%d%d%d",&dis,&n,&rem);
	for(int i=1;i<=n;i++) scanf("%d",&g[i]);
	g[n+1]=dis;
	qsort(g,n+2,sizeof(int),cmp);
	high=dis;
	
	int mid,num,k;
	while(high-low>10)
	{
		mid=(high+low)/2;
		num=0;
		k=0;
		for(int i=1;i<=n+1;i++)
		{
			if(g[i]-k<mid)
			{
				num++;
				if(num>rem) break;
			}
			else k=g[i];
		}
		
		if(num<=rem) low=mid;
		else high=mid;
	}
	
	for(int i=high;i>=low;i--)
	{
		k=0;
		num=0;
		for(int j=1;j<=n+1;j++)
		{
			if(g[j]-k<i) num++;
			else k=g[j];			
		}
		if(num<=rem)
		{
			printf("%d\n",i);
			break;
		}
	}
	
	return 0;
}
		
	
	
