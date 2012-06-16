<<<<<<< HEAD
//Result:wizmann	3565	Accepted	1392K	2110MS	G++	3040B
=======
/*
 * Problem: 3565		User: wizmann
 * Memory: 1392K		Time: 2110MS
 * Language: G++		Result: Accepted
 */

>>>>>>> 4a54375654ec9a83e3725ee7c44913a1b7bbc28f
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 210
#define ARRAY 30000
#define SOURCE 0
#define SINK (2*n+1)
#define INF (1<<25)

struct node
{
	int st,dest;
	int flow;
	double cost;
	int next;

	node(){}
	node(int i_st,int i_dest,int i_flow,double i_cost,int i_next)
	{
		st=i_st;dest=i_dest;
		flow=i_flow;cost=i_cost;
		next=i_next;
	}
};

struct point
{
	double x,y;
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

node array[ARRAY];
int head[SIZE];
int pre[SIZE];
double dis[SIZE];
int backup[SIZE];
point pnt[SIZE];

int n;
int ind;

inline double mul(double x){return x*x;}

inline double pntDistance(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

void addEdge(int st,int end,int flow,double cost)
{
	//print(st<<' '<<end<<' '<<flow<<' '<<cost);
	array[ind]=node(st,end,flow,cost,head[st]);
	head[st]=ind++;

	array[ind]=node(end,st,0,-cost,head[end]);
	head[end]=ind++;
}

void makeGraph()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=n+1;j<=2*n;j++)
		{
			addEdge(i,j,1,pntDistance(pnt[i],pnt[j]));
		}
	}
	for(int i=1;i<=n;i++) addEdge(SOURCE,i,1,0);
	for(int i=n+1;i<=2*n;i++) addEdge(i,SINK,1,0);
}

bool spfa()
{
	bitset<SIZE> visit;
	memset(pre,-1,sizeof(pre));
	queue<int> q;
	visit.reset();
	
	q.push(SOURCE);
	for(int i=0;i<SIZE;i++) dis[i]=(double)INF;
	visit[SOURCE]=1;
	dis[SOURCE]=0;

	while(!q.empty())
	{
		
		int now=q.front();
		q.pop();
		
		visit[now]=0;
		for(int i=head[now];i!=-1;i=array[i].next)
		{
			int v=array[i].dest;
			if(array[i].flow!=0 && dis[v]>dis[now]+array[i].cost)
			{
				dis[v]=dis[now]+array[i].cost;
				pre[v]=i;

				if(!visit[v])
				{
					visit[v]=1;
					q.push(v);
				}
			}
		}
	}
	if(pre[SINK]==-1) return false;
	else return true;
}

double MinCostMaxFlow()
{
	double cost=0;
	int minflow;
	while(spfa())
	{
		minflow=INF;
		int now=pre[SINK];
		while(now!=-1)
		{
			minflow=min(minflow,array[now].flow);
			now=pre[array[now].st];
		}
		now=pre[SINK];
		while(now!=-1)
		{
			array[now].flow-=minflow;
			array[now^1].flow+=minflow;
			cost+=array[now].cost*minflow;
			now=pre[array[now].st];
		}
	}
	return cost;
}

int main()
{
<<<<<<< HEAD
	freopen("input.txt","r",stdin);
=======
>>>>>>> 4a54375654ec9a83e3725ee7c44913a1b7bbc28f
	double a,b;
	while(input(n))
	{
		ind=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n*2;i++)
		{
			input(a>>b);
			pnt[i]=point(a,b);
		}

		makeGraph();
		MinCostMaxFlow();
		for(int i=1;i<=n+1;i++)
		{
			for(int j=head[i];j!=-1;j=array[j].next)
			{
				//print(array[j].st<<' '<<array[j].dest<<' '<<array[j].flow);
				int v=array[j].dest;
				if(array[j].flow==0 && v)
				{
					backup[i]=v;
					break;
				}
			}
			//puts("");
		}			
		for(int i=1;i<=n;i++)
		{
			print(backup[i]-n);
		}
	}
	return 0;
}
