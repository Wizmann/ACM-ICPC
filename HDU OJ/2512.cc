//Result:2012-07-13 11:27:19	Accepted	2512	46MS	16716K	634 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 2048
#define MOD 1000

int dp[SIZE][SIZE];
int ans[SIZE];

void init()
{
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(ans));
	ans[1]=dp[1][1]=1;
	for(int i=2;i<SIZE;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1])%MOD;
			ans[i]+=dp[i][j];
			ans[i]%=MOD;
		}
	}
}

int main()
{
	int T,n;
	init();
	input(T);
	while(T--)
	{
		input(n);
		print(ans[n]);
	}
	return 0;
}
		
