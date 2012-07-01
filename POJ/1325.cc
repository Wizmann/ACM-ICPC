//Result:wizmann	1325	Accepted	728K	0MS	G++	1023B	2012-07-01 12:34:37
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define pb push_back

vector<int> g[SIZE];
int n,m;
int pre[SIZE];

bool deal(int nr,int *match)
{
	for(int i=0;i<(int)g[nr].size();i++)
	{
		int next=g[nr][i];
		if(!match[next])
		{
			match[next]=true;
			if(!pre[next] || deal(pre[next],match))
			{
				pre[next]=nr;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int sum=0;
	int match[SIZE];
	for(int i=0;i<n;i++)
	{
		memset(match,0,sizeof(match));
		if(deal(i,match)) sum++;
	}
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,k;
	while(scanf("%d%d%d",&n,&m,&k)==3)
	{
		memset(pre,0,sizeof(pre));
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(b&&c) g[b].pb(c);
		}

		print(hungary());
	}
	return 0;
}

	
