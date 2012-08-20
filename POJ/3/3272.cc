//Result:wizmann	3272	Accepted	560K	63MS	C++	1237B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 5010
#define pb push_back

int n,m;
vector<int> vecA[SIZE],vecB[SIZE];
int in[SIZE],out[SIZE];
int f[SIZE],g[SIZE];

int main()
{
	int a,b;
	input(n>>m);
	for(int i=0;i<m;i++)
	{
		input(a>>b);
		vecA[a].pb(b);
		vecB[b].pb(a);
		in[b]++;
		out[a]++;
	}
	queue<int> q;
	bitset<SIZE> bs;
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			q.push(i);
			g[i]=1;
		}
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		int sz=vecA[t].size();
		for(int i=0;i<sz;i++)
		{
			int u=vecA[t][i];
			in[u]--;
			if(!in[u]) q.push(u);
			g[u]+=g[t];
		}
	}
	bs.reset();
	q.push(n);f[n]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		int sz=vecB[t].size();
		for(int i=0;i<sz;i++)
		{
			int u=vecB[t][i];
			out[u]--;
			if(!out[u]) q.push(u);
			f[u]+=f[t];
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		int sz=vecA[i].size();
		for(int j=0;j<sz;j++) ans=max(ans,g[i]*f[vecA[i][j]]);
	}
	print(ans);
	return 0;
}
