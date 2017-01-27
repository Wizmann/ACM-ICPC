//Result:2012-09-17 16:05:11	Accepted	4292	125MS	3080K	3398 B	G++	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 1024
#define EDGE 180000
#define INF 0x3f3f3f3f
#define SOURCE 0
#define SINK (f+n*2+d+1)

struct node
{
    int st,end,flow,next;
    node(){}
    node(int ist,int iend,int iflow,int inext)
    {
		st=ist;end=iend;flow=iflow;next=inext;
	}
};

node edge[EDGE];
int head[NODE];
int ind;
int source,sink;

void addEdge(int s,int e,int f)
{
    edge[ind]=node(s,e,f,head[s]);
    head[s] = ind ++;
    
    edge[ind]=node(e,s,0,head[e]);
    head[e] = ind ++;
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


int main()
{
	freopen("input.txt","r",stdin);	
	char cmd[256];
	int a,n,f,d;
	while(input(n>>f>>d))
	{
		init();
		for(int i=1;i<=f;i++)
		{
			scanf("%d",&a);
			addEdge(SOURCE,i,a);
		}
		for(int i=1;i<=d;i++)
		{
			scanf("%d",&a);
			addEdge(f+n*2+i,SINK,a);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++) if(cmd[j]=='Y')
			{
				addEdge(j+1,f+(i*2)-1,1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			addEdge(f+i*2-1,f+i*2,1);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++) if(cmd[j]=='Y')
			{
				addEdge(f+(i*2),f+2*n+j+1,1);
			}
		}
		source=SOURCE;
		sink=SINK;
		int res = 0;
		while(dinic::BFS()) res+=dinic::DFS();
		printf("%d\n",res);
	}
	return 0;
}


