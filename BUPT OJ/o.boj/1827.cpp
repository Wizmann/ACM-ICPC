#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double input;
	scanf("%lf",&input);
	printf("%.3lf\n",-5730*log2(input));
	return 0;
}