//Result:wizmann	1985	Accepted	3472K	1110MS	C++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define pb push_back

typedef struct node
{
	int dest,dis;
	inline void setnode(int a,int b)
	{
		dest=a;dis=b;
	}
}node;

int n,ask;
vector<node> g[40010];
bitset<40010> visit;
bitset<40010> temp;
int d=-1,st=1;

void dfs(int pos,int dis)
{
	temp[pos]=1;
	visit[pos]=1;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		if(!temp[g[pos][i].dest])
		{
			dfs(g[pos][i].dest,dis+g[pos][i].dis);
		}
	}
	if(dis>d)
	{
		d=dis;
		st=pos;
	}
}

int main()
{
	int ans=-1;
	int a,b,c;
	char str[20];
	scanf("%d%d",&n,&ask);
	while(ask--)
	{
		scanf("%d%d%d%s",&a,&b,&c,str);
		node t;
		t.setnode(b,c);
		g[a].pb(t);
		t.setnode(a,c);
		g[b].pb(t);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			temp.reset();
			dfs(i,0);
			temp.reset();
			dfs(st,0);
			if(d>ans) ans=d;
		}
	}
	printf("%d\n",ans);
	return 0;
}
