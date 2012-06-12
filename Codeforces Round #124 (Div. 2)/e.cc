#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1520
#define pb push_back

struct point
{
	int x,y;
	int nr;
	point(){}
	point(int i_x,int i_y,int i_nr)
	{
		x=i_x;y=i_y;nr=i_nr;
	}
};

int cmp(const void *a,const void *b)
{
	point *ta=(point*)a;
	point *tb=(point*)b;
	if(ta->x-tb->x==0) return ta->y-tb->y;
	else return ta->x-tb->x;
}

vector<int> g[SIZE];
point array[SIZE];
int ans[SIZE];
int ind=0;
char visit[SIZE];

void dfs(int now)
{
	ans[now]=array[ind].nr;
	visit[now]=1;
	ind++;
	for(int i=0;i<(int)g[now].size();i++)
	{
		if(!visit[g[now][i]]) dfs(g[now][i]);
	}
}

int main()
{
	freopen("e.txt","r",stdin);
	int n,a,b;
	input(n);
	for(int i=0;i<n-1;i++)
	{
		input(a>>b);
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=0;i<n;i++)
	{
		input(a>>b);
		array[i]=point(a,b,i+1);
	}
	qsort(array,n,sizeof(point),cmp);
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) printf(" ");
		printf("%d",ans[i]);
	}
	return 0;
}
		
		
