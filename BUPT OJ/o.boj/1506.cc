//Result:1506 	Accepted	4MS	252K	G++	568B	2011-10-31 17:25:23	Wizmann 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl

int love[32];
int candy[2],a;

int main()
{
	int t,n;
	input(t);
	while(t--)
	{
		double ans=1;
		input(n);
		memset(love,n,sizeof(love));
		for(int i=0;i<n;i++) input(love[i]);
		input(candy[0]>>candy[1]>>a);
		for(int i=0;i<n;i++)
		{
			ans*=(double)candy[love[i]]/(candy[0]+candy[1]);
			candy[love[i]^1]+=a;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}


