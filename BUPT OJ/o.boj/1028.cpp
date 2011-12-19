#include <stdio.h>
#include <stdlib.h>

int* creat(int n)
{
	int *ret=(int*)malloc(sizeof(int)*n);
	return ret;
}

int comp(const void *a,const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	int *sweet,*nor;
	int s,n;
	int sum=0;
	scanf("%d%d",&s,&n);
	sweet=creat(s);
	nor=creat(n);
	for(int i=0;i<s;i++) scanf("%d",&sweet[i]);
	for(int i=0;i<n;i++) scanf("%d",&nor[i]);
	qsort(sweet,s,sizeof(int),comp);
	qsort(nor,n,sizeof(int),comp);
	for(int i=0;i<s;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(sweet[i]>nor[j])
			{
		    	sum++;
		    	break;
			}
		}
		sum++;
	}
	printf("%d\n",sum);
	return 0;		
}