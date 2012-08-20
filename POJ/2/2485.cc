#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 500+10
#define MAX 1<<30
#define MIN -1

int matrix[N][N];
int pos[N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<x;j++)
			{
				scanf("%d",&matrix[i][j]);
				if(matrix[i][j]==0) matrix[i][j]=MAX;
			}
		}
		memset(pos,0,sizeof(pos));
		
		pos[0]=1;
		int num=1;
		int max=MIN;
		while(num<x)
		{
			int min=MAX;
			int plus;
			for(int i=0;i<num;i++)
			{
				for(int j=0;j<x;j++)
				{
					if(min>matrix[pos[i]][j])
					{
						min=matrix[pos[i]][j];
						plus=j;
					}
				}
			}
			pos[num]=plus;
			if(min>max) max=min;
			for(int i=0;i<num;i++)
			{
				matrix[pos[i]][plus]=MAX;
				matrix[plus][pos[i]]=MAX;
			}
			num++;
		}
		printf("%d\n",max);
	}
	return 0;
}