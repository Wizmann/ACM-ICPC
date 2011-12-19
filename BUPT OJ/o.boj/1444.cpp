#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix[10][10];

int main()
{
	int n;
	scanf("%d",&n);
	
	int tot=0;
	int x=0,y=0;
	while(tot<n*n)
	{
		while(x>=0&&y+1<=n)
		{
			matrix[y][x]=++tot;
			x--;y++;
		}
		x++;y--;
		if(x-1<0&&y+1<n) y++;
		else x++;
		
		while(y>=0&&x+1<=n)
		{
			matrix[y][x]=++tot;
			x++;y--;
		}
		x--;y++;
		if(x+1>=n&&y+1<n) y++;
		else x++;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<n;k++)
		{
			printf("%d ",matrix[i][k]);
		}
		printf("\n");
	}
	return 0;
}