//Result:Wizmann 	2193 	Accepted 	GNU C++ 	1.62k 	380 ms 	5344 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256
#define INF 1e10
#define START 0
#define DEST n-1

struct node
{
	int dest;
	double w;
	int next;
	
	node(){}
	node(int i_dest,double i_w,int i_next)
	{
		dest=i_dest;
		w=i_w;
		next=i_next;
	}
};

double dis[SIZE];
node g[SIZE<<10];
int head[SIZE];
map<string,int> mp;
int n,m;
int ind;

void init()
{
	mp.clear();
	mp["China"]=0;
	mp["Mauritius"]=n-1;
	ind=0;
	memset(head,-1,sizeof(head));
}


void addEdge(int from,int to,double cost)
{
	g[ind]=node(to,cost,head[from]);
	head[from]=ind++;
	g[ind]=node(from,cost,head[to]);
	head[to]=ind++;
}

double SPFA()
{
	queue<int> q;
	bitset<SIZE> visit;
	while(!q.empty()) q.pop();
	visit.reset();
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	q.push(START);
	dis[START]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int t=head[now];
		while(t!=-1)
		{
			int dest=g[t].dest;
			if(dis[now]<INF && dis[now]+g[t].w<dis[dest])
			{
				dis[dest]=dis[now]+g[t].w;
				if(!visit[dest])
				{
					q.push(dest);
					visit[dest]=1;
				}
			}
			t=g[t].next;
		}
	}
	return dis[DEST];
}


int main()
{
	freopen("input.txt","r",stdin);
	string country;
	while(input(n>>m))
	{
		
		int cind=0;
		init();
		for(int i=0;i<n;i++)
		{
			input(country);
			if(mp.find(country)==mp.end()) mp[country]=++cind;
		}
		
		string ca,cb;
		int s,v;
		for(int i=0;i<m;i++)
		{
			input(ca>>cb>>s>>v);
			int a=mp[ca];
			int b=mp[cb];
			addEdge(a,b,(double)s/v);
		}
		
		printf("%.2lf\n",SPFA());
	}
	return 0;
}
			

