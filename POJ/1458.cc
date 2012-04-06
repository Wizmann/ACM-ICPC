//Result:wizmann	1458	Accepted	4828K	47MS	G++	613B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

int dp[SIZE][SIZE];
char a[SIZE],b[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%s%s",a+1,b+1)!=EOF)
	{
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;a[i];i++)
		{
			for(int j=1;b[j];j++)
			{
				if(a[i]==b[j])
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+1);
					ans=max(ans,dp[i][j]);
				}
				else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
		print(ans);
	}
	return 0;
}
