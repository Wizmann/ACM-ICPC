#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	freopen("input.txt","r",stdin);

	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		if(N==0)
		{
			printf("\n");
			continue;
		}
		int** queue=new int*[N];
		int sum=0;
		for(int j=0;j<N;j++)
		{
			int n;
			scanf("%d",&n);
			sum+=n;
			queue[j]=new int[n+1];
			queue[j][n]=-1;
			for(int k=0;k<n;k++) scanf("%d",&queue[j][k]);
			//print(queue[j]);
			//printf("\n");
		}
		int *sort= new int[sum];
		int num=0;
		for(int j=0;j<N;j++)
		{
			int sex=0;
			while(queue[j][sex]!=-1)
			{
				sort[num++]=queue[j][sex++];
			}
		}

		qsort(sort,sum,sizeof(int),cmp);

		/*
for(int j=0;j<sum;j++) printf("%d ",sort[j]);
		printf("\n");*/

		int temp=sort[0];
		printf("%d",temp);
		for(int j=1;j<sum;j++)
		{
			if(sort[j]!=temp) printf(" %d",sort[j]);
			temp=sort[j];
		}
		printf("\n");
	}
	return 0;
}