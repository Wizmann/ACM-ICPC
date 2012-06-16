/*
 * Problem: 3207		User: wizmann
 * Memory: 2908K		Time: 110MS
 * Language: G++		Result: Accepted
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1010
#define M 512
#define pb push_back

typedef struct edge
{
	int st,end;	
	edge(int a,int b){st=a;end=b;}	
	inline void setedge(int a,int b){st=a;end=b;}
}edge;

int n,m;
int cnc[M][2];
vector<int> g[SIZE];
int lv,cnt;
int dfn[SIZE],low[SIZE];
char visit[SIZE][SIZE];
char in[SIZE];
int color[SIZE];
stack<edge> st;

void slove(int pos)
{
	memset(in,0,sizeof(in));
	while(1)
	{
		edge now=st.top();
		st.pop();
		in[now.st]=in[now.end]=1;//该点在此点双连通分量中
		if(now.st==pos) break;
	}
	for(int i=0;i<(m*2);i++)
	{
		if(in[i]) color[i]=cnt;
	}
	cnt++;
}


void tarjan(int pos)
{
	dfn[pos]=low[pos]=++lv;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int u=g[pos][i];
		if(visit[pos][u]) continue;//判重边pos->u
		visit[pos][u]=visit[u][pos]=1;//无向图
		
		if(!dfn[u])//如果u点没有被访问过
		{
			st.push(edge(pos,u));//压栈
			tarjan(u);//向下搜索
			low[pos]=min(low[pos],low[u]);//low[x]表示x所能到达的最小深度的顶点
			if(dfn[pos]<=low[u]) slove(pos);//如果不能有比pos更小的深度
											//找出找出双连通分量，进行处理
		}
		else low[pos]=min(low[pos],dfn[u]);
	}
}


bool zweiSat()
{
	lv=0;
	bool res=true;
    for(int i=0;i<m*2;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	return res;
}
	

int main()
{
	int a,b;
	cnt=1;
	input(n>>m);
	for(int i=0;i<m;i++)
	{
		input(a>>b);
		if(a>b) swap(a,b);
		cnc[i][0]=a;cnc[i][1]=b;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if((cnc[i][0]<cnc[j][0] && cnc[i][1]>cnc[j][0] && cnc[i][1]<cnc[j][1]) ||
					(cnc[j][0]<cnc[i][0] && cnc[j][1]>cnc[i][0] && cnc[j][1]<cnc[i][1]))
			{
				g[i].pb(j+m);
				g[j+m].pb(i);
				g[j].pb(i+m);
				g[i+m].pb(j);
			}
		}
	}
	bool ans=true;
	zweiSat();
	for(int i=0;i<m;i++)
	{
		if(color[i]==color[i+m] && color[i])
		{
			ans=false;
			break;
		}
	}
	
	if(ans) print("panda is telling the truth...");
	else print("the evil panda is lying again");
	return 0;
}
