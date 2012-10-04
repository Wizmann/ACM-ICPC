/* Result
 * 2012-09-30 16:43:20
 * Moody Wizmann	K-path cover
 * accepted	1.19 	3.2M	C++ 4.3.2
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12800
#define INF 0x3f3f3f3f

struct node
{
	int nr,val;
	node(){}
	node(int inr,int ival)
	{
		nr=inr;val=ival;
	}
	friend bool operator < (const node& a,const node& b)
	{
		return a.val<b.val;
	}
};

vector<int> g[SIZE];
node sc[SIZE];
int n,m,kk;
int anti[SIZE];
char visit[SIZE];
int pre[SIZE];
int lx[SIZE],ly[SIZE];

int slove()
{
	int tk=0;//Toni Kroos
	int from,to,mincost;
	memset(lx,-1,sizeof(lx));
	memset(ly,-1,sizeof(ly));
	while(tk<kk)
	{
		queue<int> q;
		memset(visit,0,sizeof(visit));
		mincost=INF;
		to=-1;
		
		for(int i=0;i<n;i++)
		{
			if(lx[i]==-1)
			{
				q.push(i);
				while(!q.empty())
				{
					int now=q.front();
					q.pop();
					for(int j=0;j<(int)g[now].size();j++)
					{
						int next=g[now][j];
						if(!visit[next])
						{
							visit[next]=1;
							pre[next]=now;
							if(ly[next]==-1)
							{
								if(sc[i].val+sc[next].val<mincost)
								{
									mincost=sc[i].val+sc[next].val;
									to=next;
									from=i;
								}
							}
							else q.push(ly[next]);
						}
					}
				}
			}
		}
		if(to!=-1)
		{
			tk++;
			while(1)
			{
				int v=to;
				int u=pre[to];
				to=lx[u];
				ly[v]=u;lx[u]=v;
				if(u==from) break;
			}
		}
		else break;
	}
	if(tk<kk) return -1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(lx[i]!=-1) sum+=sc[i].val+sc[lx[i]].val;
	}
	return sum;
}


int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		input(kk>>n>>m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			sc[i]=node(i+1,a);
		}
		sort(sc,sc+n);
		for(int i=0;i<n;i++)
		{
			anti[sc[i].nr]=i;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			g[anti[a]].push_back(anti[b]);
		}
		int ans=slove();
		if(ans==-1) puts("NONE");
		else print(ans);
	}
	return 0;
}
