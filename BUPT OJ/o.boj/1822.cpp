#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	int black=0,white=0;
	int temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==1) white++;
		else if(temp==0) black++;
	}
	printf("%d\n",black-white);
	return 0;
}