#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}



int main()
{
	char print[500]="";
	char temp[10]="";
	int n;
	scanf("%d",&n);
	int *array=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&array[i]);
	qsort(array,n,sizeof(int),comp);
	
	int rep=-1;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(rep==array[i]) continue;
		else
		{
			if(count==0) sprintf(temp,"%d",array[i]);
			else sprintf(temp," %d",array[i]);
			rep=array[i];
			count++;
			strcat(print,temp);
		}
	}
	printf("%d\n%s\n",count,print);
	free(array);
	return 0;
}