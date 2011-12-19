#include <stdio.h>
#include <stdlib.h>

int main()
{
	float Vs,Vi,f;
	scanf("%f,%f,%f",&Vs,&Vi,&f);
	f=(340-Vi)*f/(340-Vs);
	printf("%.2f\n",f);
	return 0;	
}