#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main()
{
	double a,b;
	while(scanf("%lf%lf",&a,&b)!=EOF)
	{
		printf("%.0f\n",pow(b,1/a));
	}
	return 0;
} 