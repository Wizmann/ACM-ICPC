//Result:wizmann	1734	Accepted	388K	32MS	C++	1747B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 110
#define INF 1<<25

int mat[SIZE][SIZE];
int dist[SIZE][SIZE];
int pre[SIZE][SIZE];
int n,m;


int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	
	while(input(n>>m))//n个点，m条边
	{
		stack<int> path;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mat[i][j]=dist[i][j]=INF;
				pre[i][j]=i;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			mat[a][b]=mat[b][a]=dist[a][b]=dist[b][a]=min(mat[a][b],c);
		}

		int mindis=INF;
		for(int k=1;k<=n;k++)//最短路径外一点将最短路首尾链接,那么就得到一个最小环
		{
			for(int i=1;i<k;i++)
			{
				for(int j=i+1;j<k;j++)
				{
					//求最小环不能用两点间最短路松弛,因为(i,k)之间的最短路,(k,j)之间的最短路可能有重合的部分
					//所以mat[][]其实是不更新的,这里和单纯的floyd最短路不一样
					//dist[i][j]保存的是 i 到 j 的最短路权值和
					int tmp=dist[i][j]+mat[i][k]+mat[k][j];//这里 k 分别和 i 还有 j 在mat中直接相连
					if(tmp<mindis)
					{
						mindis=tmp;
						while(!path.empty()) path.pop();
						int p=j;
						while(p!=i)
						{
							//回溯
							path.push(p);
							p=pre[i][p];//pre[i][j]表示i到j最短路径上,在j前面的一个点
						}
						path.push(i);
						path.push(k);
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dist[i][j]>dist[i][k]+dist[k][j])
					{
						dist[i][j]=dist[i][k]+dist[k][j];//dist[][]保存两点间最短距离
						pre[i][j]=pre[k][j];
					}
				}
			}
		}
		if(mindis==INF) puts("No solution.");
		else
		{
			//print(mindis);
			//输出最小环的路径
			printf("%d",path.top());
			path.pop();
			while(!path.empty())
			{
				printf(" %d",path.top());
				path.pop();
			}
			puts("");
		}
	}
	return 0;
}
