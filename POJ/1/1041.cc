//Result:wizmann	1041	Accepted	1084K	235MS	G++	1701B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 50
#define ROAD 2000

typedef struct node
{
	int dest,road;

	node(int i_dest,int i_road)
	{
		dest=i_dest;
		road=i_road;
	}

	friend bool operator < (const node& a,const node& b)
	{
		return a.road<b.road;
	}

}node;

int source;
vector<node> g[SIZE];
int ind;
int in[SIZE];
char visit[ROAD];
stack<int> st;

bool check()
{
	for(int i=0;i<SIZE;i++)
	{
		if(in[i] & 1) return false;
	}
	return true;
}

void dfs(int now)
{
	int sz=(int)g[now].size();
	for(int i=0;i<sz;i++)
	{
		if(!visit[g[now][i].road])
		{
			visit[g[now][i].road]=1;
			dfs(g[now][i].dest);
			st.push(g[now][i].road);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int begin,end,road;
	while(input(begin>>end) && begin+end)
	{
		set<int> hash;
		ind=0;
		memset(visit,0,sizeof(visit));
		memset(in,0,sizeof(in));
		source=min(begin,end);
		for(int i=0;i<SIZE;i++) g[i].clear();
		while(begin+end)
		{
			input(road);
			g[begin].push_back(node(end,road));
			g[end].push_back(node(begin,road));
			in[begin]++;
			in[end]++;
			hash.insert(road);
			input(begin>>end);
		}
		ind=hash.size();
		if(!check()) print("Round trip does not exist.");
		else
		{
			//for(int i=0;i<SIZE;i++) sort(g[i].begin(),g[i].end());
			while(!st.empty()) st.pop();
			dfs(source);
			printf("%d",st.top());
			st.pop();
			while(!st.empty())
			{
				printf(" %d",st.top());
				st.pop();
			}
			print("");
		}
	}
	return 0;
}

