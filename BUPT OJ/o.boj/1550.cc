#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char str[100];
	int flag=0;
	while(scanf("%s",str)!=EOF)
	{
		char *p=str;
		while(*p!='\0')
		{
			if(!flag)
			{
				printf("%X",*p);
				flag++;
			}
			else printf(" %X",*p);
			p++;
		}
	}
	printf("\n");
	return 0;
}
		
