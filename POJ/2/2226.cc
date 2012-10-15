//Result:wizmann	2226	Accepted	4396K	79MS	C++	1571B	2012-09-28 14:50:12
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 54
#define NODE 1024

int g[NODE][NODE];
int pre[NODE];
char visit[NODE];
char maze[SIZE][SIZE];
int ll,rr;
int n,m;
int markx[SIZE][SIZE],marky[SIZE][SIZE];

void mark()
{
	memset(markx,-1,sizeof(markx));
	memset(marky,-1,sizeof(marky));
	ll=rr=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) if(maze[i][j]=='*')
		{
			if(j==0 || maze[i][j-1]!=maze[i][j])
			{
				markx[i][j]=++ll;
			}
			else markx[i][j]=ll;
		}
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++) if(maze[i][j]=='*')
		{
			if(i==0 || maze[i-1][j]!=maze[i][j])
			{
				marky[i][j]=++rr;
			}
			else marky[i][j]=rr;
		}
	}
}

bool deal(int x)
{
	for(int i=0;i<NODE;i++) if(g[x][i])
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
	for(int i=0;i<=ll;i++)
	{
		memset(visit,0,sizeof(visit));
		if(deal(i)) sum++;
	}
	return sum;
}


int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>m))
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
		}
		mark();

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='*')
				{
					g[markx[i][j]][marky[i][j]]=1;
				}
			}
		}
		print(hungary());
	}
	return 0;
}



