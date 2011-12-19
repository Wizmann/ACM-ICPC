#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int L,people;
	scanf("%d%d",&L,&people);
	
	char *path=(char*)malloc(sizeof(char)*(L+5));
	memset(path,0,sizeof(char)*(L+5));
	
	while(people--)
	{
		int x,d,k;
		scanf("%d%d%d",&x,&d,&k);
		while(k--)
		{
			path[x]++;
			x+=d;
		}
	}
	
	int flag=-1;
	int max=2e30;	
	for(int i=0;i<=L;i++)
	{
		if(path[i])
		{
			if(path[i]>1)
			{
				printf("%d\n",0);
				return 0;
			}
			else
			{
				if(flag<0) flag=i;
				else
				{
					if(max>i-flag) max=i-flag;
					flag=i;
				}
			}
		}
	}
	
	//for(int i=0;i<=L;i++) printf("%d ",path[i]);
	//printf("\n");
	
	printf("%d\n",max);
	return 0;
}