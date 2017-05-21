//Result:Aug 27, 2011 10:22:16 PM 	Wizmann 	C - Buns 	GNU C++ 	Accepted 	30 ms 	1400 KB 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct node
{
	int cost,num,val;

	inline void setnode(int a,int b,int c)
	{
		cost=a;num=b;val=c;
	}
}node;

int dough,m;
node array[1010];
int dp[1010];

int main()
{
	//freopen("input.txt","r",stdin);
	int a,b,c,d;
	scanf("%d%d",&dough,&m);
	scanf("%d%d",&a,&b);
	array[0].setnode(a,dough/a,b);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		array[i].setnode(c,a/b,d);
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int ans=0;
	for(int i=0;i<=m;i++)
	{
		for(int k=0;k<array[i].num;k++)
		{
			for(int j=dough;j>=0;j--)
			{
				if(dp[j]>=0)
				{
					if(j+array[i].cost<=dough)
					{
						dp[j+array[i].cost]=max(dp[j+array[i].cost],dp[j]+array[i].val);
						ans=max(ans,dp[j+array[i].cost]);
					}	
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
	
