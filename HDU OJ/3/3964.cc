//Result:2012-07-27 16:02:59	Accepted	3964	281MS	528K	1097 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10
#define MOD 23456789

vector<int> g[SIZE+5];
int n;

void dfs(int start,int pos,bitset<SIZE+5> &visit,deque<int> &dq)
{
	dq.push_back(pos);
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int next=g[pos][i];
		if(visit[next] && next==start)
		{
			for(int i=0;i<(int)dq.size();i++)
			{
				printf("%d",dq[i]);
			}
			puts("");
		}
		else if(!visit[next])
		{
			visit[next]=1;
			dfs(start,next,visit,dq);
			visit[next]=0;
 		}
	}
	dq.pop_back();
}


int main()
{
	freopen("input.txt","r",stdin);
	int a;
	while(input(n))
	{
		for(int i=0;i<n;i++)
		{
			g[i].clear();
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a);
				if(a) g[i].push_back(j);
			}
		}
		
		bitset<SIZE+5> visit;
		for(int i=0;i<n;i++)
		{
			//print(visit);
			deque<int> dq;
			visit[i]=1;
			dfs(i,i,visit,dq);
		}
		puts("");
	}
	return 0;
}

