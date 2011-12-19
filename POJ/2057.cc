//Result:wizmann	2057	Accepted	4776K	110MS	G++	1296B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define SIZE 1010

int n;
int worm[SIZE];
int tree[SIZE][SIZE];//树的临接表
int suc[SIZE],fail[SIZE];
int leaf[SIZE];

bool myCmp(int u,int v)
{
	return (fail[u]+2)*leaf[v]<(fail[v]+2)*leaf[u];
	//设(leaf[v]/leaf[ROOT])==P[v],(leaf[u]/leaf[ROOT])==P[u],P为概率
	//Delta=P[v]*suc[v]+P[u]*(fail[u]+suc[v])-P[u]*suc[u]-P[v]*(fail[v]+suc[u])
	//Delta为先选u与先选v在期望步数上的差别
	//程序中的fail[u]+2为回到u,v的父节点所需要的步数
	//经整理得此式
}

void slove(int now)
{
	if(!tree[now][0])
	{
		leaf[now]=1;
		fail[now]=0;
		suc[now]=0;
	}

	for(int i=1;i<=tree[now][0];i++) slove(tree[now][i]);

	for(int i=1;i<=tree[now][0];i++)
	{
		leaf[now]+=leaf[tree[now][i]];//统计now点子树的叶节点
		if(!worm[now]) fail[now]+=(fail[tree[now][i]]+2);
		//当worm[now]，则没有失败的情况，直接返回
	}

	int temp[SIZE];
	for(int i=0;i<tree[now][0];i++) temp[i]=tree[now][i+1];

	sort(temp,temp+tree[now][0],myCmp);
	for(int i=1,j=0;i<=tree[now][0];i++)
	{
		suc[now]+=(j+1)*leaf[temp[i-1]]+suc[temp[i-1]];
		//(j+1)是失败的路径长度，leaf[temp[i-1]]是此点的叶节点数，(j+1)*leaf[temp[i-1]]是所有失败节点所走过的失败路径
		j+=fail[temp[i-1]]+2;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	char cmd[5];
	while(scanf("%d",&n),n)
	{
		memset(tree,0,sizeof(tree));
		memset(worm,0,sizeof(worm));
		memset(leaf,0,sizeof(leaf));
		memset(suc,0,sizeof(suc));
		memset(fail,0,sizeof(fail));

		int t;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%s",&t,cmd);
			if(t>0)	tree[t][++tree[t][0]]=i;

			if(*cmd=='Y') worm[i]=1;
		}

		slove(1);
		printf("%.4f\n",(double)suc[1]/leaf[1]);
	}
	return 0;
}
