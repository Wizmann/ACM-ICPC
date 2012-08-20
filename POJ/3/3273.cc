#include <cstdio>
#include <cstring>
#include <cstdlib>

int n,month;
int ex[100100];

int main()
{
	freopen("input.txt","r",stdin);
	int low=0,high=0;
	int mid;
	while(scanf("%d%d",&n,&month)!=EOF)
	{
		low=0;high=0;
		memset(ex,0,sizeof(ex));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ex[i]);
			high+=ex[i];
		}
		
		while(high-low>5)
		{
			int t=0,num=0;
			mid=(high+low)/2;
			for(int i=0;i<n;i++)
			{
				t+=ex[i];
				if(ex[i]>mid)
				{
					num=1<<20;
					break;
				}				
				if(t>mid)
				{
					t=0;
					i--;
					num++;
				}
			}
			if(t) num++;
			if(num<=month) high=mid;
			else low=mid;
		}
		
		for(int i=low;i<=high;i++)
		{
			int t=0,num=0;
			for(int j=0;j<n;j++)
			{
				t+=ex[j];
				if(ex[j]>i)
				{
					num=1<<20;
					break;
				}
				if(t>i)
				{
					t=0;
					j--;
					num++;
				}
			}
			if(t) num++;
			if(num<=month)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
	
