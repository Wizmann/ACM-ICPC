#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	long long min;
	int n;
	while(scanf("%d",&n)!=-1)
	{
		min=0;
		int temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			min^=temp; 
		}
		
		printf("%lld\n",min);
	}
	return 0;
}