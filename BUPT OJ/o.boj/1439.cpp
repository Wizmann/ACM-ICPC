#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vote
{
	unsigned int first;
	unsigned int sec;
	int nr;
	
	void setvote(int i,int a,int b)
	{
		nr=i;
		first=a;
		sec=b;
	}
}vote;

int cmp1(const void *a,const void *b)
{
	vote *at,*bt;
	at=(vote*)a;
	bt=(vote*)b;
	
	return (bt->first) - (at->first) ;
}

int cmp2(const void *a,const void *b)
{
	vote *at,*bt;
	at=(vote*)a;
	bt=(vote*)b;
	
	return (bt->sec) - (at->sec) ;
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int N,K;
	scanf("%d%d",&N,&K);
	while(N!=0&&K!=0)
	{
		vote *people=new vote[N];
		
		for(int i=0;i<N;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			people[i].setvote(i,a,b);
		}
		
		qsort(people,N,sizeof(vote),cmp1);
		
		qsort(people,K,sizeof(vote),cmp2);
		
		printf("%d\n",people[0].nr+1);
		
		delete [] people;		
		
		scanf("%d%d",&N,&K);
	}
}