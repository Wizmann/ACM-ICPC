//Result:wizmann	1639	Accepted	768K	47MS	G++	3433B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<25
#define SIZE 30
#define PARK 0


int n,k;	  //节点总数 度数限制为k
int mst;	 //最终结果：最小k限制度生成树
int g[SIZE][SIZE];   //图
int father[SIZE];  //节点n的父节点
char connect[SIZE][SIZE];  //判断边(i,j)是否加入到生成树中
int best[SIZE];	//从v0到v路径上与v0无关的最大权边的点序号
char visit[SIZE];
map<string,int> mp;//名称->编号映射

void dfs(int now,char *mark)//用DFS把无根树变成有根树
{
	for(int i=0;i<n;i++)
	{
		if(connect[i][now] && mark[i])
		{
			father[i]=now;
			mark[i]=0;
			dfs(i,mark);
		}
	}
}

int prim(int s)//PRIM算法＋生成1度MST
{
	int ans,key;
	int sum = 0;
	
	int dis[SIZE],pre[SIZE];
	char mark[SIZE];

	memset(pre,0,sizeof(pre));
	memset(mark,0,sizeof(mark));
	mark[s]=1;
	visit[s]=1;
	for(int i=0;i<n;i++)
	{
		dis[i]=g[s][i];
		pre[i]=s;
	}
	while(true)
	{
		ans=INF;
		for(int i=0;i<n;i++)
		{
			if(!visit[i] && !mark[i] && dis[i]<ans)
			{
				ans=dis[i];
				key=i;
			}
		}
		if(ans>=INF) break;
		mark[key]=1;
		visit[key]=1;
		connect[pre[key]][key]=connect[key][pre[key]]=1;
		sum+=ans;
		for(int i=0;i<n;i++)
		{
			if(!visit[i] && !mark[i] && dis[i]>g[key][i])
			{
				dis[i]=g[key][i];
				pre[i]=key;
			}
		}
	}
	
	ans=INF;
	int root=-1;	  //找到与v0相关联的点的最小边，加入1条边，生成1度MST
	for(int i=0;i<n;i++)
	{
		if(mark[i] && g[PARK][i]<ans)
		{
			ans=g[PARK][i];
			root=i;
		}
	}
	mark[root]=0;
	dfs(root,mark);//生成有根树
	father[root]=PARK;
	return sum+ans;
}

int findMaxLen(int x)//记忆化搜索PARK到x的最大权值的边
{
	int tmp;
	if(father[x]==PARK) return -1;//如果节点的父节点是PARK，不再查找
	if(best[x]!=-1) return best[x];//如果访问过此节点，返回正确的值
	tmp=findMaxLen(father[x]);
	
	if(tmp!=-1 && g[tmp][father[tmp]]>g[father[x]][x]) best[x]=tmp;//取最长边的编号
	else best[x]=x;//否则就取本节点的编号
	
	return best[x];
}


void solve()
{
	memset(visit,0,sizeof(visit));
	memset(connect,0,sizeof(connect));
	memset(father,-1,sizeof(father));
	visit[PARK]=1;
	int m=0;
	mst = 0;
	//先求m度限制最小生成树
	for(int i=0;i<n;i++)
	{
		if(!visit[i])
		{
			m++;
			mst+=prim(i);
		}
	}
	
	int change;//回路上权值最大的边，用于交换
	int ax,bx,tmp;
	for(int i=0;i<k-m;i++)
	{
		memset(best,-1,sizeof(best));
		for(int j=0;j<n;j++)
		{
			if(best[j]==-1 && father[j]!=PARK) findMaxLen(j);
		}

		int minadd=INF; // 交换边的最小差值
		for(int j=0;j<n;j++)
		{
			if(g[PARK][j]!=INF && father[j]!=PARK)
			{
				ax=best[j];
				bx=father[ax];
				tmp=g[PARK][j]-g[ax][bx];//取差值
				if(tmp<minadd)
				{
					minadd=tmp;
					change=j;
				}
			}
		}
		if(minadd>=0) break;//用于度数不大于k的限制，如果k限制，就不用break了
		
		mst+=minadd;//mst的值减去差值
		ax=best[change];
		bx=father[ax];
		g[ax][bx]=g[bx][ax]=INF;
		father[ax]=bx=PARK;			// 改变生成树，将点ax直接指向源点PARK
		g[ax][PARK]=g[PARK][ax]=g[change][PARK];
		g[PARK][change]=g[change][PARK]=INF;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int m;
	string str;
	n=1;
	mp.clear();
	mp["Park"]=PARK;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++) g[i][j]=INF;
	}
	input(m);
		
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		input(str);
		if(mp.find(str)==mp.end()) mp[str]=n++;
		x=mp[str];
		
		input(str);
		if(mp.find(str)==mp.end()) mp[str]=n++;
		y=mp[str];
		
		input(w);
		if(w<g[x][y]) g[x][y]=g[y][x]=w;
	}
	input(k);
	solve();
	
	print("Total miles driven: "<<mst);
	return 0;
}
