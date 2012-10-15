//Result: 2195	Accepted	636K	110MS	C++	 2760B  Wizmann

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SIZE 110
#define SOURCE 0
#define SINK m+h+1
#define INF 1<<20

typedef struct point
{
	int x,y;
	int step;
	
	inline void setpoint(int a,int b,int c)
	{
		x=a;y=b;step=c;
	}
}point;

const int mx[]={0, 0,1,-1};
const int my[]={1,-1,0,0};

int cost[SIZE<<1][SIZE<<1];
int dis[SIZE<<1];
int pre[SIZE<<1];
int x,y,m,h;
queue<point> q;
int ans;
int g[SIZE][SIZE];
point parray[SIZE];
int flow[SIZE<<1][SIZE<<1];
char visit[SIZE][SIZE];

void bfs(int p)
{
	memset(visit,0,sizeof(visit));
	while(!q.empty()) q.pop();
	q.push(parray[p]);
	while(!q.empty())
	{
		point t=q.front();
		q.pop();
		if(!visit[t.y][t.x])
		{
			if(g[t.y][t.x])
			{
				flow[g[t.y][t.x]][p+h]=1;
				cost[g[t.y][t.x]][p+h]=t.step;
			}
			visit[t.y][t.x]=1;
			for(int i=0;i<4;i++)
			{
				int nx=t.x+mx[i],ny=t.y+my[i],ns=t.step+1;
				if(nx>0&&nx<=x&&ny>0&&ny<=y)
				{
					point np;
					np.setpoint(nx,ny,ns);
					q.push(np);
				}
			}
		}
	}
}

bool bellman_ford()
{
	memset(pre,-1,sizeof(pre));
	for(int i=SOURCE;i<=SINK;i++) dis[i]=INF;
	dis[SOURCE]=0;
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=SOURCE;i<=SINK;i++)
		{
			if(dis[i]>=INF) continue;
			else
			{
				for(int j=SOURCE;j<=SINK;j++)
				{
					if(flow[i][j]&&cost[i][j]<INF&&dis[i]+cost[i][j]<dis[j])
					{
						dis[j]=dis[i]+cost[i][j];
						pre[j]=i;
						flag=true;
					}
				}
			}
		}
	}
	return dis[SINK]!=INF;
}

void mcmf()
{
	while(bellman_ford())
	{
		int now=SINK,c=0;
		while(now!=SOURCE)
		{
			int p=pre[now];
			c+=cost[p][now];
			flow[p][now]=0;
			flow[now][p]=1;
			cost[now][p]=-cost[p][now];
			now=p;
		}
		ans+=c;
	}
}

int main()
{
	while(scanf("%d%d",&y,&x)!=EOF&&x&&y)
	{
		memset(parray,0,sizeof(parray));
		memset(flow,0,sizeof(flow));
		memset(cost,0,sizeof(cost));
		memset(g,0,sizeof(g));
		ans=0;
		m=0,h=0;
		char map[SIZE];
		for(int i=0;i<y;i++)
		{
			scanf("%s",map);
			for(int j=0;j<x;j++)
			{
				if(map[j]=='H') g[i+1][j+1]=++h;
				else if(map[j]=='m')
				{
					parray[++m].setpoint(j+1,i+1,0);
					flow[SOURCE][m]=1;
				}
			}
		}
		//编号处理：SOURCE->m1,m2->h1,h2->SINK
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++) cost[i][j]=INF;
		}
		for(int i=1;i<=m;i++)
		{
			cost[SOURCE][i]=0;
			flow[SOURCE][i]=1;
		}
		for(int i=1;i<=h;i++)
		{
			cost[i+m][SINK]=0;
			flow[i+m][SINK]=1;
		}
		for(int i=1;i<=m;i++) bfs(i);	
		mcmf();
		
		printf("%d\n",ans);
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////


//Result:wizmann	2195	Accepted	332K	0MS	C++	2038B	2012-09-28 15:39:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 0x3f3f3f3f

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

int n,m;
char maze[SIZE][SIZE];
point house[SIZE],man[SIZE];
int ph,pm;
int g[SIZE][SIZE];
char visx[SIZE],visy[SIZE];
int linky[SIZE];
int lx[SIZE],ly[SIZE];
int slack;

inline int pntDis(const point& a,const point& b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

bool dfs(int x)
{
	visx[x]=1;
	for(int y=0;y<ph;y++)
	{
		if(visy[y]) continue;
		int t=lx[x]+ly[y]-g[x][y];
		if(!t)
		{
			visy[y]=1;
			if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y]=x;
				return 1;
			}
		}
		else if(t<slack) slack=t;
	}
	return 0;
}


int km()
{
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=0;i<pm;i++)
	{
		for(int j=0;j<ph;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=0;i<pm;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(dfs(i)) break;
			for(int j=0;j<pm;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=0;j<ph;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=0;i<ph;i++)
	{
		if(linky[i]!=-1)
		{
			res+=lx[linky[i]]+ly[i];
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>m) && n+m)
	{
		ph=pm=0;
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='m')
				{
					man[pm++]=point(j,i);
				}
				else if(maze[i][j]=='H')
				{
					house[ph++]=point(j,i);
				}
			}
		}
		for(int i=0;i<pm;i++)
		{
			for(int j=0;j<ph;j++)
			{
				g[i][j]=-pntDis(man[i],house[j]);
			}
		}

		print(-km());
	}
	return 0;
}
