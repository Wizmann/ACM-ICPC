#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int g[110][110];
int sum;
int sx,sy;
int y,x;

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&y,&x)!=EOF)
	{
		memset(g,0,sizeof(g));
		sum=0;
		
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++) scanf("%d",&g[i][j]);
		}
		
		for(int i=0;i<y-2;i++)
		{
			for(int j=0;j<x-2;j++)
			{
				int T=0;
				for(int k=0;k<3;k++)
				{
					for(int l=0;l<3;l++)
					{
						T+=g[i+k][j+l];
					}
				}
				if(T>sum)
				{
					sum=T;
					sx=j;
					sy=i;
				}
			}
		}
		
		printf("%d\n%d %d\n",sum,sy+1,sx+1);
	}
	return 0;
}
	
