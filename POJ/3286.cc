//Result:wizmann	3286	Accepted	728K	204MS	G++	744B	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12

typedef long long llint;

llint zehn[SIZE];

void init()
{
	zehn[0]=1;
	for(int i=1;i<SIZE;i++)
	{
		zehn[i]=zehn[i-1]*10;
	}
}

llint count(llint x)
{
	llint ans=0;
	for(int i=1;i<SIZE;i++)
	{
		llint res=x/zehn[i]-1;
		ans+=res*zehn[i-1];
		int m=(x%zehn[i]-x%zehn[i-1])/zehn[i-1];
		if(m>0) ans+=zehn[i-1];
		else if(m==0) ans+=x%zehn[i-1]+1;
		if(x<zehn[i]) break;
	}
	return ans;
}

int main()
{
	llint m,n;
	init();
	while(input(m>>n) && m+n>0)
	{
		print(count(n)-count(m-1));
	}
	return 0;
}


