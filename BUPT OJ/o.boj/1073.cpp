#include <stdio.h>

int main()
{
	int black=0,white=0,temp;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==0) black++;
		if(temp==1) white++;
	}
	printf("%d\n",black-white);
	return 0;
}