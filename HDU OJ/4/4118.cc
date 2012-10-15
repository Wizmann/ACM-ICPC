//Result:2012-10-13 13:29:18	Accepted	4118	1046MS	7828K	1506 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 102400

typedef long long llint;

struct node
{
	int dest,cost;
	node(){}
	node(int idest,int icost)
	{
		dest=idest;cost=icost;
	}
};

vector<node> g[SIZE];
int n;
int num[SIZE];
char visit[SIZE];

void init()
{
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(num,0,sizeof(num));
	memset(visit,0,sizeof(visit));
}

void dfs()
{
	stack<int> st;
	st.push(1);
	while(!st.empty())
	{
		int now=st.top();
		visit[now]=1;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].dest;
			if(!visit[next]) st.push(next);
		}

		if(st.top()==now)
		{
			for(int i=0;i<(int)g[now].size();i++)
			{
				num[now]+=num[g[now][i].dest];
			}
			num[now]++;
			st.pop();
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b,c;
	input(T);
	int cas=1;
	while(T--)
	{
		printf("Case #%d: ",cas++);
		llint ans=0;
		init();
		input(n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a].push_back(node(b,c));
			g[b].push_back(node(a,c));
		}
		dfs();
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(int)g[i].size();j++)
			{
				int u=i,v=g[i][j].dest;

				if(num[v]>num[u]) swap(u,v);
				ans+=llint(min(num[v],n-num[v]))*g[i][j].cost;
			}
		}
		print(ans);
	}
	return 0;
}




