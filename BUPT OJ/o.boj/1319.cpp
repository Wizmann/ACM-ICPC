#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 12

int matrix[MAX][MAX];

int main()
{
	
	int a,b;
	while(scanf("%d%d",&a,&b)!=-1)
	{
		memset(matrix,0,sizeof(matrix));
		for(int i=0;i<a;i++)
		{
			scanf("%d",&matrix[0][i]);
		}
		for(int i=0;i<a;i++)
		{
			scanf("%d",&matrix[i][0]);
		}
		for(int i=1;i<a;i++)
		{
			for(int k=1;k<a;k++)
			{
				matrix[i][k]=matrix[i-1][k]+matrix[i][k-1]+matrix[i-1][k-1];
			}
		}
		printf("%d\n",matrix[a-1][a-1]);
	}
	return 0;
}
