/*
启发式合并

Boring counting
Time Limit: 3000MS		Memory Limit: 98304KB

Description
In this problem we consider a rooted tree with N vertices. The vertices are numbered from 1 to N, and vertex 1 represents the root. There are integer weights on each vectice. Your task is to answer a list of queries, for each query, please tell us among all the vertices in the subtree rooted at vertice u, how many different kinds of weights appear exactly K times?
 
Input
The first line of the input contains an integer T( T<= 5 ), indicating the number of test cases.
For each test case, the first line contains two integers N and K, as described above. ( 1<= N <= 105, 1 <= K <= N )
Then come N integers in the second line, they are the weights of vertice 1 to N. ( 0 <= weight <= 109 )
For next N-1 lines, each line contains two vertices u and v, which is connected in the tree.
Next line is a integer Q, representing the number of queries. (1 <= Q <= 105)
For next Q lines, each with an integer u, as the root of the subtree described above.
 
Output
For each test case, output "Case #X:" first, X is the test number. Then output Q lines, each with a number -- the answer to each query.

Seperate each test case with an empty line.
 
Sample Input
1
3 1
1 2 2
1 2
1 3
3
2
1
3
 
Sample Output
Case #1:
1
1
1

*/

//Result:2012-08-13 14:42:20	Accepted	4358	1515MS	29076K	1657 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
#define pb push_back

typedef map<int,int>::iterator map_iter;

map<int,int> mp[SIZE];
int w[SIZE];
int n,k;
vector<int> g[SIZE];
int local[SIZE],p[SIZE],ans[SIZE];

void merge(int u,int v)
{
	for(map_iter iter=mp[v].begin();iter!=mp[v].end();iter++)
	{
		int val=iter->first;
		int num=iter->second;

		if(mp[u][val]==k) p[u]--;
		mp[u][val]+=num;
		if(mp[u][val]==k) p[u]++;
    }
}


void dfs(int now,int father) 
{
	for(int i=0;i<(int)g[now].size();i++)
	{
		int next=g[now][i];
		if(next!=father)
		{
			dfs(next,now);
			int nv=local[now];
			int nu=local[next];
			if(mp[nv].size()>mp[nu].size())
			{
				merge(nv,nu);
			}
			else
			{
				local[now]=nu;
				merge(nu,nv);
			}
		}
	}
	ans[now]=p[local[now]];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,a,b,q;
	input(T);
	int cas=1;
	while(T--)
	{
		memset(p,0,sizeof(p));
		memset(ans,0,sizeof(ans));
		printf("Case #%d:\n",cas++);
		for(int i=0;i<SIZE;i++)
		{
			g[i].clear();
			mp[i].clear();
		}
		input(n>>k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",w+i);
			mp[i][w[i]]=1;
			if(k==1) p[i]=1;
			local[i]=i;
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			g[a].pb(b);
			g[b].pb(a);
		}
		dfs(1,-1);
		input(q);
		while(q--)
		{
			scanf("%d",&a);
			printf("%d\n",ans[a]);
		}
		if(T) puts("");
	}
	return 0;
}

