//Result:wizmann	2151	Accepted	504K	79MS	C++	1270B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define elif else if
#define INF 1<<25
#define eps 1e-5

int m,t,n;
double team[1024][32];
		
double getRes()
{
	double res=1;
	double ret=1;
	double dp[32][32];
	for(int i=0;i<t;i++)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(!k) dp[j][k] = dp[j-1][k]*(1-team[i][j-1]);
				else dp[j][k]=dp[j-1][k-1]*team[i][j-1]+dp[j-1][k]*(1-team[i][j-1]);
			}
		}
		res*=(1-dp[m][0]);
		double p = 0;
		for(int i=1;i<n;i++) p+=dp[m][i];
		ret*=p;
	}
	return res-ret;
}

int main()
{
	while(scanf("%d%d%d",&m,&t,&n)==3)
	{
		memset(team,0,sizeof(team));
		if(m+t+n==0) break;
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<m;j++) input(team[i][j]);
		}
		double res=getRes();
		printf("%.3f\n",res);
	}
	return 0;
}
