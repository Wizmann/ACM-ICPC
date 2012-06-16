//Result:2012-06-16 04:49:40	Moody Wizmann	Factorial	 accepted	1.74	 2.6M	C++ 4.3.2
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int slove(int x,int v)
{
	int mul=v,res=0;
	while(mul<=x)
	{
		res+=x/mul;
		mul*=v;
	}
	return res;
}

int main()
{
	int T,x;
	input(T);
	while(T--)
	{
		input(x);
		print(min(slove(x,5),slove(x,2)));
	}
	return 0;
}
		
