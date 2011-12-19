#include <stdio.h>
#include <string.h>

void rev(char *string)
{
	for(int i=0;i<strlen(string);i++)
	{
		printf("%c",string[strlen(string)-i-1]);
	}
	printf("\n");
}

int main()
{
	char temp[100];
	gets(temp);
	while(strcmp(temp,"***"))
	{
		rev(temp);
		gets(temp);
	}
	return 0;
}