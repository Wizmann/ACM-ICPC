#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);	
	int *array=(int*)malloc(sizeof(int)*n);
	int **matrix=(int**)malloc(sizeof(int*)*n);
	
	for(int i=0;i<n;i++)
	{
		matrix[i]=(int*)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++) scanf("%d",&matrix[i][j]);
		qsort(matrix[i],n,sizeof(int),cmp);		
	}
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++) printf("%d ",matrix[i][j]);
//		printf("\n");
//	}


	
	for(int i=0;i<n;i++) array[i]=matrix[i][(int)n/2];
	qsort(array,n,sizeof(int),cmp);
	
//	for(int i=0;i<n;i++) printf("%d ",array[i]);
//	printf("\n");
	
	printf("%d\n",array[n/2]);
	return 0;
}