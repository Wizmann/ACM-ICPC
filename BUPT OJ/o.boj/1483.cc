#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct str
{
	char string[500];
	
	void setstr(char *p)
	{
		strcpy(string,p);
	}
}str;

str array[1000];

char input[1000];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	gets(input);
	while(*input!='#')
	{
		char *p=strtok(input,"\\");
		int foot=0;
		while(p)
		{
			if(strncmp(p,"..",2)==0) foot--;
			else if(strncmp(p,".",1)==0) /*Do Nothing*/;
			else
			{
				array[foot].setstr(p);
				foot++;
			}
			p=strtok(NULL,"\\");
		}
		
		for(int i=0;i<foot;i++)
		{
			if(i) printf("\\");
			printf("%s",array[i].string);
		}
		printf("\n");		
		gets(input);
	}
	return 0;
}