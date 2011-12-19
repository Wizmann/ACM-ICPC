#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int dis;
	scanf("%d",&dis);
	if(dis%2==0) printf("error\n");
	else
	{
		printf("1");
		printf(" %d",1+dis);
		for(int i=1;i<n-1;i++)
		{
			printf(" %d",1+(2*i+1)*dis);
		}
		printf("\n");
	}
	return 0;
}