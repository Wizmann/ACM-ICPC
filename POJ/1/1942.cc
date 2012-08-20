//Result:wizmann	1942	Accepted	712K	0MS	G++	476B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl

long long slove(long long a,long long b)
{
	double ans=1;
	for(long long i=1;i<=a;i++)
	{
		ans*=(double)(b-i+1)/i;
	}
	return (long long)(ans+0.5);
}

int main()
{
	long long m,n;
	while(1)
	{
		input(m);
		input(n);
		if(m+n==0) break;
		else print(slove(min(m,n),m+n));
	}
	return 0;
}
