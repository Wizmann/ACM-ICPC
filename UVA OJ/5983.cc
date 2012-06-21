//Result:	5983	MAGRID	Accepted	C++	1.664	2012-06-21 13:30:33
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 1<<30

const int mx[]={0,1};
const int my[]={1,0};

int r,c;
int g[SIZE][SIZE];
int dp[SIZE][SIZE];

bool DP(int val)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i+j==0) dp[i][j]=val;
			else
			{
				dp[i][j]=-INF;
				if(i-1>=0) dp[i][j]=max(dp[i][j],dp[i-1][j]+g[i][j]);
				if(j-1>=0) dp[i][j]=max(dp[i][j],dp[i][j-1]+g[i][j]);
			}
			if(dp[i][j]<=0) dp[i][j]=-INF;
		}
	}
	return dp[r-1][c-1]>-INF;
}
	

int main()
{
	freopen("a.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&r,&c);
		int left=0,right=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				scanf("%d",&g[i][j]);
				if(g[i][j]<0) right+=abs(g[i][j]);
			}
		}
		while(left<=right)
		{
			int mid=(left+right)>>1;
			//print(left<<' '<<right);
			if(DP(mid)) right=mid-1;
			else left=mid+1;
		}
		//while(!dfs(0,0,left)) left++;
		printf("%d\n",left);
	}
	return 0;
}
		
