//Result:2012-08-23 22:37:51	Accepted	4394	15MS	308K	870 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1LL<<60

typedef long long llint;

llint zehn[10];

llint dfs(llint x,llint base,int step=0)
{
	if(base*base%zehn[step+1]!=x%zehn[step+1]) return INF;
	else if(base*base%zehn[step+1]==x) return base;
	else
	{
		llint ans=INF;
		for(int i=0;i<=9;i++)
		{
			ans=min(ans,dfs(x,i*zehn[step+1]+base,step+1));
		}
		return ans;
	}
}
			

void init()
{
	zehn[0]=1;
	for(int i=1;i<10;i++)
	{
		zehn[i]=zehn[i-1]*10;
	}
}

int main()
{
	int T,x;
	input(T);
	init();
	while(T--)
	{
		llint ans=INF;
		input(x);
		for(int i=0;i<=9;i++)
		{
			ans=min(ans,dfs(x,i));
		}
		if(ans>=INF) puts("None");
		else print(ans);
	}
	return 0;
}

