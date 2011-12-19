#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		int len;
		scanf("%d",&len);
		int *array=(int*)malloc(sizeof(int)*len);
		
		for(int i=0;i<len;i++) scanf("%d",&array[i]);
		
		qsort(array,len,sizeof(int),cmp);
		
		//for(int i=0;i<len;i++) printf("%d ",array[i]);
		//printf("\n");
		
		int start=(array[0]+array[len-1]-1)/2;
		int path=0;
		path+=start-array[0];
		path+=array[len-1]-array[0];
		path+=array[len-1]-start;
		
		printf("%d\n",path);
	}
	return 0;
}