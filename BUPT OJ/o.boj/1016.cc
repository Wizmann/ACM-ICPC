#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000+20
#define INF 1<<30

int matrix[N][N];
char pos[N];

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(matrix,0,sizeof(matrix));
		int temp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&temp);
				if(!temp) matrix[i][j]=INF;
				else matrix[i][j]=temp;
			}
		}
		//***¹¹½¨¾ØÕó***//
		
		memset(pos,0,sizeof(pos));
		pos[0]=1;
		int min;
		int next;
		int sum=0;
		for(int time=0;time<n-1;time++)
		{
			min=1<<30;
			for(int i=0;i<n;i++)
			{
				if(pos[i])
				{
					for(int j=0;j<n;j++)
					{
						if(matrix[i][j]<min&&pos[j]==0)
						{
							min=matrix[i][j];
							next=j;
						}
					}
				}
			}
			sum+=min;
			pos[next]=1;
		}	
		printf("%d\n",sum);	 
	}
	return 0;
}