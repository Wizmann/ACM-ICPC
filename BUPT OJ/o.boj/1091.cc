//Result:1091 	Accepted	14MS	328K	G++	1919B	2011-11-01 20:04:43	

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<30
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define SIZE 64

typedef struct node
{
	int start,end,val;
	
	void setnode(int a,int b,int c)
	{
		start=a;end=b;val=c;
	}
}node;

node array[SIZE*SIZE];
int n,m;
int dis[SIZE][SIZE];
vector<int> tree[SIZE];
bitset<SIZE> visit;
bitset<SIZE> cover;

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;
	return ta->val - tb->val;
}

bool dfs(int pos)
{
	bool res=false;
	visit[pos]=1;
	if(cover[pos]) return true;
	int sz=tree[pos].size();
	for(int i=0;i<sz;i++)
	{
		if(!visit[tree[pos][i]])
		{
			if(!dis[pos][tree[pos][i]]) res |= false;
			else res |= dfs(tree[pos][i]);
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(input(n>>m) && n)
	{
		for(int i=0;i<SIZE;i++) tree[i].clear();
		cover.reset();
		memset(array,0,sizeof(array));
		for(int i=0;i<n-1;i++)
		{
			input(a>>b>>c);
			tree[a].pb(b);
			tree[b].pb(a);
			dis[a][b]=dis[b][a]=c;
			array[i].setnode(a,b,c);
		}
		qsort(array,n-1,sizeof(node),cmp);
		
		for(int i=0;i<m;i++)
		{
			input(a);
			cover[a]=1;
		}
		
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			visit.reset();
			visit[array[i].start]=1;
			visit[array[i].end]=1;
			if(dfs(array[i].start) && dfs(array[i].end))
			{
				dis[array[i].start][array[i].end]=dis[array[i].end][array[i].start]=0;
				ans+=array[i].val;
			}
		}
		print(ans);
	}
	return 0;
}
