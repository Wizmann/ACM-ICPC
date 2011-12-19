#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int money[310];

int main()
{
	freopen("input.txt","r",stdin);
	
	int n,c;
	scanf("%d%d",&n,&c);
	money[0]=1;
	while(c--)
	{
		int temp;
		scanf("%d",&temp);
		for(int i=0;i<=n;i++)
		{
			if(money[i]) money[i+temp]+=money[i];
		}
	}
	
	printf("%d\n",money[n]);
	return 0;
}
