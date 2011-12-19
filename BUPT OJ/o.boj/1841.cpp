#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combine(int start,int num,int *sum,int i,int *temp)
{
	if(i==num)
	{
		for(int k=0;k<num;k++) printf("%d ",temp[k]+1);
		printf("\n");
		(*sum)++;
	}
	else
	{
		while(start--)
		{
			temp[i]=start;
			combine(start,num,sum,i+1,temp);
		}
	}
}

int main()
{
	int start,num;
	int sum=0;
	scanf("%d,%d",&start,&num);
	int *temp=(int*)malloc(sizeof(int)*num);
	memset(temp,0,sizeof(int)*num);
	combine(start,num,&sum,0,temp);
	printf("%d\n",sum);
	return 0;
}