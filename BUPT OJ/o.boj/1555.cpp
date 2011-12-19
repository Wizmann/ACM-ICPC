#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	double a,b;
	char flag;
	scanf("%c",&flag);
	if(flag=='X')
	{
		scanf(":%lf,%lf",&a,&b);
		printf("D:%.3lf\n",sqrt(a*a-b*b));
	}
	else
	{
		scanf(":%lf,%lf",&a,&b);
		printf("X:%.3lf\n",sqrt(a*a+b*b));
	}
	return 0;
}