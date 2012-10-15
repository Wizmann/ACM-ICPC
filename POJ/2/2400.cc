//Result:wizmann	2400	Accepted	252K	63MS	C++	2256B	2012-09-28 20:04:17
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 16
#define INF 0x3f3f3f3f

int mp[SIZE][SIZE];
int n;

char visx[SIZE],visy[SIZE];
int linky[SIZE];
char visit[SIZE];
int lx[SIZE],ly[SIZE];
int slack;
int bp,sum;

bool dfs(int x)
{
	visx[x]=1;
	for(int y=0;y<n;y++)
	{
		if(visy[y]) continue;
		int t=lx[x]+ly[y]-mp[x][y];
		if(!t)
		{
			visy[y]=1;
			if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y]=x;
				return 1;
			}
		}
		else if(t<slack) slack=t;
	}
	return 0;
}

int km()
{
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			lx[i]=max(lx[i],mp[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(dfs(i)) break;
			for(int j=0;j<n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=0;j<n;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(linky[i]!=-1)
		{
			res+=lx[linky[i]]+ly[i];
		}
	}
	return res;
}

void print_ans()
{
	printf("Best Pairing %d\n",bp++);
	for(int i=0;i<n;i++)
	{
		printf("Supervisor %d with Employee %d\n",i+1,linky[i]+1);
	}
}

void slove(int x=0,int tmp=0)
{
	if(tmp>sum) return;
	else if(x==n)
	{
		print_ans();
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!visit[i])
			{
				visit[i]=1;
				linky[x]=i;
				slove(x+1,tmp-mp[x][i]);
				visit[i]=0;
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T,tmp,cas=1;
	input(T);
	while(T--)
	{
		input(n);
		bp=1;
		memset(mp,0,sizeof(mp));
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&tmp);
				mp[--tmp][i]-=j;
			}
		}

		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&tmp);
				mp[i][--tmp]-=j;
			}
		}


		sum=-km();

		printf("Data Set %d, Best average difference: %.6lf\n",cas++,(double)sum/(double)(2*n));
		memset(visit,0,sizeof(visit));
		slove();
		if(T) puts("");
	}
	return 0;
}



		

