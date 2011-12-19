#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int s,e;
	while(scanf("%d%d",&s,&e)!=EOF)
	{
		if(!s&&!e) break;
		int t=e-s;
		if(t<=0)
		{
			printf("0\n");
		}
		else if(t>=512*60)
		{
			printf("10\n");
		}
		else if(t>0&&t<120)
		{
			printf("1\n");
		}
		else
		{
			int ans=0;
			while(t>=60)
			{
				t/=2;
				ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

			
