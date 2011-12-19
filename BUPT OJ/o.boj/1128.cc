#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pos[101000];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int money;
	int n;
	while(scanf("%d",&money)!=EOF)
	{
		scanf("%d",&n);
		memset(pos,0,sizeof(pos));
		pos[0]=1;
		int num,bill;
		while(n--)
		{
			scanf("%d%d",&num,&bill);
			int plus=bill;
			int k=1;
			while(num>=k)
			{
				num-=k;
				for(int i=money;i>=0;i--)
				{
					if(pos[i]&&i+plus*k<=money) pos[i+plus*k]=1;
				}
				k<<=1;
			}
			
			if(num)
			{
				for(int i=money;i>=0;i--)
				{
					if(pos[i]&&i+num*bill<=money) pos[i+num*bill]=1;
				}
			}
			
		}
		
		int i;
		for(i=money;i>=0;i--)
		{
			if(pos[i]) break;
		}
		
		printf("%d\n",i);
	}
	return 0;
}
