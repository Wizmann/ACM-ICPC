//Result:2012-09-07 17:47:02	Accepted	3681	1125MS	12256K	2785 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <deque>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 16
#define INF 0x3f3f3f3f

const int mx[]={0,1,-1,0};
const int my[]={1,0,0,-1};

struct point
{
	int x,y;
	int type;
	point(){}
	point(int ix,int iy,int itype=-1)
	{
		x=ix;y=iy;type=itype;
	}
	friend bool operator < (const point &a,const point &b)
	{
		return a.type<b.type;
	}
};

int n,m,sw,sz;
char maze[SIZE+5][SIZE+5];
point array[SIZE];
int dis[SIZE+5][SIZE+5];
int g[SIZE][SIZE];

bool inMap(const point& p)
{
	if(p.y>=0 && p.y<n &&
			p.x>=0 && p.x<m &&
			maze[p.y][p.x]!='D') return true;
	else return false;
}

void bfs(int st)
{
	queue<point> q;
	point ST=array[st];
	ST.type=0;//use type as step
	q.push(ST);
	memset(dis,0x3f,sizeof(dis));
	dis[ST.y][ST.x]=0;
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		dis[now.y][now.x]=now.type;
		for(int i=0;i<4;i++)
		{
			point next=now;
			next.x+=mx[i];
			next.y+=my[i];
			next.type+=1;
			if(inMap(next) && dis[next.y][next.x]>=INF) q.push(next);
		}
	}
}

struct bp
{
	int pos,status,power;
	bp(){}
	bp(int ipos,int istatus,int ipower)
	{
		pos=ipos;status=istatus;power=ipower;
	}
};

int dp[(1<<16)][SIZE];

bool slove(int x)
{
	int end=(1<<sw)-1;
	queue<bp> q;
	bp ST=bp(sz-1,1<<(sz-1),x);
	q.push(ST);
	memset(dp,0,sizeof(dp));
	while(!q.empty())
	{
		bp now=q.front();
		q.pop();
		if( (now.status&end) == end) return true;
		if(dp[now.status][now.pos]>=now.power) continue;
		else dp[now.status][now.pos]=now.power;
		for(int i=0;i<sz;i++)
		{
			if((now.status&(1<<i))==0 && now.power-g[now.pos][i]>=0)
			{
				int power=now.power-g[now.pos][i];
				if(array[i].type==2) power=x;
				q.push(bp(i,(now.status|(1<<i)),power));
			}
		}
	}
	return false;
}



int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>m) && n+m)
	{
		sz=0;
		sw=0;
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
			for(int j=0;maze[i][j];j++)
			{
				if(maze[i][j]=='F')
				{
					array[sz++]=point(j,i,3);
					maze[i][j]='S';
				}
				else if(maze[i][j]=='G') array[sz++]=point(j,i,2);
				else if(maze[i][j]=='Y')
				{
					array[sz++]=point(j,i,1);
					sw++;
				}
			}
		}
		sort(array,array+sz);
		for(int i=0;i<sz;i++)
		{
			bfs(i);
			for(int j=0;j<sz;j++)
			{
				g[i][j]=dis[array[j].y][array[j].x];
			}
		}
		
		int l=0,r=SIZE*SIZE*2;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(slove(mid)) r=mid-1;
			else l=mid+1;
		}
		if(l>SIZE*SIZE*2) l=-1;
		printf("%d\n",l);
	}
	return 0;
}

