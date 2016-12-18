#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 25005
#define EDGE 50005

vector<int> g[SIZE];
int n,m;
int dfn[SIZE],low[SIZE];
stack<int> st;
int bio[SIZE];
int lv,sum;
set<pair<int,int> > road;
char visit[SIZE];

void init()
{
	lv=sum=0;
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	st=stack<int>();
	memset(bio,0,sizeof(bio));
	memset(visit,0,sizeof(visit));
}

void tarjan(int v,int pre)
{
	dfn[v]=low[v]=++lv;
	st.push(v);
	for(int i=0;i<(int)g[v].size();i++)
	{
		int u=g[v][i];
		if(u==pre) continue;
		if(!dfn[u])
		{
			tarjan(u,v);
			low[v]=min(low[v],low[u]);
		}
		else low[v]=min(low[v],dfn[u]);
	}

	if(low[v]==dfn[v])
	{
		int t;
		sum++;
		do
		{
			t=st.top();
			st.pop();
			bio[t]=sum;
		}while(t!=v);
	}
}



int main()
{
    freopen("input.txt", "r", stdin);
    int a,b;
    while(input(n>>m) && n+m)
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i]) tarjan(i, -1);
        }
        int q;
        input(q);
        while (q--) {
            scanf("%d%d", &a, &b);
            puts(bio[a] == bio[b]? "Yes": "No");
        }
    }
    return 0;
}
