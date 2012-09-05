//Result:2012-07-13 11:09:13	Accepted	2009	0MS	236K	235 B	C++	Wizmann
#include <cstdio>
#include <cmath>

int main()
{
	double a;
	int b;
	while(scanf("%lf%d",&a,&b)==2)
	{
		double sum=0;
		for(int i=0;i<b;i++)
		{
			sum+=a;
			a=sqrt(a);
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}

