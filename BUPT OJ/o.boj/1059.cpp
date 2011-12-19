#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int array[9];
	int sum=0;
	for(int i=0;i<9;i++)
	{
		scanf("%d",&array[i]);
		sum+=array[i];
	}
	
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(array[i]+array[j]==sum-100) goto end;
		}
	}
	
	end:
	
	for(int k=0;k<9;k++)
	{
		if(k!=i&&k!=j)	printf("%d\n",array[k]);
	}
	
	return 0;
}