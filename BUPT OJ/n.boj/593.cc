//Result:593	Accepted	19ms	144kb	G++	416B	2012-05-15 22:22:07	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define inf (1<<25)

int main()
{
	int T;
	input(T);
	while(T--)
	{
		int n,a;
		input(n);
		int ans=-inf;
		for(int i=0;i<n;i++)
		{
			input(a);
			ans=max(ans,a);
		}
		printf("%.3f\n",ans/1.);
	}
	return 0;
}
