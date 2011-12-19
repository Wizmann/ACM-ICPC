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

int LCM(int a,int b)
{
	return a*b/GCD(a,b);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d %d %d\n",i+1,LCM(a,b),GCD(a,b));
	}
	return 0;
}