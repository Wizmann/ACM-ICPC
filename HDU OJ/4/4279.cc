//Result:2012-09-10 14:22:03	Accepted	4279	46MS	472K	594 B	G++	Wizmann
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

llint slove(llint x)
{
	if(x<=5) return 0;
	llint res=(x-5+1)/2;
	llint now=sqrt(x-1);
	while(now*now<=x) now++;
	now--;
	
	llint odd=(now+1)/2-2;
	llint even=(now)/2-2;
	
	res=res+odd-even;
	return res;
	
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	llint a,b;
	input(T);
	while(T--)
	{
		input(a>>b);
		print(slove(b)-slove(a-1));
	}
	return 0;
}
		
