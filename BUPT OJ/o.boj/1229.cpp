#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int *array=new int[n];
	for(int i=0;i<n;i++) scanf("%d",&array[i]);
	
	qsort(array,n,sizeof(int),cmp);
	
	int sum=0;
	
	for(int i=0;i<n/2+1;i++)
	{
		sum+=array[i]/2+1;
	}
	
	printf("%d\n",sum);
	
	return 0;
}