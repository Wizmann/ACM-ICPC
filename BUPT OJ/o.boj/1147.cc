#include <stdio.h>

int a,b,c;

long long pow(int b)
{
	long long temp;
	if(b>1)
	{
		temp=pow(b/2);
		temp%=c;
		temp*=temp;
		temp%=c;
		if(b%2) return (temp*a)%c;
		else return temp;
	}
	else if(b==1) return a;
	else return 1;
}
		

int main()
{
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		a%=c;
		printf("%lld\n",pow(b-1));
	}
	return 0;
}
