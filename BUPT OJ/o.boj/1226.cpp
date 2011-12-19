#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n>0) printf("%d\n",( (1+n)*n )/2);
	else printf("%d\n",( (-1+n)*(-n) )/2+1);
	return 0;
}