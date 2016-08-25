/*

Street Directions
Time Limit: 1000MS		Memory Limit: 10000KB

Description
According to the Automobile Collision Monitor (ACM), most fatal traffic accidents occur on two-way streets. In order to reduce the number of fatalities caused by traffic accidents, the mayor wants to convert as many streets as possible into one-way streets. You have been hired to perform this conversion, so that from each intersection, it is possible for a motorist to drive to all the other intersections following some route. 

You will be given a list of streets (all two-way) of the city. Each street connects two intersections, and does not go through an intersection. At most four streets meet at each intersection, and there is at most one street connecting any pair of intersections. It is possible for an intersection to be the end point of only one street. You may assume that it is possible for a motorist to drive from each destination to any other destination when every street is a two-way street. 
Input
The input consists of a number of cases. The first line of each case contains two integers n and m. The number of intersections is n (2 <= n <= 1000), and the number of streets is m. The next m lines contain the intersections incident to each of the m streets. The intersections are numbered from 1 to n, and each street is listed once. If the pair i j is present, j i will not be present. End of input is indicated by n = m = 0. 
Output
For each case, print the case number (starting from 1) followed by a blank line. Next, print on separate lines each street as the pair i j to indicate that the street has been assigned the direction going from intersection i to intersection j. For a street that cannot be converted into a one-way street, print both i j and j i on two different lines. The list of streets can be printed in any order. Terminate each case with a line containing a single `#' character. 

Note: There may be many possible direction assignments satisfying the requirements. Any such assignment is acceptable. 
Sample Input
7 10
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
2 5
3 6
7 9
1 2
1 3
1 4
2 4
3 4
4 5
5 6
5 7
7 6
0 0
Sample Output
1

1 2
2 4
3 1
3 6
4 3
5 2
5 4
6 4
6 7
7 5
#
2

1 2
2 4
3 1
4 1
4 3
4 5
5 4
5 6
6 7
7 5
#
*/

//Result:wizmann	1515	Accepted	1376K	141MS	C++	1821B	2012-09-20 16:21:21
//给你一个无向公路网，让你改造一些道路为单向，使改造后的公路网成为一个强连通分量
//并输出公路网的结构

//首先使用边双连通分量，求出图中的桥，桥必须为双向的
//然后用DFS，求出最后的结果

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

vector<int> g[SIZE];
int n,m;
int dfn[SIZE],low[SIZE];
stack<int> st;
int bio[SIZE];
int lv,sum;
set<pair<int,int> > road;
char visit[SIZE];
char inst[SIZE][SIZE];

void init()
{
	lv=sum=0;
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	st=stack<int>();
	memset(bio,0,sizeof(bio));
	memset(visit,0,sizeof(visit));
	memset(inst,0,sizeof(inst));
}

void dfs(int x,int fa)
{
	for(int i=0;i<(int)g[x].size();i++) if(g[x][i]!=fa)
	{
		if(bio[x]==bio[g[x][i]] && !inst[x][g[x][i]])
		{
			printf("%d %d\n",g[x][i],x);
		}
		else if(!inst[x][g[x][i]])
		{
			printf("%d %d\n",x,g[x][i]);
			printf("%d %d\n",g[x][i],x);
		}
		inst[x][g[x][i]]=inst[g[x][i]][x]=1;
		if(!visit[g[x][i]])
		{
			visit[g[x][i]]=1;
			dfs(g[x][i],x);
		}
	}
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
	freopen("input.txt","r",stdin);
	int a,b,cas=1;
	while(input(n>>m) && n+m)//n为点数，m为边数,点的编号为[1..n]
	{
		printf("%d\n\n",cas++);
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i,-1);
		}
		dfs(1,-1);//输出强连通分量中需要连的边
		puts("#");
	}
	return 0;
}


