#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>

#define MAX 100100
#define pb push_back 

using namespace std;

priority_queue < int, vector<int>, greater<int> > heap;
vector<int> g[MAX];
int dis[MAX];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,ask;
	while( scanf("%d%d",&n,&ask)!=EOF&& (n||ask) )
	{
		memset(dis,0,sizeof(dis));
		while(!heap.empty()) heap.pop();
		for(int i=1;i<=n;i++) g[i].clear();
		int a,b;
		while(ask--)
		{
			scanf("%d%d",&a,&b);
			g[a].pb(b);
			dis[b]++;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!dis[i]) heap.push(i);
		}
		
		printf("ORDER:");
		while(!heap.empty())
		{
			int t=heap.top();
			printf(" %d",t);
			heap.pop();
			for(int i=0;i<(int)g[t].size();i++)
			{
				int j=g[t][i];
				dis[j]--;
				if(!dis[j]) heap.push(j);
			}
		}
		printf("\n");
	}
	return 0;
}
