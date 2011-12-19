//wizmann	1905	Accepted	260K	0MS	C++	795B	2011-05-28 23:48:29

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>

double l,t;
double c;

inline double lp()
{
	return (double)(1+t*c)*l;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%lf%lf%lf",&l,&t,&c);
	while(1)
	{
		if(l<0) break;
		if(l*t*c<=0) puts("0.000");
		else
		{
			double res=lp();
			double max=(double)INT_MAX;
			double min=0;
			
			while(fabs(max-min)>1e-6)
			{
				double mid=(max+min)/2;
				double angel=asin(l/(2*mid));
				double len=2*angel*mid;
				
				if(len>res) min=mid;
				else max=mid;
			}
			//printf("R:%lf\n",min);
			min-=sqrt(min*min-(l/2)*(l/2));
			std::cout<<std::fixed<<std::setprecision(3)<<min<<std::endl;

		}
		scanf("%lf%lf%lf",&l,&t,&c);
	}
	return 0;
}
