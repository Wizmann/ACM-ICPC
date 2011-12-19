//Result:1094 	Accepted	206MS	16220K	G++	798B	2011-11-03 13:01:39
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2048
#define mul(x) ((x)*(x))
#define INF 1<<25

int array[SIZE];
int n,m;
int dp[SIZE][SIZE];

void slove()
{
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+mul(array[i]-array[i-1]));
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>m))
	{
		memset(array,0,sizeof(array));
		for(int i=1;i<=n;i++) input(array[i]);
		sort(array+1,array+n+1);
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=0;
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=INF;
			}
		}
		dp[2][1]=mul(array[1]-array[2]);
		slove();
		print(dp[n][m]);
	}
	return 0;
}
