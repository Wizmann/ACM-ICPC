#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 1<<25

int dp[SIZE][SIZE];
char a[SIZE],b[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(input(n))
	{
		int ans=INF;
		n--;
		scanf("%s",a+1);
		for(int i=0;i<n;i++)
		{
			int t=0;
			memset(dp,0,sizeof(dp));
			scanf("%s",b+1);
			for(int j=1;a[j];j++)
			{
				for(int k=1;b[k];k++)
				{
					if(a[j]==b[k])
					{
						dp[j][k]=max(dp[j][k-1],dp[j-1][k-1]+1);
						t=max(t,dp[j][k]);
					}
					else dp[j][k]=max(dp[j][k-1],dp[j-1][k]);
				}
			}
			ans=min(ans,t);
		}
		
		print(ans);
	}
	return 0;
}
		
