#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bean
{
	int num;
	int score;
	
	int countbean(int n)
	{
		return n*score;
	}
}bean;

int cmp(const void *a,const void *b)
{
	bean *at,*bt;
	at=(bean*)a;
	bt=(bean*)b;
	return bt->score - at->score;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	
	int n,group;
	scanf("%d%d",&n,&group);
	while(n!=0&&group!=0)
	{
		bean* array=new bean[group];
		
		for(int i=0;i<group;i++)
		{
			int temp;
			scanf("%d",&temp);
			array[i].num=temp;
		}
		
		for(int i=0;i<group;i++)
		{
			int temp;
			scanf("%d",&temp);
			array[i].score=temp;
		}
		
		qsort(array,group,sizeof(bean),cmp);
		
		int sum=0;
	
		for(int i=0;i<group;i++)
		{
			if(array[i].num<n)
			{
				sum+=array[i].countbean(array[i].num);
				n-=array[i].num;
				continue;
			}
			else if(array[i].num==n)
			{
				sum+=array[i].countbean(array[i].num);
				break;
			}
			else
			{
				sum+=array[i].countbean(n);
				break;
			}
		}
		
		printf("%d\n",sum);
		delete [] array;
		scanf("%d%d",&n,&group);
	}
	

}