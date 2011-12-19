#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pos
{
	int x,y;
	
	void setpos()
	{
		scanf("%d%d",&x,&y);
	}
}pos;

int cmpx(const void *a,const void *b)
{
	pos* ta=(pos*)a;
	pos* tb=(pos*)b;
	
	int res=ta->x-tb->x;
	if(res) return res;
	else return ta->y-tb->y;
}

int cmpy(const void *a,const void *b)
{
	pos* ta=(pos*)a;
	pos* tb=(pos*)b;
	
	int res=ta->y-tb->y;
	if(res) return res;
	else return ta->x-tb->x;
}

pos array[1010];

int abs(int n)
{
	return n>0?n:-n;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++)
		{
			array[i].setpos();
		}
		qsort(array,n,sizeof(pos),cmpx);
		int sum=0;
		for(int i=0;i<n;i+=2)
		{
			sum+=abs(array[i+1].y-array[i].y);
		}
		qsort(array,n,sizeof(pos),cmpy);
		for(int i=0;i<n;i+=2)
		{
			sum+=abs(array[i+1].x-array[i].x);
		}
		
		printf("%d\n",sum);
	}
	return 0;
}