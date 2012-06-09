//Result:1481	Accepted	54MS	216K	G++	 749B	2012-06-10 01:01:50	Wizmann
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

llint mod(llint a,llint b,llint c)
{
	if(b==0) return 1;
	else if(b==1) return a%c;
	else
	{
		llint tmp=mod(a,b>>1,c);
		tmp=(tmp*tmp)%c;
		if(b&1) return (tmp*a)%c;
		else return tmp;
	}
}


llint slove(llint m,llint n)
{
	if(m==0) return 0;
	else if(m==1) return 1;
	else
	{
		llint tmp=slove(m>>1,n);
		tmp=(tmp+tmp*mod(10,m>>1,n))%n;
		if(m&1) return (tmp+mod(10,m-1,n))%n;
		else return tmp;
	}
}
		

int main()
{
	freopen("input.txt","r",stdin);
	int m,n;
	while(input(m>>n) && m+n)
	{
		print(slove(m,n));
	}
	return 0;
}
