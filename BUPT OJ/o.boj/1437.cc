#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int song[1100];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,loop;
	scanf("%d%d",&n,&loop);
	while(n&&loop)
	{
		for(int i=1;i<=n;i++) scanf("%d",&song[i]);
		
		for(int i=0;i<loop;i++)
		{
			int max=-1;
			int pos;
			for(int j=1;j<=loop;j++)
			{
				if(song[j]>max)
				{
					max=song[j];
					pos=j;
				}
			}
			
			printf("%d\n",pos);
			song[pos]=0;
			
			int mod=max%(n-1);
			for(int j=1;j<=n;j++)
			{
				if(pos!=j)
				{
					song[j]+=max/(n-1);
					if(mod)
					{
						song[j]++;
						mod--;
					}
				}
			}
		}
		scanf("%d%d",&n,&loop);
	}
	return 0;
}