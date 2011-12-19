#define LOCAL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE sizeof(float)*num

float* creat(int n)
{
	float *ret=(float*)calloc(n,sizeof(float));
	return ret;
}

int cmp(const void *a,const void *b)
{
	return (int) ( *(float*)a - *(float*)b );
}

#ifdef LOCAL
void print(float *line,int num)
{
	for(int i=0;i<num;i++)
	{
		printf("%.2f ",line[i]);
	}	
	printf("\n");
}
#endif

void check(float *sort,float *queue,int num)
{
	for(int i=0;i<num;i++)
	{
		for(int n=0;n<num;n++)
		{
			if(sort[i]==queue[n]) printf("%d",n+1);
		}
		if(i<num-1) printf(" ");
	}
	printf("\n");
}

int main()
{
	int num;
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&num);
	float *queue=creat(num);
	float *sort =creat(num);
	for(int i=0;i<num;i++)
	{
		scanf("%f",&queue[i]);
	}
	memcpy(sort,queue,SIZE);
	qsort(sort,num,sizeof(float),cmp);
	#ifdef LOCAL
	printf("SORT:");
	print(sort,num);
	printf("QUEUE:");
	print(queue,num);
	#endif
	
	check(sort,queue,num);
	return 0;
}
