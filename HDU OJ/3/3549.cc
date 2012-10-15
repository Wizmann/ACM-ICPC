//Result:2012-10-13 14:21:24	Accepted	3549	156MS	356K	2726 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 36
#define EDGE 10240
#define INF 1<<29

struct node
{
	int st,end,flow,next;
	node(){}
	node(int ist,int iend,int iflow,int inext)
	{
		st=ist;end=iend;
		flow=iflow;next=inext;
	}
};

node edge[EDGE];
int head[NODE];
int ind;
int source,sink;

inline void addEdge(int s,int e,int f)
{
	edge[ind]=node(s,e,f,head[s]);
	head[s]=ind++;

	edge[ind]=node(e,s,0,head[e]);
    head[e]=ind++;
}
namespace dinic
{
	int level[NODE],curhead[NODE],Que[NODE];
	int estack[4*NODE+4*EDGE],estop;
	
	int BFS()
	{
		memset(level,-1,sizeof(level));
		Que[0]=source;
		level[source]=0;
		for(int fr=0,tail=1;fr!=tail;fr=(fr+1)%NODE)
		{
			int cur=Que[fr];
			for(int e=head[cur];e!=-1;e=edge[e].next)
			{
				int next=edge[e].end;
				if(edge[e].flow && level[next] == -1)
				{
					Que[tail]=next;
					level[next]=level[cur]+1;
					tail=(tail+1)%NODE;
				}
			}
		}
		return level[sink]!=-1;
	}
	
	int DFS()
	{
		int indptr,minf,e;
		int res=0;
		int cur=source;                                                   
		estop=0;
		memcpy(curhead,head,sizeof(head));  
		while(estop>=0)
		{            
			if(cur==sink)
			{                                      
				minf=INF;
				for(int i=estop-1;i>=0;i--)
				{
					e=estack[i];
					if(edge[e].flow<=minf)
					{
						minf=edge[e].flow;
						indptr=i;
					}
				}
				res+=minf;                                   

				for(int i=estop-1;i>=0;i--)
				{               
					e=estack[i];
					edge[e].flow-=minf;
					edge[e^1].flow+=minf;
				}
				estop=indptr;                                    
				cur=edge[estack[estop]].st;          
			}
			for(e=curhead[cur];e!=-1;e=edge[e].next)
			{  
				curhead[cur]=e;
				int next=edge[e].end;
				if(edge[e].flow && level[next]==level[cur]+1)
				{
					estack[estop++]=e;
					cur=next;
					break;
				}
			}
			if(e==-1)
			{                                           
				estop--;
				level[cur]=-2;                                    
				cur=edge[estack[estop]].st;               
			}
		}
		return res;
	}
}

void init()
{
	ind=0;
	memset(head,-1,sizeof(head));
}

int n,m;

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b,c,cas=1;
	input(T);
	while(T--)
	{
		printf("Case %d: ",cas++);
		init();
		input(n>>m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
		}
		addEdge(0,1,INF);
		source=0;sink=n;
		int res=0;
		while(dinic::BFS()) res+=dinic::DFS();
		print(res);
	}
	return 0;
}

