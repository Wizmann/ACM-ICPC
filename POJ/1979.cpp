#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char maze[25][25];
int sum;
int x,y;

void make(int sx,int sy)
{
	if(sy+1<y&&maze[sy+1][sx]!='#')
	{
		maze[sy+1][sx]='#';
		sum++;
		make(sx,sy+1);
	}
	if(sy-1>=0&&maze[sy-1][sx]!='#')
	{
		maze[sy-1][sx]='#';
		sum++;
		make(sx,sy-1);
	}
	if(sx-1>=0&&maze[sy][sx-1]!='#')
	{
		maze[sy][sx-1]='#';
		sum++;
		make(sx-1,sy);
	}
	if(sx+1<x&&maze[sy][sx+1]!='#')
	{
		maze[sy][sx+1]='#';
		sum++;
		make(sx+1,sy);
	}	
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int ix,iy;
	scanf("%d%d",&x,&y);
	while(x!=0&&y!=0)
	{
		sum=0;
		memset(maze,0,sizeof(maze));
		scanf("\n");
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++)
			{
				scanf("%c",&maze[i][j]);
				if(maze[i][j]=='@')
				{
					ix=j;iy=i;
					maze[i][j]='#';
				}
			}
			scanf("\n");
		}
		make(ix,iy);
		printf("%d\n",sum+1);
		scanf("%d%d",&x,&y);
	}
	return 0;
}