#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int temp;
		int a=0,b=0;
		while(n--)
		{
			scanf("%d",&temp);
			if(temp%2) a++;
			else b++;
		}
		if(a>b) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
