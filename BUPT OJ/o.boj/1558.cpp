#include <stdio.h>

int GCD(int a,int b)
{
	if(a>=b)
	{
		if(a%b==0) return b;
		else return GCD(b,a%b);
	}
	else return GCD(b,a);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("GCD(%d,%d) = %d\n",a,b,GCD(a,b));
	return 0;
}