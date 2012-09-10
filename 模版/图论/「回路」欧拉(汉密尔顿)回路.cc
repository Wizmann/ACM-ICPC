//Result:2012-09-10 23:44:34	Accepted	4284	265MS	340K	1958 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 101
#define N 16
#define INF 1<<28

struct city
{
	int nr,ci,di;
	
	city(){}
	city(int inr,int ici,int idi)
	{
		nr=inr;ci=ici;di=idi;
	}
	friend bool operator < (const city &a,const city &b)
	{
		return a.nr<b.nr;
	}
};


int g[SIZE][SIZE];
int n,m,gold,h;
city tour[N];
int gg[N][N];
char visit[N];

bool dfs(int cur,int num,int coin)
{
	if(num==h)
	{
		if(coin-gg[cur][0]>=0) return true;
		//如果修改最后的条件就是汉密尔顿路
		//不修改就是欧拉回路
		else return false;
	}
	bool ans=false;
	for(int i=0;i<h;i++)
	{
		int v=i;
		if( (coin-gg[cur][v]-tour[i].di>=0) && !visit[v] )
		{
			int res=coin+(tour[i].ci-tour[i].di)-gg[cur][v];
            visit[v]=true;
            if(res>=0) ans|=dfs(v,num+1,res);
            visit[v]=false;
            if(ans) return ans;
       }
   }
   return false;
}
          

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T,a,b,c;
	input(T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&gold);
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++) g[i][j]=INF;
			g[i][i]=0;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a][b]=g[b][a]=min(g[a][b],c);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
				}
			}
		}
		input(h);
		bool start=false;
		for(int i=0;i<h;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a==1) start=true;
			tour[i]=city(a,b,c);
		}
		if(!start) tour[h++]=city(1,0,0);
		sort(tour,tour+h);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<h;j++)
			{
				gg[i][j]=gg[j][i]=g[tour[i].nr][tour[j].nr];
			}
		}
		memset(visit,0,sizeof(visit));
		bool ok=dfs(0,0,gold);
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}




