//Result:1027906 	5985 	Robbing Gringot... 	Wizmann 	Accepted 	C++ 	31.649 	2012-07-03 10:04:43
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <stack>
#include <deque>
#include <cmath>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 64
#define INF 1<<20

int pack[SIZE];
int n,m;
int g[SIZE][SIZE];

bitset<SIZE> visx,visy;
int linky[SIZE];
int lx[SIZE],ly[SIZE];
int slack;

bool dfs(int x)
{
	visx[x]=1;
    for(int y=0;y<m;y++)
    {
        if(visy[y]) continue;
        int t=lx[x]+ly[y]-g[x][y];
        if(!t)
        {
            visy[y] = 1;
            if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y] = x;
				return 1;
			}
		}
		else if(t<slack)  slack=t;
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
		for(int j=0;j<m;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			visx.reset();
			visy.reset();
			slack=INF;
			if(dfs(i)) break;
			for(int j=0;j<n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=0;j<m;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=0;i<m;i++)
	{
		if(linky[i]!=-1)
		{
			res+=lx[linky[i]]+ly[i];
		}
	}
    return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,num;
	int v[SIZE];
	set<int> hash;
	input(T);
	while(T--)
	{
		int maxpack=-INF;
		scanf("%d%d",&n,&m);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%d",pack+i);
			maxpack=max(maxpack,pack[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&num);
			for(int j=0;j<num;j++)
			{
				scanf("%d",v+j);
			}
			int half=num>>1;
			hash.clear();
			hash.insert(0);
			for(int j=1;j<(1<<half);j++)
			{
				int sum=0;
				for(int k=0;k<half;k++)
				{
					if(j&(1<<k)) sum+=v[k];
				}
				if(sum<=maxpack) hash.insert(sum);
			}

			for(int j=0;j<(1<<(num-half));j++)
			{
				int sum=0;
				for(int k=0;k<(num-half);k++)
				{
					if(j&(1<<k)) sum+=v[k+half];
				}
				for(int k=0;k<n;k++)
				{
					int minus=pack[k]-sum;
					if(!g[k][i] && minus<=maxpack && hash.find(minus)!=hash.end())
					{
						g[k][i]=pack[k];
					}
				}
			}
		}

		
		if(n>m)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<i;j++)
				{
					swap(g[i][j],g[j][i]);
				}
			}
			swap(m,n);
		}
		/*
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",g[i][j]);
			}
			puts("");
		}
		*/
		printf("%d\n",km());
	}
	return 0;
}

