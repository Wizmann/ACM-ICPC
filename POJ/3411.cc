//Result: Wizmann	3411	Accepted	176K	0MS	C++	1031B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define min(a,b) (a<b?a:b)
#define SIZE 11
#define INF 1<<20

short n,r;

typedef struct node
{
	short dest,pre;
	short c1,c2;

	inline void setnode()
	{
		scanf("%hd%hd%hd%hd",&dest,&pre,&c1,&c2);
	}
}node;
node road[SIZE][SIZE];
char num[SIZE];
int mincost;
char dfn[SIZE];

void dfs(int now,int cost)
{
	//printf("NOW:%d\n",now);
	if(cost>mincost) return;
	else if(now==n) mincost=min(cost,mincost);
	else
	{
		dfn[now]++;
		for(int i=1;i<=num[now];i++)
		{
			node hier=road[now][i];

			if(dfn[hier.dest]>5) continue;
			if(dfn[hier.pre]==0) dfs(hier.dest,cost+hier.c2);
			else dfs(hier.dest,cost+hier.c1);
		}
		dfn[now]--;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a;
	mincost=INF;
	scanf("%hd%hd",&n,&r);
	for(int i=0;i<r;i++)
	{
		scanf("%d",&a);
		num[a]++;
		road[a][num[a]].setnode();
	}
	dfs(1,0);
	if(mincost<INF) printf("%d\n",mincost);
	else puts("impossible");
	return 0;
}
