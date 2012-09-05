//Result:2012-08-08 15:37:37	Accepted	4345	0MS	8476K	1236 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1010

typedef long long llint;

int prime[SIZE];
int cnt;

void init()
{
	cnt=0;
	bitset<SIZE+10> bs;
	for(int i=4;i<SIZE+10;i+=2) bs[i]=1;
	for(int i=3;i<SIZE+10;i+=2)
	{
		for(int j=2;i*j<SIZE+10;j++)
		{
			bs[i*j]=1;
		}
	}
	prime[0]=2;cnt++;
	for(int i=3;i<SIZE+10;i+=2)
	{
		if(!bs[i]) prime[cnt++]=i;
	}
}


llint dp[SIZE+10][SIZE+10];
llint ans[SIZE+10];

llint dfs(int x,int t)
{
	if(dp[x][t]!=-1) return dp[x][t];
	else
	{
		if(prime[t]>x)
		{
			return dp[x][t]=1;
		}
		dp[x][t]=dfs(x,t+1);
		int k=prime[t];
		while(k<=x)
		{
			dp[x][t]+=dfs(x-k,t+1);
			k*=prime[t];
		}
		return dp[x][t];
	}
}
	

int main()
{
	int x;
	init();
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<SIZE;i++)
	{
		ans[i]=dfs(i,0);
	}
	while(input(x)) print(ans[x]);
	return 0;
}
	
	
	
