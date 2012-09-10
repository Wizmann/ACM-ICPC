//Result:2012-09-10 21:48:28	Accepted	4282	359MS	476K	804 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

llint mul(llint a,int x)
{
	llint res=1;
	while(x)
	{
		if(x&1) res*=a;
		a=a*a;
		x>>=1;
	}
	return res;
}



int slove(llint x)
{
	int res=0;
	for(int i=3;i<32;i++)
	{
		llint up=pow(x,1./i);
		for(llint b=2;b<=up;b++)
		{
			for(llint a=1;a<b;a++)
			{
				llint sum=mul(a,i)+mul(b,i)+a*b*i;
				if(sum==x) res++;
				else if(sum>x) break;
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	llint x;
	while(input(x) && x)
	{
		int ans=0;
		llint t=sqrt(x);
		if(t*t==x) ans+=(t-1)/2;
		ans+=slove(x);
		print(ans);
	}
	return 0;
}

