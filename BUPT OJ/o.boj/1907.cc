#include <cstdio>
#include <cstring>
#include <cstdlib>

int pos[1010][1010];
int mem[1010][1010];
int max=1;
int x,y;

int dfs(int tx,int ty)
{
	if(mem[ty][tx]) return mem[ty][tx];
	else
	{
		int temp;
		mem[ty][tx]=1;
		if(ty-1>=0&&pos[ty-1][tx]<pos[ty][tx])
		{
			temp=dfs(tx,ty-1)+1;
			if(mem[ty][tx]<temp) mem[ty][tx]=temp;
		}
		if(ty+1<y&&pos[ty+1][tx]<pos[ty][tx])
		{
			temp=dfs(tx,ty+1)+1;
			if(mem[ty][tx]<temp) mem[ty][tx]=temp;
		}
		if(tx-1>=0&&pos[ty][tx-1]<pos[ty][tx])
		{
			temp=dfs(tx-1,ty)+1;
			if(mem[ty][tx]<temp) mem[ty][tx]=temp;
		}
		if(tx+1<x&&pos[ty][tx+1]<pos[ty][tx])
		{
			temp=dfs(tx+1,ty)+1;
			if(mem[ty][tx]<temp) mem[ty][tx]=temp;
		}
	}
	return mem[ty][tx];
}
		

int main()
{
	
	freopen("input.txt","r",stdin);
	
	scanf("%d%d",&y,&x);
	
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++) scanf("%d",&pos[i][j]);
	}
	
	int temp;
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(!mem[i][j])
			{
				temp=dfs(j,i);
				if(temp>max) max=temp;
			}
		}
	}
	
	printf("%d\n",max);
	return 0;
}
	
	
