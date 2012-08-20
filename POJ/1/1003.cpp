#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	double cut;
	double val;
	scanf("%lf",&val);
	while(val>1e-5)
	{
		double sum=0;
		int i;
		for(i=1;/*Do Nothing*/;i++)
		{
			if(sum>val) break;
			else sum+=(double)1/(i+1);
		}
		printf("%d card(s)\n",i-1);
		scanf("%lf",&val);	
	}
	return 0;
}