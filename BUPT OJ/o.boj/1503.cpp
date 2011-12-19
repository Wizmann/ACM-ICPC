#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rev(char *start,char *end)
{
	char temp;
	while(start<end)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char string[1500];
	gets(string);
	int len=strlen(string);
	char *start=string+len-1;
	char *end;
	
	while(start>=string)
	{
		while(*(start-1)!='#'&&start!=string) start--;
		end=start;
		while(*(end+1)!='#'&&*(end+1)!='\0') end++;
		if( (*start>='A'&&*start<='Z') || (*start>='a'&&*start<='z') ) rev(start,end);
		start--;	
	}
	
	char *p=string+len-1;
	while(p!=string-1) printf("%c",*(p--));
	printf("\n");
	return 0;
}