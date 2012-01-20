//Result:Accepted	1428	62MS	404K	1523 B	G++	Foc_Kuuy
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 55
#define llint long long

const int mx[]={0,0,1,-1};
const int my[]={1,-1,0,0};

struct point
{
	int x,y;
	
	point(int i_x=0,int i_y=0)
	{
		x=i_x;y=i_y;
	}
};

int g[SIZE][SIZE];
int minStep[SIZE][SIZE];
llint dp[SIZE][SIZE];
int n;
char visit[SIZE][SIZE];

void bfs()
{
	queue<point> q;
	q.push(point(n-1,n-1));
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=now.x+mx[i];
			int ty=now.y+my[i];
			if(tx>=0 && tx<n && ty>=0 && ty<n)
			{
				if(minStep[ty][tx]==-1 || minStep[ty][tx]>minStep[now.y][now.x]+g[ty][tx])
				{
					minStep[ty][tx]=minStep[now.y][now.x]+g[ty][tx];
					q.push(point(tx,ty));
				}
			}
		}
	}
}

llint dfs(int x,int y)
{
	if(dp[y][x]>0) return dp[y][x];
	if(x==n-1&&y==n-1) return 1;
	for(int i=0;i<4;i++)
	{
		int tx=x+mx[i];
		int ty=y+my[i];
		if(tx>=0&&tx<n&&ty>=0&&ty<n && minStep[y][x]>minStep[ty][tx])
		{
			dp[y][x]+=dfs(tx,ty);
		}
	}
	return dp[y][x];
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
		}
		memset(minStep,-1,sizeof(minStep));
		memset(dp,0,sizeof(dp));
		memset(visit,0,sizeof(visit));
		
		minStep[n-1][n-1]=0;
		bfs();
		
		print(dfs(0,0));
	}
	return 0;
}
