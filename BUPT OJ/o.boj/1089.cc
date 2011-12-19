#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x


int main()
{
	int n;
	while(input(n) && n)
	{
		long long ans=0;
		for(int i=n;i>=2;i--)
		{
			ans+=(n-i+1)*(n-i+1)*(i-1);
		}
		print(ans);
	}
	return 0;
}
