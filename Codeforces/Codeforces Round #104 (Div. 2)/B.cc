#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define elif else if

int getMask(int a)
{
	int res=0,ind=1;
	while(a)
	{
		if(a%10==4 || a%10==7)
		{
			res=res+a%10*ind;
			ind*=10;
		}
		a/=10;
	}
	return res;
}

int main()
{
	int a,b;
	input(a>>b);
	a++;
	while(1)
	{
		if(getMask(a)==b) break;
		else a++;
	}
	print(a);
	return 0;
}
