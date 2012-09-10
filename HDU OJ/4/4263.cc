//Result:2012-09-10 14:23:20	Accepted	4263	421MS	3732K	1401 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define pb push_back

vector<int> g[2][SIZE];
int n,m,k;
int father[SIZE];
int cnt[SIZE];
int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}


int cnc(vector<int> vec[])
{
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<=n;i++) father[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)vec[i].size();j++)
		{
			int a=i,b=vec[i][j];
			father[findfather(a)]=findfather(b);
		}
	}
	for(int i=1;i<=n;i++) cnt[findfather(i)]++;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]) res++;
	}
	return res-1;
}



int main()
{
	freopen("input.txt","r",stdin);
	char cmd[5];
	int a,b,ptr,red,bla;
	while(input(n>>m>>k))
	{
		red=bla=0;
		if(n+m+k==0) break;
		for(int i=0;i<SIZE;i++)
		{
			g[0][i].clear();
			g[1][i].clear();
		}
		for(int i=0;i<m;i++)
		{
			scanf("%s%d%d",cmd,&a,&b);
			if(*cmd=='B')
			{
				ptr=0;
				bla++;
			}
			else
			{
				ptr=1;
				red++;
			}
			g[ptr][a].pb(b);
			g[ptr][b].pb(a);
		}

		int nR=cnc(g[0]);
		int nB=cnc(g[1]);
		//print(nB<<"  "<<nR);
		if(bla>=k && k>=nB && nR<=n-k-1 && red>=n-k-1) puts("1");
		else puts("0");
	}
	return 0;
}

