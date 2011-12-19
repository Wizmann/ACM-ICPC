#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 105

int g[N][N];
int array[N];
int y,x;

int maxArray()
{
	int res=-1<<25;
	int sum=0;
	for(int i=0;i<y;i++)
	{
		if(sum<0) sum=0;
		sum+=array[i];
		if(sum>res) res=sum;
	}
	return res;
}		

int maxMatrix()
{
	int res=-1<<25;
	int temp;
	for(int i=0;i<x;i++)
	{
		memset(array,0,sizeof(array));
		for(int j=i;j<x;j++)
		{
			for(int k=0;k<y;k++) array[k]+=g[k][j];
			temp=maxArray();
			if(res<temp) res=temp;
		}
	}
	return res;
}
			

int main()
{
	
	freopen("input.txt","r",stdin);
	
	while(scanf("%d%d",&y,&x)!=EOF)
	{
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++) scanf("%d",&g[i][j]);
		}
		printf("%d\n",maxMatrix());
	}
	return 0;
}
		
