//Result:2012-09-05 13:17:02	Accepted	4034	109MS	436K	1043 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 0x3f3f3f3f


int g[SIZE][SIZE];
int mp[SIZE][SIZE];
char visit[SIZE][SIZE];
int n;

int slove()
{
	memset(visit,0,sizeof(visit));
	int num=n*n-n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++) if(i!=k && j!=k)
			{
				if(!visit[j][k] && g[j][k]>=g[j][i]+g[i][k])
				{
					visit[j][k]=1;
					g[j][k]=g[j][i]+g[i][k];
					if(g[j][k]==mp[j][k]) num--;
					else if(g[j][k]<mp[j][k]) return INF;
				}
			}
		}
	}
	return num;
}
			

int main()
{
	freopen("input.txt","r",stdin);
	int T,tmp,cas=1;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&tmp);
				g[i][j]=mp[i][j]=tmp==0?INF:tmp;
			}
		}
		int ans=slove();
		printf("Case %d: ",cas++);
		if(ans<INF) print(ans);
		else puts("impossible");
	}
	return 0;
}
