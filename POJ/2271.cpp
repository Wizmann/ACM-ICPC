#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	char str[100];
	int flag=0;
	int len=0;
	while(scanf("%s",str)!=EOF)
	{
		if(strcmp(str,"<br>")==0)
		{
			printf("\n");
			flag=0;
			len=0;
		}
		else if(strcmp(str,"<hr>")==0)
		{
			if(flag) printf("\n");
			printf("--------------------------------------------------------------------------------\n");
			flag=0;
			len=0;
		}
		else
		{
			len+=strlen(str)+1;
			if(len>80)
			{
				printf("\n");
				len=strlen(str)+1;
				flag=0;
			}
			if(flag) printf(" %s",str);
			else
			{
				printf("%s",str);
				flag=1;
			}
		}
	}
	printf("\n");
	
	return 0;
}
