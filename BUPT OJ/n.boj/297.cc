#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 310
#define INF 1<<25

int dist[SIZE][SIZE];
int mat[SIZE][SIZE];
int pre[SIZE][SIZE];
int n,m;

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(input(n>>m))
	{
		stack<int> path;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=mat[i][j]=INF;
				pre[i][j]=i;
			}
		}
		while(m--)
		{
			input(a>>b>>c);
			dist[a][b]=dist[b][a]=min(mat[a][b],c);
			mat[a][b]=mat[b][a]=min(mat[a][b],c);
		}
		int minCircle=INF;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<k;i++)
			{
				for(int j=i+1;j<k;j++)
				{
					
					int tmp=dist[i][j]+mat[i][k]+mat[k][j];
					
					if(tmp<minCircle)
					{
						minCircle=tmp;
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
						dist[i][j]=dist[i][k]+dist[k][j];
						pre[i][j]=pre[k][j];
					}
				}
			}
		}
		if(minCircle>=INF) print(-1);
		else
		{
			print(minCircle);
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
			
