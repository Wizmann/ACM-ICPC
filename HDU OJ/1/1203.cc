//Result:Accepted	1203	203MS	424K	811 B	G++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10240
#define llint long long
#define INF 1LL<<60

double dp[SIZE];
bitset<SIZE> bs;

int main()
{
	freopen("j.txt","r",stdin);
	int n,m;
	int weight;
	double val;
	while(input(n>>m) && m+n)
	{
		for(int i=0;i<=n;i++) dp[i]=1.0;
		bs.reset();
		dp[0]=1;bs[0]=1;
		for(int i=0;i<m;i++)
		{
			input(weight>>val);
			val=1.0-val;
			for(int j=n;j>=0;j--)
			{
				if(bs[j]&&j+weight<=n)
				{
					bs[j+weight]=1;
					dp[j+weight]=min(dp[j+weight],val*dp[j]);
				}
			}
		}
		double ans=1.0;
		for(int i=n;i>=0;i--) ans=min(ans,dp[i]);
		printf("%.1lf%%\n",(1-ans)*100);
	}
	return 0;
}
