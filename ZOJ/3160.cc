//Result:2013-01-01 10:23:38	 Accepted	3160	C++	120	728	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define SIZE 333

int n,m;
int array[SIZE];
char cnc[SIZE][SIZE];
int dp[SIZE][SIZE];

int slove()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;i+j<n;j++)
		{
			int st=j,end=i+j;
			int res=max(dp[st][end-1],dp[st+1][end]);
			if(dp[st+1][end-1]==end-st-1 && cnc[array[st]][array[end]])
			{
				res=max(res,dp[st+1][end-1]+2);
			}
			for(int k=st;k<end;k++)
			{
				res=max(res,dp[st][k]+dp[k+1][end]);
			}
			dp[st][end]=res;
		}
	}
	return dp[0][n-1];
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n>>m))
	{
		memset(array,0,sizeof(array));
		memset(cnc,0,sizeof(cnc));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			cnc[a][b]=cnc[b][a]=1;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",array+i);
		}
		print(slove());
	}
	return 0;
}


