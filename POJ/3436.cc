#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>

#define SOURCE 0
#define SINK n+1
#define INF 1<<25

using namespace std;

int part,n;

typedef struct node
{
	int flow;
	int in[12],out[12];
	
	void setnode()
	{
		scanf("%d",&flow);
		for(int i=0;i<part;i++) scanf("%d",&in[i]);
		for(int i=0;i<part;i++) scanf("%d",&out[i]);
	}			
}node;

typedef struct ans
{
	int from,to,flow;
	
	void setans(int a,int b,int c)
	{
		from=a;to=b;flow=c;
	}
	
	void print()
	{
		printf("%d %d %d\n",from,to,flow);
	}
}ans;
		

node mach[52];
ans save[100];
int g[52][52];
int pre[52];
char used[52];
ans *st=save;

void pushans(int a,int b,int c)
{
	st->setans(a,b,c);
	st++;
}

bool equal(int *a,int *b)
{
	for(int i=0;i<part;i++)
	{
		if(a[i]+b[i]==1) return false;
	}
	return true;
}

void EK()
{
	int flow=0,tnum=0;
	while(1)
	{
		memset(used,0,sizeof(used));
		memset(pre,-1,sizeof(pre));
		stack<int> q;
		while(!q.empty()) q.pop();
		q.push(SOURCE);
		used[SOURCE]=1;
		while(!q.empty())
		{
			int now=q.top();
			q.pop();
			for(int i=SOURCE;i<=SINK;i++)
			{
				if(!used[i]&&g[now][i])
				{
					used[i]=1;
					q.push(i);
					pre[i]=now;
					if(i==SINK) break;
				}
			}
			used[now]=1;
		}
		
		if(pre[SINK]==-1) break;
		int p=SINK;
		int minc=INF;
		while(p!=SOURCE)
		{
			int t=pre[p];
			if(g[t][p]<minc) minc=g[t][p];
			p=t;
		}
		flow+=minc;
		p=SINK;
		while(p!=SOURCE)
		{
			int t=pre[p];
			g[t][p]-=minc;
			g[p][t]+=minc;
			if(t!=SOURCE&&p!=SINK)
			{
				tnum++;
				pushans(t,p,minc);
			}
			p=t;
		}
	}
	printf("%d %d\n",flow,tnum);
	for(int i=0;i<tnum;i++) save[i].print();
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d",&part,&n);
	for(int i=1;i<=n;i++) mach[i].setnode();
	
	mach[SOURCE].flow=mach[SINK].flow=INF;
	for(int i=0;i<part;i++)
	{
		mach[SOURCE].in[i]=mach[SOURCE].out[i]=0;
		mach[SINK].in[i]=mach[SINK].out[i]=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(equal(mach[i].out,mach[j].in)) g[i][j]=min(mach[i].flow,mach[j].flow);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<part;j++)
		{
			if(mach[i].in[j]==1)
			{
				flag=1;
				break;
			}
		}
		if(!flag) g[SOURCE][i]=mach[i].flow;
	}
	
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<part;j++)
		{
			if(mach[i].out[j]!=1)
			{
				flag=1;
				break;
			}
		}
		if(!flag) g[i][SINK]=mach[i].flow;
	}
			
	EK();
	return 0;
}
		
