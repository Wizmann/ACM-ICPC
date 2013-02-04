//Result:Feb 4, 2013 12:02:53 PM	Wizmann	 E - Flawed Flow	 GNU C++	Accepted	218 ms	10876 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200100

int n,m;
int flow[SIZE][2];
int start[SIZE];
int source[SIZE];

char vis[SIZE];
queue <int> q;

struct node
{
	int dest,cap,nr;
	int next;
	
	node(){}
	node(int idest,int icap,int inr,int inext)
	{
		dest=idest; cap=icap; nr=inr; next=inext;
	}
};

node edge[SIZE<<1];
int ind,head[SIZE];

inline void init()
{
	ind=0;
	memset(head,-1,sizeof(head));
}

inline void addedge(int a,int b,int f,int nr)
{
	edge[ind]=node(b,f,nr,head[a]);
	head[a]=ind++;
}

int main()
{
	int a,b,c;
	scanf("%d%d",&n,&m);
	
	init();
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		start[i]=a;
		addedge(a,b,c,i); addedge(b,a,c,i);  
		flow[a][0]+=c; flow[b][0]+=c;
	}
	q.push(1); 
	vis[1]=1;
	while(!q.empty())
	{
		int now=q.front(); 
		q.pop();
		for(int i=head[now];i!=-1;i=edge[i].next)
		{
			int next=edge[i].dest;
			int cap=edge[i].cap;
			int nr=edge[i].nr;
			
			if(vis[next]) continue;
			source[nr]=now;
			
			flow[next][1]+=cap;
			flow[next][0]-=cap;
			
			if(next!=n && flow[next][1]==flow[next][0])
			{
				vis[next]=1;
				q.push(next);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(source[i]==start[i]) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
