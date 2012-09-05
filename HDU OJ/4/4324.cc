//Result:2012-08-01 14:51:16	Accepted	4324	296MS	17024K	1037 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2048

int n;
int g[SIZE][SIZE];
int visit[SIZE];
bool ans;

inline void addEdge(int a,int b)
{
	g[a][0]++;
	g[a][g[a][0]]=b;
}

void findCircle(int now,int step)
{
	visit[now]=step;
	for(int i=1;i<=g[now][0];i++)
	{
		int next=g[now][i];
		if(visit[next]==-1) findCircle(next,step+1);
		else if(visit[next]<step)
		{
			ans=true;
			return;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	int cas=1;
	input(T);
	char cmd[SIZE];
	while(T--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d",&n);
		memset(visit,-1,sizeof(visit));
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++)
			{
				if(cmd[j]=='1') addEdge(i,j);
			}
		}
		ans=false;
		findCircle(0,0);
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}

