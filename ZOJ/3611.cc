//Result:2012-09-16 11:45:20	 Accepted	3611	C++	40	1500	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define N 13

const int mx[]={-1,0,0,1};
const int my[]={0,-1,1,0};

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

const int INF=0x3f3f3f3f;

char maze[SIZE][SIZE];
int g[N][N];
int dis[SIZE][SIZE];
int m,n;
int sz,end_status;
point gold[N];

bool inMap(const point& p)
{
	if(p.y>=0 && p.y<n && p.x>=0 && p.x<m)
	{
		if(maze[p.y][p.x]!='#' && maze[p.y][p.x]!='W') return true;
		else return false;
	}
	else return false;
}

void bfs(point p)
{
	memset(dis,INF,sizeof(dis));
	queue< pair<point,int> > q;
	q.push(make_pair(p,0));
	dis[p.y][p.x]=0;
	while(!q.empty())
	{
		point now=q.front().first;
		int step=q.front().second;
		q.pop();
	
		dis[now.y][now.x]=step;

		if(maze[now.y][now.x]>=0 && maze[now.y][now.x]<4)
		{
			int dir=maze[now.y][now.x];
			point next=point(now.x+mx[dir],now.y+my[dir]);
			if(inMap(next) && dis[next.y][next.x]>=INF)
			{
				q.push(make_pair(next,step+1));
			}
		}
		else if(maze[now.y][now.x]=='0' || maze[now.y][now.x]=='$')
		{
			for(int i=0;i<4;i++)
			{
				point next=point(now.x+mx[i],now.y+my[i]);
				if(inMap(next) && dis[next.y][next.x]>=INF)
				{
					q.push(make_pair(next,step+1));
				}
			}
		}
		else print(maze[now.y][now.x]);
	}
}

struct bnode
{
	int now,status,step;
	bnode();
	bnode(int inow,int istatus,int istep)
	{
		now=inow;status=istatus;step=istep;
	}
};

int dp[1<<N];

int slove()
{
	queue<bnode> q;
	q.push(bnode(0,0,0));
	memset(dp,INF,sizeof(dp));
	while(!q.empty())
	{
		int now=q.front().now;
		int status=q.front().status;
		int step=q.front().step;
		q.pop();
		
		status|=(1<<now);
		if(dp[status]<step) continue;
		else dp[status]=step;
		
		for(int i=0;i<sz;i++)
		{
			if(g[now][i]<INF && !(status&(1<<i)))
			{
				q.push(bnode(i,status,step+g[now][i]));
			}
		}
	}
	
	int maxgold=-1,minstep=INF;
	for(int i=0;i<(1<<N);i++)
	{
		if( (i & (1<<(sz-1))) && dp[i]<INF )
		{
			int sum=0;
			for(int j=0;j<N;j++)
			{
				if(i&(1<<j)) sum++;
			}
			if(sum>maxgold)
			{
				maxgold=sum;
				minstep=dp[i];
			}
			else if(sum==maxgold)
			{
				minstep=min(minstep,dp[i]);
			}
		}
	}
	return minstep;
}
		
		
	

int main()
{
	freopen("input.txt","r",stdin);
	point st,end;
	int a,b;
	while(input(n>>m))
	{
		sz=1;
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='$') gold[sz++]=point(j,i);

				if(maze[i][j]=='L') maze[i][j]=0;
				if(maze[i][j]=='U') maze[i][j]=1;
				if(maze[i][j]=='D') maze[i][j]=2;
				if(maze[i][j]=='R') maze[i][j]=3;
			}
		}
		scanf("%d%d",&a,&b);
		a--;b--;
		st=point(b,a);
		scanf("%d%d",&a,&b);
		a--;b--;
		gold[sz++]=end=point(b,a);
		
		memset(g,INF,sizeof(g));
		bfs(st);
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%d ",dis[i][j]);
			}
			puts("");
		}
		puts("-----------");
		*/
		for(int i=1;i<sz;i++)
		{
			if(dis[gold[i].y][gold[i].x]<INF)
			{
				g[0][i]=dis[gold[i].y][gold[i].x];
				if(i!=sz-1) g[0][i]+=2;
			}
		}

		for(int i=1;i<sz-1;i++)
		{
			bfs(gold[i]);
				
			for(int j=1;j<sz;j++)
			{
				if(i!=j)
				{
					g[i][j]=dis[gold[j].y][gold[j].x];
					if(j!=sz-1) g[i][j]+=2;
				}
			}
		}
		g[sz-1][sz-1]=0;
		int ans=slove();
		if(ans==INF) print(-1);
		else print(ans);
	}
	return 0;
}


