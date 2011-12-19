#include <stdio.h>
#include <math.h>

int mul(int i)
{
	return i*i;
}
int main()
{
	int a;
	scanf("%d",&a);
	if(mul( (int) sqrt( (double) a) )==a) printf("Yes\n");
	else printf("No\n");
	return 0;
}