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

vector<int> g[SIZE];
char visit[SIZE];
int pre[SIZE];
int n,m;

bool deal(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		int next=g[x][i];
		if(!visit[next])
		{
			visit[next]=1;
			if(pre[next]==-1 || deal(pre[next]))
			{
				pre[next]=x;
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
	while(input(n>>m))
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			g[--a].push_back(--b);
		}

		printf("%d\n",hungary());
	}
	return 0;
}


