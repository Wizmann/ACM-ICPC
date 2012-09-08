//Result:2012-09-07 16:34:28	Accepted	3696	125MS	1160K	1719 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10240

const double inf=1e10;

struct node
{
	int dest;
	double cost;
	int next;

	node(){}
	node(int idest,double icost,int inext)
	{
		dest=idest;cost=icost;next=inext;
	}
};

double dis[SIZE];
int head[SIZE];
int n;
node g[SIZE*3];
int ind;
const int SOURCE=0;
double box[SIZE],val[SIZE];

void addEdge(int st,int end,double cost)
{
	g[ind]=node(end,cost,head[st]);
	head[st]=ind++;
}

void spfa()
{
	queue<int> q;
	bitset<SIZE> visit;
	q.push(SOURCE);
	visit[SOURCE]=1;
	fill(dis,dis+SIZE,-inf);
	dis[SOURCE]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].dest;
			double cost=g[i].cost;
			if(dis[now]+cost>dis[next])
			{
				dis[next]=dis[now]+cost;
				if(!visit[next])
				{
					q.push(next);
					visit[next]=1;
				}
			}
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int k,m;
	int a,c;
	double b;
	while(input(n) && n)
	{
		memset(head,-1,sizeof(head));
		ind=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&val[i],&box[i]);
		}
		input(k);
		while(k--)
		{
			input(m);
			scanf("%d",&a);
			for(int i=0;i<m-1;i++)
			{
				scanf("%lf%d",&b,&c);
				addEdge(c,a,log(b));
				a=c;
			}
		}
		for(int i=1;i<=n;i++)
		{
			addEdge(SOURCE,i,log(val[i]));
		}
		spfa();
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=box[i]*exp(dis[i]);
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}

