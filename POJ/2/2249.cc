#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	long long a,b;
	double res;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		if(a==0&&b==0) break;
		
		long long t=b;
		if(t>a-t)
		{
			t=a-t;
			b=a-b;
		}
		res=1;
		for(long long i=0;i<t;i++)
		{
			res*=(double)a/b;
			a--;
			b--;
		}
		
		printf("%.0f\n",res);
	}
	return 0;
}
