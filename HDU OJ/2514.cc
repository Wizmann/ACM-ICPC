//Result:2012-07-09 19:37:50	Accepted	2514	0MS	500K	1904 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define inf 1e30
#define eps 1e-9
#define pb push_back

int val[10];

vector<int> g[10];

inline void addedge(int a,int b)
{
	g[a].pb(b);
	g[b].pb(a);
}

void init()
{
	addedge(0,1);addedge(0,2);addedge(0,3);
	addedge(1,2);addedge(1,4);addedge(1,5);
	addedge(2,3);addedge(2,4);addedge(2,5);addedge(2,6);
	addedge(3,5);addedge(3,6);
	addedge(4,5);addedge(4,7);
	addedge(5,6);addedge(5,7);
	addedge(6,7);
}

bool check(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		int next=g[x][i];
		if(abs(val[x]-val[next])==1) return false;
	}
	return true;
}

int main()
{
	freopen("h.txt","r",stdin);
	int cas=1;
	int T,a;
	input(T);
	init();
	while(T--)
	{
		printf("Case %d: ",cas++);
		bitset<10> visit;
		vector<int> start;
		for(int i=0;i<8;i++)
		{
			scanf("%d",&a);
			val[i]=a;
			if(a) visit[a]=1;
			else start.push_back(i);
		}
		int ans=0;
		int ind=0,unused[10];
		int out[10];
		for(int i=1;i<=8;i++)
		{
			if(!visit[i]) unused[ind++]=i;
		}
		do
		{
			for(int i=0;i<(int)start.size();i++)
			{
				val[start[i]]=unused[i];
			}
			bool mark=true;
			for(int i=0;i<8;i++)
			{
				mark&=check(i);
				if(!mark) break;
			}
			if(mark)
			{
				ans++;
				for(int i=0;i<8;i++)
				{
					out[i]=val[i];
				}
			}
			if(ans>1) break;
		}while(next_permutation(unused,unused+ind));
		if(ans>1) print("Not unique");
		else if(ans==0) print("No answer");
		else
		{
			for(int i=0;i<8;i++)
			{
				if(i) printf(" ");
				printf("%d",out[i]);
			}
			puts("");
		}
	}
	return 0;
}
			
