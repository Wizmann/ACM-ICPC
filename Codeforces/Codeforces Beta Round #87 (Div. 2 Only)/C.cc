#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
 
using namespace std;
 
#define pb push_back
 
vector<int> g[2010];
int n,a;
int ans;
char visit[2010];
char group[2010];
int father[2010];
 
void dfs(int x,int p=0)
{
	if(!group[p]) group[p]=1;
 
	visit[x]=1;
	int sz=g[x].size();
	for(int i=0;i<sz;i++)
	{
		dfs(g[x][i],p+1);
	}
}
 
 
int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a>0) g[a].pb(i);
		father[i]=a;
	}
	for(int i=1;i<=n;i++) if(father[i]==-1)
	{
		dfs(i);
	}
	for(int i=0;i<n;i++)
	{
		if(group[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
