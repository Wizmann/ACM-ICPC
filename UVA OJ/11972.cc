//Result:Wizmann	UVA 11972	Accepted	0 KB	192 ms	C++ 4.5.3	3426 B	2012-09-18 21:56:36	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 128
#define EDGE 2048
#define INF 1<<28
#define DEBUG puts("OK");

int n,m,c;

struct node
{
	int st,end,flow,next;
	node(){}
	node(int ist,int iend,int iflow,int inext)
	{
		st=ist;end=iend;flow=iflow;next=inext;
	}
};

node edge_backup[EDGE];
vector<int> ans;

int ind;
node edge[EDGE];
int head[NODE];
int source,sink;
namespace dinic
{
	int level[NODE],cur_head[NODE],Que[NODE];
	int edge_stack[4*NODE+4*EDGE];
	int stack_top;
	
	
	int BFS()
	{
		int fr,tp,cur,next,e;
		memset(level,-1,sizeof(level));
		Que[0]=source;
		level[source]=0;
		for(fr=0,tp=1;fr!=tp;fr=(fr+1)%NODE)
		{
			cur=Que[fr];
			for(e=head[cur];e!=-1;e=edge[e].next)
			{
				next=edge[e].end;
				if(edge[e].flow && level[next] == -1)
				{
					Que[tp]=next;
					level[next]=level[cur]+1;
					tp=(tp+1)%NODE;
				}
			}
		}
		return level[sink] != -1;
	}
	int DFS()
	{
		int index,min_limit,e;
		int res = 0;

		memcpy(cur_head,head,sizeof(head));                          
		int cur = source;                                                   

		stack_top = 0;
		while(stack_top>=0)
		{            
			if(cur==sink)
			{                                       
				min_limit = INF;
				for(int i=stack_top-1;i>=0;i--)
				{
					e=edge_stack[i];
					if(edge[e].flow<=min_limit)
					{
						min_limit = edge[e].flow;
						index = i;
					}
				}
				res+=min_limit;                                   

				for(int i=stack_top-1;i>=0;i--)
				{               
					e = edge_stack[i];
					edge[e].flow -= min_limit;
					edge[e^1].flow += min_limit;
				}
				stack_top = index;                                    
				cur = edge[edge_stack[stack_top]].st;          
			}
			for(e =cur_head[cur]; e!=-1; e=edge[e].next)
			{  
				cur_head[cur] = e;
				int next = edge[e].end;
				if( edge[e].flow && level[next] == level[cur] + 1 )
				{
					edge_stack[stack_top ++]  = e;
					cur = next;
					break;
				}
			}
			if(e==-1)
			{                                           
				stack_top--;
				level[cur]=-2;                                    
				cur=edge[edge_stack[stack_top]].st;               
			}
		}
		return res;
	}
}


void addEdge(int s,int e,int f)
{
    edge[ind]=node(s,e,f,head[s]);
    head[s] = ind ++;
    
    //edge[ind]=node(e,s,0,head[e]);
    //head[e] = ind ++;
}

void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
	ans.clear();
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b,cas=1;
	input(T);
	while(T--)
	{
		init();
		input(n>>m>>c);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			addEdge(a,b,1);
			addEdge(b,a,1);
		}
		
		for(int i=1;i<=n;i++)
		{
			memcpy(edge_backup,edge,sizeof(edge));
			if(i!=c)
			{
				source=c;sink=i;
				int res=0;
				while(dinic::BFS()&&res<2) res+=dinic::DFS();
				
				if(res>=2) ans.push_back(i);
				memcpy(edge,edge_backup,sizeof(edge));
			}
		}
		printf("Case %d:",cas++);
		if(!ans.size()) puts(" none");
		else
		{
			for(int i=0;i<(int)ans.size();i++) if(ans[i]!=c)
			{
				printf(" %d",ans[i]);
			}
			puts("");
		}
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////


//Result: Wizmann	UVA 11972	Accepted	0 KB	16 ms	C++ 4.5.3	1703 B	2012-09-18 22:28:43
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128


int g[SIZE][SIZE];//临接表
int dfn[SIZE],low[SIZE];//时间戳
stack<int> st;
int bio[SIZE];
int lv=0,sum;

inline void pb(int a,int b)
{
	g[a][0]++;g[b][0]++;
	g[a][g[a][0]]=b;
	g[b][g[b][0]]=a;
}


void tarjan(int v,int pre)
{
	dfn[v]=low[v]=++lv;
	st.push(v);
	for(int i=1;i<=g[v][0];i++)
	{
		int u=g[v][i];
		if(u==pre) continue;//不能回到父节点，判重
		if(!dfn[u])
		{
			tarjan(u,v);
			low[v]=min(low[v],low[u]);
		}
		else low[v]=min(low[v],dfn[u]);
	}
	if(low[v]==dfn[v])
	{
		int t;
		++sum;
		do
		{
			t=st.top();
			st.pop();
			bio[t]=sum;//对找到的双连通分量标号
		}while(t!=v);
	}
}

inline void init()
{
	lv=sum=0;
	memset(g,0,sizeof(g));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(bio,0,sizeof(bio));
	while(!st.empty()) st.pop();
}

int main()
{
	freopen("input.txt","r",stdin);
	int n,m,q,T,a,b,cas=1;
	input(T);
	while(T--)
	{
		init();
		input(n>>m>>q);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			pb(a,b);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i,-1);
		}
		vector<int> ans;
		
		for(int i=1;i<=n;i++)
		{
			if(bio[i]==bio[q] && i!=q) ans.push_back(i);
		}
		
		printf("Case %d:",cas++);
		if(ans.size()==0) puts(" none");
		else
		{
			sort(ans.begin(),ans.end());
			for(int i=0;i<(int)ans.size();i++)
			{
				printf(" %d",ans[i]);
			}
			puts("");
		}
	}
	return 0;
}



