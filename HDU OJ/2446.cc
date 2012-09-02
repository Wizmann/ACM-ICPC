//Result:2012-09-01 21:31:08	Accepted	2446	171MS	308K	1009 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;
typedef unsigned long long ullint;

ullint getsum(ullint n)
{
	return n*(n+1)/2*(n+2)/3;
}

ullint getsumy(ullint n)
{
	return n*(1+n)/2;
}

llint findx(ullint x)
{
	llint l=1,r=3900000;
	while(l<=r)
	{
		llint mid=(l+r)>>1;
		if(getsum(mid)>=x) r=mid-1;
		else l=mid+1;
	}
	return r;
}

llint findy(ullint y)
{
	llint l=1,r=3900000;
	while(l<=r)
	{
		llint mid=(l+r)>>1;
		if(getsumy(mid)>=y) r=mid-1;
		else l=mid+1;
	}
	return r;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	ullint x;
	input(T);
	//printf("%.lf\n",getsum(96440));
	while(T--)
	{
		ullint a,b,c;
		input(x);
		if(x==0) puts("1 1 1");
		else
		{
			a=findx(x)+1;
			b=x-getsum(a-1);
			ullint tmp=b;
			b=findy(b)+1;
			c=tmp-getsumy(b-1);
			print(a<<' '<<b<<' '<<c);
		}
	}
	return 0;
}
