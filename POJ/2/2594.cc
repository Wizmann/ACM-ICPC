//Result:wizmann	2594	Accepted	1756K	1032MS	G++	1153B	

//最小覆盖路径：选择最少的两两不相交的路径覆盖有向无环图的所有顶点，ans=顶点数减去最大匹配数

//此题中，``You should notice that the roads of two different robots may contain some same point. ``
//并没有``两两不相交路径``这个限制条件，所以即如果两个点能连通，则两个点之间加一条路径
//然后使用Hungary算法，求出最小覆盖路径



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 0x3f3f3f3f

vector<int> g[SIZE];
int pre[SIZE];
char visit[SIZE];
int n,m;
int mp[SIZE][SIZE];

bool deal(int x)
{
	for(int i=0;i<n;i++) if(mp[x][i])
	{
		if(!visit[i])
		{
			visit[i]=1;
			if(pre[i]==-1 || deal(pre[i]))
			{
				pre[i]=x;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int sum=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(deal(i)) sum++;
	}
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n>>m) && n+m)
	{
		memset(mp,0,sizeof(mp));
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			mp[a][b]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					mp[j][k]=mp[j][k] | (mp[j][i]&mp[i][k]);
				}
			}
		}
		int sum=hungary();
		printf("%d\n",n-sum);
	}
	return 0;
}
