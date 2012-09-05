#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 320

const int INF=1<<28;

int g[SIZE][SIZE];
int n;
int slack;
char visx[SIZE],visy[SIZE];
int linky[SIZE];
int lx[SIZE],ly[SIZE];

bool find(int x)
{
	visx[x]=1;
    for(int y=0;y<n;y++)
    {
        if(visy[y]) continue;
        int t=lx[x]+ly[y]-g[x][y];
        if(!t)
        {
            visy[y] = 1;
            if(linky[y]==-1 || find(linky[y]))
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
	memset(ly,0,sizeof(ly));
	memset(lx,0,sizeof(lx));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			lx[i]=max(g[i][j],lx[i]);
		}
	}

	for(int i=0;i<n;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(find(i)) break;
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
		if(linky[i]>-1)
		{
			res+=g[linky[i]][i];
		}
	}
	return res;
}


int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&g[i][j]);
			}
		}
		printf("%d\n",km());
	}
	return 0;
}

