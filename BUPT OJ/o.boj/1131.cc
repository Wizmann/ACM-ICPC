//Result:1131 	Accepted	3MS	204K	G++	314B	2011-11-30 11:06:23
#include <cstdio>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
	int T,n;
	input(T);
	while(T--)
	{
		input(n);
		int res;
		if(n&1) res=(n/2)*(n/2-1)/2+(n/2+1)*(n/2)/2;
		else res=(n/2)*(n/2-1);
		print(res);
	}
	return 0;
}
