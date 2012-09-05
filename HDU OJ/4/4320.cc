//Result:2012-08-01 23:40:04	Accepted	4320	15MS	312K	440 B	C++	Wizmann
#include <cstdio>
#include <iostream>
using namespace std;
#define print(x) cout<<x<<endl
#define input(x) cin>>x
typedef long long llint;
llint gcd(llint a,llint b){return b?gcd(b,a%b):a;}
int main()
{
	int T,cas=1;
	llint a,b;
	input(T);
	while(T--)
	{
		printf("Case #%d: ",cas++);
		input(a>>b);
		while(1)
		{
			llint t=gcd(a,b);
			if(t<=1) break;
			else a/=t;
		}
		puts(a==1?"YES":"NO");
	}
	return 0;
}
