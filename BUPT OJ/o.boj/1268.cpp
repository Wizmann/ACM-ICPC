#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AB(int n)
{
	int a=0,b=0;
	while(n>0)
	{
		if(n%2==0) b++;
		else a++;
		
		n/=2;
	}
	if(a>b) return 1;
	else return -1;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=-1)
	{
		int a=0,b=0;
		for(int i=1;i<=n;i++)
		{
			if(AB(i)==1)
			{
				a++;
				//printf("Nr.%d is A\n",i);
			}
			else b++;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}