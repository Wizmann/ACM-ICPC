#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n>60) printf("0.800\n");
	else
	{
		float cut=0.6;
		cut=pow(cut,4-n/15);
		printf("%.3f\n",cut);
	}
	return 0;
}