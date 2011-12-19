#include <stdio.h>
#include <math.h>

int mul(int n)
{
	return n*n;
}

int main()
{
	int x1,y1;
	int x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",(mul(x2-x1)+mul(y1+y2)));
	return 0;
}