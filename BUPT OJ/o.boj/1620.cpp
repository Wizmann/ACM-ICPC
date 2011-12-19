#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	double val;char sign[5];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %s",&val,sign);
		printf("%d ",i+1);
		if(!strcmp(sign,"kg")) printf("%.4lf lb",2.2046*val);
		if(!strcmp(sign,"l")) printf("%.4lf g",0.2642*val);
		if(!strcmp(sign,"lb")) printf("%.4lf kg",0.4536*val);
		if(!strcmp(sign,"g")) printf("%.4lf l",3.7854*val);
		printf("\n");
	}
	return 0;
}