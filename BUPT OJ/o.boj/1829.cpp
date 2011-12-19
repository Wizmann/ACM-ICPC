#include <stdio.h>
#include <string.h>

int main()
{
	char temp[30];
	scanf("%s",temp);
	int len=strlen(temp);
	for(int i=0;i<len;i++) printf("%c",temp[len-i-1]);
	printf("\n");
	return 0;
}