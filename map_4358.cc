//Result:2012-08-13 14:42:20	Accepted	4358	1515MS	29076K	1657 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
#define pb push_back

typedef map<int,int>::iterator map_iter;

map<int,int> mp[SIZE];
int w[SIZE];
int n,k;
vector<int> g[SIZE];
int local[SIZE],p[SIZE],ans[SIZE];

void merge(int u,int v)
{
	for(map_iter iter=mp[v].begin();iter!=mp[v].end();iter++)
	{
		int val=iter->first;
		int num=iter->second;

		if(mp[u][val]==k) p[u]--;
		mp[u][val]+=num;
		if(mp[u][val]==k) p[u]++;
    }
}


void dfs(int now,int father) 
{
	for(int i=0;i<(int)g[now].size();i++)
	{
		int next=g[now][i];
		if(next!=father)
		{
			dfs(next,now);
			int nv=local[now];
			int nu=local[next];
			if(mp[nv].size()>mp[nu].size())
			{
				merge(nv,nu);
			}
			else
			{
				local[now]=nu;
				merge(nu,nv);
			}
		}
	}
	ans[now]=p[local[now]];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,a,b,q;
	input(T);
	int cas=1;
	while(T--)
	{
		memset(p,0,sizeof(p));
		memset(ans,0,sizeof(ans));
		printf("Case #%d:\n",cas++);
		for(int i=0;i<SIZE;i++)
		{
			g[i].clear();
			mp[i].clear();
		}
		input(n>>k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",w+i);
			mp[i][w[i]]=1;
			if(k==1) p[i]=1;
			local[i]=i;
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			g[a].pb(b);
			g[b].pb(a);
		}
		dfs(1,-1);
		input(q);
		while(q--)
		{
			scanf("%d",&a);
			printf("%d\n",ans[a]);
		}
		if(T) puts("");
	}
	return 0;
}

