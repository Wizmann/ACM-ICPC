#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alpha[30];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	scanf("%s",alpha);
	scanf("\n");
	char temp[100];
	gets(temp);
	char *p=temp;
	while(*p!='\0')
	{
		if(*p>='A'&&*p<='Z')
		{
			printf("%c",alpha[*p-'A']-'a'+'A');
		}
		else if(*p>='a'&&*p<='z')
		{
			printf("%c",alpha[*p-'a']);
		}
		else printf("%c",*p);
		p++;
	}
	printf("\n");
	return 0;
}