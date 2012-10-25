//Result:2012-10-15 22:40:58	Accepted	1814	406MS	764K	1544 B	C++	Wizmann
#include <cstdio>
#include <cstring>

using namespace std;

const int NODE=16000+123;
const int EDGE=100000+123;

const int RED=1;
const int BLACK=2;
const int WHITE=0;

struct edge
{
	int v,next;
	edge(){}
	edge(int iv,int inext)
	{
		v=iv;next=inext;
	}
};

edge g[EDGE];
int head[NODE],ind;
int color[NODE];
int scc[NODE],sccnr,limit;

inline void _addedge(int a, int b)
{
	g[ind]=edge(b,head[a]);
	head[a]=ind++;
}

inline void addedge(int a, int b)
{
	_addedge(a,b^1);
	_addedge(b,a^1);
}

void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
}

bool dfs(int now)
{
	if(color[now]==BLACK) return false;
	else if(color[now]==RED) return true;
	else
	{
		color[now]=RED;
		color[now^1]=BLACK;
		scc[sccnr++]=now;
		for(int p=head[now];p!=-1;p=g[p].next)
		{
			if(!dfs(g[p].v)) return false;//有矛盾
		}
		return true;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		limit=n*2;
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(--a,--b);
		}
		memset(color,0,sizeof(color));
		bool ok=true;
		for(int i=0;i<n;i++)
		{
			if(color[i<<1] || color[i<<1|1]) continue;
			sccnr=0;
			if(!dfs(i<<1))//如果失败，回溯遍历此连通分量之前的状态
			{
				for(int j=0;j<sccnr;j++)
				{
					color[scc[j]]=color[scc[j]^1]=WHITE;
				}
				if(!dfs(i<<1|1)) ok=false;
			}
		}
		if(ok)
		{   
			for(int i=0;i<n*2;i++)
			{
				if(color[i]==RED) printf("%d\n",i+1);
			}
		}
		else puts("NIE");
	}
	return 0;
}
