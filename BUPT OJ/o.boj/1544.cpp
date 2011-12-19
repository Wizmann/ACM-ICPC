#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int find(int num,int n,int *array) //找到数值，返回下标
{
	for(int i=0;i<n;i++)
	{
		if (array[i]==num) return i;
	}
} 


int main()
{
	freopen("input.txt","r",stdin);
	
	int n;//the number of machine and the field
	int ask;
	scanf("%d%d",&n,&ask);
	while(ask!=0&&n!=0)
	{
		int *machine=new int[n];
		int *field=new int[n];
		int *mach_sort=new int[n];
		int *fie_sort=new int[n];
		
		for(int i=0;i<n;i++) scanf("%d",&machine[i]);
		for(int i=0;i<n;i++) scanf("%d",&field[i]);
		
		memcpy(mach_sort,machine,sizeof(int)*n);
		memcpy(fie_sort,field,sizeof(int)*n);
		
		qsort(mach_sort,n,sizeof(int),cmp);
		qsort(fie_sort,n,sizeof(int),cmp);
		
		 
		for(int i=0;i<ask;i++)
		{
			int temp;
			scanf("%d",&temp);
			int mach_qua=find(machine[temp-1],n,mach_sort);
			printf("%d\n",find(fie_sort[mach_qua],n,field)+1);
		}
		scanf("%d%d",&n,&ask);
	}
	return 0;
}