#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		if(n%2==1)
		{
			printf("7");
			n-=3;
		}
		while(n>0)
		{
			printf("1");
			n-=2;
		}	
		printf("\n");
		
		scanf("%d",&n);
	}
	return 0;
}