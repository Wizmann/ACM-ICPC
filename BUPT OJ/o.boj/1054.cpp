#include <stdio.h>
#include <stdlib.h>

int comp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int array[3];
	for(int i=0;i<3;i++)
	{
		scanf("%d",&array[i]);
	}
	char name[3];
	scanf("\n");
	for(int i=0;i<3;i++)
	{
		scanf("%c",&name[i]);
	}
	qsort(array,3,sizeof(int),comp);
	int flag=0;
	for(int i=0;i<3;i++)
	{
		int print;
		if(name[i]=='A') print=array[0];
		else if(name[i]=='B') print=array[1];
		else if(name[i]=='C') print=array[2];
		
		if(flag==0)
		{
			printf("%d",print);
			flag=-1;
		}
		else printf(" %d",print);
	}
	printf("\n");
	return 0;
}