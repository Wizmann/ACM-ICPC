#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char pos[100];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	int cell;
	scanf("%d",&n);
	while(n--)
	{
		int run=0;
		scanf("%d",&cell);
		memset(pos,0,sizeof(pos));
		for(int i=2;i<=cell;i++)
		{
			for(int j=i;j<=cell;j+=i)
			{
				if(pos[j]) pos[j]=0;
				else pos[j]=1;
			}
		}
		for(int i=1;i<=cell;i++) if(!pos[i]) run++;
		printf("%d\n",run);
	}
	return 0;
}