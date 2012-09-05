//Result:2012-07-12 11:32:20	Accepted	3804	2203MS	8636K	1963 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100005
#define pb push_back

/*
 * 1.注意审题
 * 2.学习用Stack模拟栈
 */


struct node
{
	int dest,cost;
	node(){}
	node(int i_dest,int i_cost)
	{
		dest=i_dest;cost=i_cost;
	}
};

struct problem
{
	int val,nr,next;
	
	problem(){}
	problem(int i_val,int i_nr,int i_next)
	{
		val=i_val;nr=i_nr;next=i_next;
	}
};

vector<node> g[SIZE];
int n;
multiset<int> query;
int ans[SIZE];
int head[SIZE];
problem pro[SIZE];
int ind;

void addquery(int a,int val,int nr)
{
	pro[ind]=problem(val,nr,head[a]);
	head[a]=ind++;
}

void ask(int x)
{
	for(int i=head[x];i!=-1;i=pro[i].next)
	{
		problem now=pro[i];
		multiset<int>::iterator iter=query.upper_bound(now.val);
		iter--;
		ans[now.nr]=(*iter);
	}
}
	

void dfs()
{
	stack<node> st;
	bitset<SIZE> visit;
	st.push(node(1,-1));
	while(!st.empty())
	{
		node now=st.top();
		int d=now.dest;
		int l=now.cost;
		
		if(!visit[d])
		{
			visit[d]=1;
			query.insert(l);
			ask(d);
			for(int i=0;i<(int)g[d].size();i++)
			{
				node next=g[d][i];
				if(!visit[next.dest]) st.push(node(next.dest,next.cost));
			}
		}
		else
		{
			query.erase(query.find(l));
			st.pop();
		}
	}
}
			
int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b,c,q;
	input(T);
	while(T--)
	{
		memset(head,-1,sizeof(head));
		ind=0;
		scanf("%d",&n);
		memset(ans,0,sizeof(ans));
		for(int i=0;i<SIZE;i++) g[i].clear();
		query.clear();
		query.insert(-1);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a].pb(node(b,c));
			g[b].pb(node(a,c));
		}
		input(q);
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&a,&b);
			addquery(a,b,i);
		}
		dfs();
		for(int i=0;i<q;i++)
		{
			printf("%d\n",ans[i]);
		}		
	}
	return 0;
}
