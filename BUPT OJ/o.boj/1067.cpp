#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int sum=2e30;
	int x,y;
	
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i*j>=n)
			{
				if(sum>=i+j)
				{
					sum=i+j;
					x=i;
					y=j;
				}
			}
		}
	}
	
	printf("%d %d\n",y,x);
	return 0;
}