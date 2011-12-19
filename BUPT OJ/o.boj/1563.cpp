#include <stdio.h>
#include <stdlib.h>

typedef struct num
{
	int number;
	int sum;
	
	bool operator > (const num& right)
	{
		if(sum>right.sum) return true;
		else if(sum==right.sum)
		{
			if (number<right.number) return true;
			else return false;
		}
		else return false;
	}
}num;

int cmp(const void* a,const void* b)
{
	if(*(num*)b>*(num*)a) return 1;
	else return -1;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int people,sub;
	scanf("%d%d",&people,&sub);
	num *array=new num[people];
	for(int i=0;i<people;i++)
	{
		int num;
		scanf("%d",&num);
		array[i].number=num;
		int grade_sum=0;
		for(int j=0;j<sub;j++)
		{
			int grade;
			scanf("%d",&grade);
			grade_sum+=grade;
		}
		array[i].sum=grade_sum;
	}
	
	qsort(array,people,sizeof(num),cmp);
	
	for(int i=0;i<people;i++)
	{
		printf("%d %d\n",array[i].number,array[i].sum);
	}
	return 0;
}