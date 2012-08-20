//Result:wizmann	2115	Accepted	164K	0MS	C++	735B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

// (A + C*x) MOD 2^D == B

long long x,y;

long long eEuclid(long long a,long long b)
{
	long long ret;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	else
	{
		ret=eEuclid(b,a%b);
		long long t=x;
		x=y;
		y=t-a/b*y;
		return ret;
	}
}

long long solve(long long a,long long b,long long n)
{
	long long d=eEuclid(a,n);
	if(b%d!=0) return -1;
	long long e=x*(b/d)%n+n;
	return e%(n/d);
}

int main()
{
	freopen("input.txt","r",stdin);
	long long a,b,c,d;
	while(1)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a+b+c+d==0) break;
		d=(1LL<<d);
		long long ans=solve(c,b-a,d);
		if(ans==-1) puts("FOREVER");
		else printf("%lld\n",ans);
	}
	return 0;
}
	
