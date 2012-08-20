//Result:wizmann	2049	Accepted	4244K	813MS	G++	2258B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 220
#define MAXN (SIZE*SIZE)
#define INF 1<<25
#define WALL INF
#define DOOR 1
#define pb push_back

struct node
{
	int dest,cost;
	node(){}
	node(int i_dest,int i_cost)
	{
		dest=i_dest;
		cost=i_cost;
	}
};

int wall,door;

inline int ord(int x,int y)
{
	return x+y*SIZE;
}


vector<node> g[MAXN];
int ans[MAXN];
char mat[SIZE][SIZE][2];
int ind;
	
void makeG(int x,int y,int dir,int cost)
{
	//printf("%d %d %d %d\n",x,y,dir,cost);
	mat[x][y][dir]=1;
	int now=ord(x,y),next;
	int nx=x,ny=y;
	if(dir==0) ny--;
	else nx--;
	if(nx<0 || ny<0) return;
	if(cost>=INF) return;
	next=ord(nx,ny);
	//print(next);
	g[now].pb(node(next,cost));
	g[next].pb(node(now,cost));
}		

int bfs(int end)
{
	//print(end);
	for(int i=0;i<MAXN;i++) ans[i]=INF;
	queue<int> q;
	q.push(0);
	bitset<MAXN> visit;
	ans[0]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		
		visit[now]=0;
		
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].dest;
			int cost=g[now][i].cost;
			int c_n=ans[now]+cost;
			if(ans[next]>c_n)
			{
				ans[next]=c_n;
				if(!visit[next])
				{
					q.push(next);
					visit[next]=1;
				}
			}
		}
	}
	return ans[end]>=INF?-1:ans[end];
}


int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,d;
	double nemo_x,nemo_y;
	while(input(wall>>door) && wall+door!=-2)
	{
		ind=0;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<MAXN;i++) g[i].clear();
		for(int i=0;i<wall;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			for(int j=0;j<d;j++)
			{
				makeG(a,b,c,WALL);
				if(c==0) a++;
				else b++;
			}
		}
		for(int i=0;i<door;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			makeG(a,b,c,DOOR);
		}
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(!mat[j][i][k]) makeG(j,i,k,0);
				}
			}
		}
		scanf("%lf%lf",&nemo_x,&nemo_y);
		if(nemo_x>199 || nemo_y>199) print(0);
		else print(bfs(ord(nemo_x,nemo_y)));
	}
	return 0;
}
