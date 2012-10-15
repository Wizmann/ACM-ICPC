//Result:wizmann	2175	Accepted	640K	235MS	C++	3064B	2012-10-06 10:54:02

/* 最小费用流消圈算法
 * 给出一个费用流的可行解（非最优），让你求出比这个解更优化（可以非最优）的解
 * 
 * 解法：用SPFA找出图中的负环，然后沿着负环将解进行处理，从而使解更优化
*/

/* 题意：给你N座大楼和M个避难所，大楼里面有人，避难所可以装人，但有容量限制。
 * 现在要求给一个方案使得所有人从大楼里跑到避难所里的时间总和最小。
 * 委员会已经搞出了一个方案，你需要看看是不是最优的。如果不是最优的，只需要提出一个更优的。
 *
 * 输入：n个大楼和m个避难所的位置坐标和容量
 * 然后是委员会给出的方案
 * 输出：更优的方案
 */


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256
#define INF 1<<28
#define abs(x) ((x)>0?(x):(-(x)))

struct CPoint
{
	int x,y,val;
	CPoint(){}
	CPoint(int ix,int iy,int ival)
	{
		x=ix;y=iy;val=ival;
	}
};

struct CEdge
{
	int dest,cost,next;
	CEdge(){}
	CEdge(int idest,int icost,int inext)
	{
		dest=idest;cost=icost;next=inext;
	}
};

inline int pntDis(const CPoint &a,const CPoint &b)
{
	return abs(a.x-b.x)+abs(a.y-b.y)+1;
}

CPoint hause[SIZE],shell[SIZE];
int n,m;
int head[SIZE];
CEdge g[SIZE*SIZE*5];
int ind;
int pre[SIZE];
int method[SIZE][SIZE];
int sum[SIZE];
char visit[SIZE];

void addEdge(int u,int v,int cost)
{
	g[ind]=CEdge(v,cost,head[u]);
	head[u]=ind++;
}


int spfa(int source,int sink,int sz)
{
	int dis[SIZE];
	int cnt[SIZE]={0};
	memset(visit,0,sizeof(visit));
	memset(pre,-1,sizeof(pre));
	
	queue<int> q;
	q.push(source);
	visit[source]=1;
		
	fill(dis,dis+SIZE,INF);
	dis[source]=0;
	
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].dest;
			int cost=g[i].cost;

			if(dis[next]>dis[now]+cost)
			{
				dis[next]=dis[now]+cost;
				pre[next]=now;
				if(!visit[next])
				{
					q.push(next);
					visit[next]=1;
					if(++cnt[next]>sz) return next;
				}
			}
		}
	}
	return -1;
}


int main()
{
	int a,b,c;
	while(input(n>>m))
	{
		memset(head,-1,sizeof(head));
		memset(method,0,sizeof(method));
		memset(sum,0,sizeof(sum));
		ind=0;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			hause[i]=CPoint(a,b,c);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			shell[i]=CPoint(a,b,c);
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&method[i][j]);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				addEdge(i,j+n,pntDis(hause[i],shell[j]));
				if(method[i][j]) addEdge(j+n,i,-pntDis(hause[i],shell[j]));
				sum[j]+=method[i][j];
			}
		}
		
		for(int i=0;i<m;i++)
		{
			if(sum[i]<shell[i].val) addEdge(i+n,m+n,0);
			if(sum[i]>0) addEdge(m+n,i+n,0);
		}
		
		int v=spfa(0,n+m,n+m);
		if(v==-1) puts("OPTIMAL");
		else
		{
			puts("SUBOPTIMAL");
			
			memset(visit,0,sizeof(visit));
			while(true)
			{
				if(!visit[v])
				{
					visit[v]=1;
					v=pre[v];
				}
				else break;
			}
			int end=v;
			do
			{
				int from = pre[v],to=v;
				if (from<n && to >= n && to<n+m) method[from][to-n]++;
				if (to < n && from >= n && from<n+m) method[to][from - n]--;
				v = pre[v];
			}while(v!=end);
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(j) printf(" ");
					printf("%d",method[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}




