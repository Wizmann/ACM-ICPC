#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 3100

const int mx[]={1,0,-1,0};
const int my[]={0,1,0,-1};

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
};

int n,m;
int sx,sy;

char maze[SIZE][SIZE];
char visit[SIZE][SIZE];
char av[SIZE][SIZE];

bool inMap(const point &p,bool super=false)
{
	if(!super)
	{
		if(p.x<0 || p.x>=m || p.y<0 || p.y>=n) return false;
		else if(visit[p.y][p.x] || maze[p.y][p.x]=='#') return false;
		visit[p.y][p.x]=1;
		return true;
	}
	else
	{
		if(p.x<0 || p.x>=m || p.y<0 || p.y>=n) return false;
		else if(maze[p.y][p.x]=='#') return false;
		if(av[p.y][p.x]) return true;
		else return false;
	}
}

bool move(const point& p,bool &super)
{
	//print(p.x<<' '<<p.y);
	if(inMap(p)) return true;
	else if(p.x<0 || p.x>=m || p.y<0 || p.y>=n)
	{
		point newp=point((p.x+m)%m,(p.y+n)%n);
		//print(newp.x<<' '<<newp.y);
		if(inMap(newp,true))
		{
			super=true;
			return false;
		}
	}
	return false;
}

void dfs()
{
	queue<point> q;
	q.push(point(sx,sy));
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		av[now.y][now.x]=1;
		for(int i=0;i<4;i++)
		{
			point next=point(now.x+mx[i],now.y+my[i]);
			if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && !visit[next.y][next.x] && maze[next.y][next.x]!='#')
			{
				visit[next.y][next.x]=1;
				q.push(next);
			}
		}
	}
}

bool slove()
{
	queue<point> q;
	q.push(point(sx,sy));
	memset(visit,0,sizeof(visit));
	memset(av,0,sizeof(av));
	dfs();
	memset(visit,0,sizeof(visit));
	while(!q.empty())
	{
		bool super=false;
		point now=q.front();
		q.pop();
		//if(visit[now.y][now.x]) continue;
		for(int i=0;i<4;i++)
		{
			point next=point(now.x+mx[i],now.y+my[i]);
			bool flag=move(next,super);
			if(flag) q.push(next);
			if(super) break;
		}
		if(super) return true;
	}
	return false;
}

int main()
{
	freopen("d.txt","r",stdin);
	input(n>>m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",maze[i]);
		for(int j=0;maze[i][j];j++)
		{
			if(maze[i][j]=='S')
			{
				sy=i;sx=j;
				maze[i][j]='.';
			}
		}
	}
	int tm=m,tn=n;
	m*=2;n*=2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			maze[i][j]=maze[i%tn][j%tm];
		}
	}
	//for(int i=0;i<n;i++) puts(maze[i]);
	if(slove()) print("Yes");
	else print("No");
	return 0;
}
