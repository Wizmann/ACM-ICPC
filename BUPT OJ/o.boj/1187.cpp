#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char name[]="martian";

void convert(char *str)
{
	char *string=str;
	while(*string!='\0')
	{
		if(*string>='A'&&*string<='Z') *string=*string-'A'+'a';
		string++;
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char temp[2000];
	int sum;
	
	while(scanf("%s",temp)!=EOF)
	{
		convert(temp);
		sum=0;
		char *p=temp;
		const char *flag=name;
		
		while(*p!='\0')
		
		{
			if(*p==*flag)
			{
				flag++;
				if(*flag=='\0')
				{
					sum++;
					flag=name;
				}
			}
			p++;
		}
		
		printf("%d\n",sum);
	}
	return 0;
}