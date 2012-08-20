//Result:wizmann	3071	Accepted	524K	141MS	C++	829B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE (1<<7)+5

double win[SIZE][SIZE];
double dp[SIZE][SIZE];
int n;

int main()
{
	while(input(n) && n>0)
	{
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<(1<<n);j++) input(win[i][j]);
		}

		memset(dp,0,sizeof(dp));
		//dp[i][j]表示第i场时第j只队伍存活下来的概率
		//dp[i][j]=sigma(dp[i-1][j]*p[j][k]*dp[i-1][k])
		for(int i=0;i<(1<<n);i++) dp[0][i]=1.;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				for(int k=0;k<(1<<n);k++)
				{
					if( ((k>>(i-1))^1) == j>>(i-1) )//神处理
					{
						//每队只和其在当轮相邻的队伍进行比赛
						//第一轮00和01可以比赛，01和10就不可以比赛（因为分组不同，见题意）
						//第二轮00x和01x进行比赛
						//etc...
						dp[i][j]+=dp[i-1][j]*dp[i-1][k]*win[j][k];
					}
				}
			}
		}

		int ans=0;

		for(int i=0;i<(1<<n);i++)
		{
			if(dp[n][i]>dp[n][ans]) ans=i;
		}

		print(ans+1);
	}
	return 0;
}
