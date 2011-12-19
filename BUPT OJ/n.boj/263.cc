//Result:263 	Accepted 	297ms 	208kb 	G++	1095B	2011-12-12 16:42:04 	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define INF 1<<25

#define SIZE 128

int g[SIZE][SIZE];
int in[SIZE];
int n,m;
//The number, and the connection
int ans;

void check(int sz)
{
	int sum=0;
	for(int i=1;i<=sz;i++)
	{
		int tmp=INF;
		for(int j=1;j<=sz;j++)
		{
			if(i!=j) tmp=min(tmp,g[in[i]][in[j]]);
		}
		sum+=tmp;
	}
	ans=max(ans,sum);
}

void dfs(int pos,int sz)
{
	if(sz>1) check(sz);
	if(pos>n) return;
	
	bool flag=true;
	for(int i=1;i<=sz;i++)
	{
		if(!g[in[i]][pos])
		{
			flag=false;
			break;
		}
	}
	
	if(flag)
	{
		in[sz+1]=pos;
		dfs(pos+1,sz+1);
		dfs(pos+1,sz);
	}
	else dfs(pos+1,sz);
}

int main()
{
	int a,b,c;
	while(input(n>>m))
	{
		ans=0;
		memset(g,0,sizeof(g));
		memset(in,0,sizeof(in));
		for(int i=0;i<m;i++)
		{
			input(a>>b>>c);
			g[a][b]=g[b][a]=c;
		}
		
		dfs(1,0);
		
		print(ans);
	}
	return 0;
}
