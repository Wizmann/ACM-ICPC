#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 30
#define INF 1999

int path[N][N];

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&path[i][j]);
			if(!path[i][j]) path[i][j]=INF;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(path[i][j]>path[i][k]+path[k][j]) path[i][j]=path[i][k]+path[k][j];
			}
		}
	}
	
	printf("%d\n",path[0][n-1]);
	return 0;
}
	
