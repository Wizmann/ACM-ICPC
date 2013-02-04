//Result:2013-01-20 11:58:32	Accepted	4028	265MS	14132K	1037 B	C++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 40

typedef long long llint;

map<llint,llint> dp[SIZE+5];
int n;
llint m;

llint gcd(llint a, llint b)
{
	llint t;
	while(b)
	{
		t=a;
		a=b;
		b=t%b;
	}
	return a;
}

llint lcm(llint a,llint b)
{
	return a*b/gcd(a,b);
}

void init()
{
	map<llint,llint>::iterator iter;
	dp[1][1]=1;
	for(int i=2;i<=SIZE;i++)
	{
		dp[i]=dp[i-1];
		dp[i][i]+=1;
		for(iter=dp[i-1].begin();iter!=dp[i-1].end();iter++)
		{
			dp[i][lcm(i,iter->first)]+=iter->second;
		}
	}
}


llint solve()
{
	map<llint,llint>::iterator iter;
	llint res=0;
	for(iter=dp[n].begin();iter!=dp[n].end();iter++)
	{
		if(iter->first>=m) res+=iter->second;
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,cas=1;
	input(T);
	init();
	while(T--)
	{
		input(n>>m);
		printf("Case #%d: ",cas++);
		print(solve());
	}
	return 0;
}
		

