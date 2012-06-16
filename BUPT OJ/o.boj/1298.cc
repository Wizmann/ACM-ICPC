//Result:1298	Accepted	3MS	308K	G++	 1669B	2012-06-13 23:39:57	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 10
#define SIZE 100

const int mx[]={1,0,-1,0};
const int my[]={0,1,0,-1};

vector<int> g[SIZE];
char maze[N][N];
int r,c;
bitset<SIZE> visit;
int match[SIZE];

inline int nr(int x,int y)
{
	return c*y+x;
}

void makeG()
{
	for(int i=0;i<SIZE;i++) g[i].clear();
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(maze[i][j]=='*')
			{
				for(int k=0;k<4;k++)
				{
					int ny=i+my[k];
					int nx=j+mx[k];
					if(ny>=0 && ny<r && nx>=0 && nx<c && maze[ny][nx]=='*')
					{
						g[nr(j,i)].push_back(nr(nx,ny));
					}
				}
			}
		}
	}
}

bool dfs(int now)
{
	for(int i=0;i<(int)g[now].size();i++)
	{
		int next=g[now][i];
		if(!visit[next])
		{
			visit[next]=1;
			if(match[next]==-1 || dfs(match[next]))
			{
				match[next]=now;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int res=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<r*c;i++)
	{
		visit.reset();
		if(dfs(i)) res++;
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	while(input(r>>c))
	{
		printf("Case %d:\n",cas++);
		int block=0;
		for(int i=0;i<r;i++)
		{
			scanf("%s",maze[i]);
			for(int j=0;maze[i][j];j++)
			{
				if(maze[i][j]=='*') block++;
			}
		}
		if(block&1) print("no");
		else
		{
			makeG();
			int sum=hungary();
			if(sum==block) print("yes");
			else print("no");
		}
	}
	return 0;
}


