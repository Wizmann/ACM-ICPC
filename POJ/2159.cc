#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int code[30];
int hash[30];
//Hash? Fxxk...

int main()
{
	char input[300];
	gets(input);
	char *p=input;
	while(*p!='\0')
	{
		code[*p-'A']++;
		p++;
	}
	qsort(code,30,sizeof(int),cmp);
	
	gets(input);
	p=input;
	while(*p!='\0')
	{
		hash[*p-'A']++;
		p++;
	}
	qsort(hash,30,sizeof(int),cmp);
	
	int flag=1;
	for(int i=0;i<30;i++)
	{
		if(code[i]==hash[i]) continue;
		else
		{
			flag=0;
			break;
		}
	}
	
	if(flag) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}