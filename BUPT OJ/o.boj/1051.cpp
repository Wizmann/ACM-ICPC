#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	int x,y;
	scanf("%d%d%d",&n,&x,&y);
	
	double max=sqrt(x*x+y*y);
	for(int i=0;i<n;i++)
	{
		double temp;
		scanf("%lf",&temp);
		if(max>=temp) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}