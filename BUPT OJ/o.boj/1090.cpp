#include <stdio.h>
#include <stdlib.h>

int* creat(int n)
{
	int* temp=(int*)malloc(sizeof(int)*n);
	return temp;
}

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n;
	int *array;
	scanf("%d",&n);
	array=creat(2*n+1);
	for(int i=0;i<2*n+1;i++) scanf("%d",array+i);
	qsort(array,2*n+1,sizeof(int),cmp);
	printf("%d\n",array[n]);
	return 0;
}