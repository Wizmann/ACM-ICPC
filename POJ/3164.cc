//Result:wizmann	3164	Accepted	288K	141MS	C++	2576B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define MUL(x) ((x)*(x))
#define ROOT 1 //起始节点
#define INF 10000000000000.0

typedef struct node
{
	int x,y;
	inline void setnode(int a,int b){x=a;y=b;}
}node;

double dis(node a,node b)
{
	double res=MUL(a.x-b.x)+MUL(a.y-b.y);
	return sqrt(res);
}

double g[110][110];
int np,nc;
node point[110];
char circle[110];
int father[110],visit[110];
double ans;

int excircle()
{
	memset(father,0,sizeof(father));
	father[ROOT]=ROOT;
	for(int i=1;i<=np;i++) if(!circle[i]&&i!=ROOT)
	{
		father[i]=i;//初始化father数组
		g[i][i]=INF;//消除自环
		for(int j=1;j<=np;j++)
		{
			if(!circle[j]&&g[j][i]<g[father[i]][i]) father[i]=j;
			//找出距离j点最近的点，做为j点的前驱点
		}
	}
	for(int i=1;i<=np;i++)
	{
		if(circle[i]) continue;//成环的点已经被缩去，所以不计算
		memset(visit,0,sizeof(visit));
		int t=i;
		while(!visit[t])
		{
			visit[t]=1;
			t=father[t];
		}
		if(t==ROOT) continue;
		//找到最终的父节点，如果是ROOT点，则此点不存在环
		//如果找到的不是ROOT点，则此点有环，反正环的最初访问节点t
		return t;
	}
	return -1;
}

void update(int p)
{
	ans+=g[father[p]][p];
	for(int i=father[p];i!=p;i=father[i])
	{
		ans+=g[father[i]][i];
		circle[i]=1;
	}//将环内的边加到ans里
	
	//更新
	for(int i=1;i<=np;i++)
	{
		if(!circle[i]&&g[i][p]<INF) g[i][p]-=g[father[p]][p];
	}
	for(int i=father[p];i!=p;i=father[i])
	{
		for(int j=1;j<=np;j++)
		{
			if(!circle[j])
			{
				if(g[j][i]<INF) g[j][p]=min(g[j][p],g[j][i]-g[father[i]][i]);
				g[p][j]=min(g[i][j],g[p][j]);
			}
		}
	}
}

void dfs(int p)
{
	visit[p]=1;
	for(int i=1;i<=np;i++)
	{
		if(!visit[i]&&g[p][i]<INF) dfs(i);
	}
}

bool cnc()//判断图是否连通
{
	memset(visit,0,sizeof(visit));
	dfs(ROOT);
	for(int i=1;i<=np;i++)
	{
		if(!visit[i]) return false;
	}
	return true;
}

void edmonds()
{
	memset(circle,0,sizeof(circle));
	while(1)
	{
		int t=excircle();//找出成环的点集
		if(t==-1) break;
		update(t);//类似于缩点的操作
	}

	for(int i=1;i<=np;i++) if(i!=ROOT&&!circle[i])
	{
		ans+=g[father[i]][i];
	}
	printf("%.2lf\n",ans);
}

int main()
{
	int a,b;
	while(scanf("%d%d",&np,&nc)==2)
	{
		ans=0;
		for(int i=1;i<=np;i++)
		{
			for(int j=1;j<=np;j++) g[i][j]=INF;
		}
		for(int i=1;i<=np;i++)
		{
			scanf("%d%d",&a,&b);
			point[i].setnode(a,b);
		}
		for(int i=1;i<=nc;i++)
		{
			scanf("%d%d",&a,&b);
			g[a][b]=dis(point[a],point[b]);
		}
		
		if(!cnc()) puts("poor snoopy");
		else edmonds();
	}
	return 0;
}
