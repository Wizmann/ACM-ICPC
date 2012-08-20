//Result: wizmann	3308	Accepted	4596K	157MS	C++	 1803B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>

#define ENE 500
#define SIZE 50
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define NODE SIZE*2+ENE+10
#define SOURCE 0
#define SINK x+y+n+1
#define INF 1<<20
#define EXP 2.718281828
#define eps 1e-8

using std::queue;

int x,y,n;
int g[NODE][NODE],pre[NODE];
char visit[NODE];
double flow[NODE][NODE];
double ans;

inline void pb(int a,int b,double v)
{
	g[a][0]++;
	g[a][g[a][0]]=b;
	flow[a][b]=v;
}

void EK()
{
	while(1)
	{
		memset(visit,0,sizeof(visit));
		memset(pre,-1,sizeof(pre));
		queue<int> q;
		q.push(SOURCE);
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			
			for(int i=1;i<=g[now][0];i++)
			{
				int t=g[now][i];
				if(flow[now][t]>eps&&!visit[t])
				{
					q.push(t);
					visit[t]=1;
					pre[t]=now;
				}
			}
		}
			
		if(pre[SINK]==-1) break;
		
		int now=SINK;
		double minf=(double)(INF);
		while(now!=SOURCE)
		{
			int p=pre[now];
			minf=min(minf,flow[p][now]);
			now=p;
		}
		now=SINK;
		ans+=minf;
		while(now!=SOURCE)
		{
			int p=pre[now];
			flow[p][now]-=minf;
			flow[now][p]+=minf;
			now=p;
		}
	}
}
				
		
		

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double c=0;
		ans=0;
		memset(g,0,sizeof(g));
		memset(flow,0,sizeof(flow));
		scanf("%d%d%d",&y,&x,&n);

		for(int i=1;i<=y;i++)
		{
			scanf("%lf",&c);
			pb(SOURCE,i,log(c));
			pb(i,SOURCE,0);
		}
		for(int i=1;i<=x;i++)
		{
			scanf("%lf",&c);
			pb(i+y,SINK,log(c));
			pb(SINK,i+y,0);
		}
		
		int a,b;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			pb(a,b+y,INF);
			pb(b+y,a,0);
		}
		EK();
		
		printf("%.4f\n",exp(ans));
	}
	return 0;
}
		
