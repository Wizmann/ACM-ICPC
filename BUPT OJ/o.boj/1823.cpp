#include <stdio.h>
#include <stdlib.h>

#define LOCAL

int *creat(int n)
{
	int *ret=(int*)malloc(sizeof(int)*n);
	return ret;
}

int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		int *array=creat(num);
		double ave=0;
		for(int j=0;j<num;j++)
		{
			scanf("%d",&array[j]);
			ave+=(double)array[j];
		}
		ave/=num;
		int sum=0;
		for(int j=0;j<num;j++)
		{
			if((double)array[j]<=ave) sum++;
		}
		printf("%.3lf%%\n",100-(double)sum/num*100);
		free(array);
	}
	return 0;
}