//Result:wizmann	1067	Accepted	728K	0MS	G++	407B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double gold=(1.0+sqrt(5.0))/2.0;

int main()
{
	int m,n;
	while(input(m>>n))
	{
		if(m>n) swap(m,n);
		int t=floor((n-m)*gold);
		if(t==m) print(0);
		else print(1);
	}
	return 0;
}
