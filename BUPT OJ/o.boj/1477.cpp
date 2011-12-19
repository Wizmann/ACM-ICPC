#include <stdio.h>
#include <stdlib.h>

int* creat(int n)
{
	int *ret=(int*)malloc(sizeof(int)*n);
	return ret;
}

int main()
{
	int n,q;
	//freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&q);
	int *queue=creat(n);
	for(int i=0;i<n;i++) scanf("%d",&queue[i]);	
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int sum=0;
		for(int j=a-1;j<=b-1;j++)
		{
			sum+=queue[j];
		}
		printf("%d\n",sum);
	}
	return 0;
}