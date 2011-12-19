#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[500];
char input[500];

char *stack;

void push(char ch)
{
	*stack=ch;
	stack++;
}

int main()
{
	freopen("input.txt","r",stdin);
	
	while(scanf("%s",input)!=EOF)
	{
		char *p=input;
		int len=0;
		int num;
		stack=str;
		while(*p!='\0')
		{
			num=0;
			while(*p>='0'&&*p<='9')
			{
				if(num<=50)
				{
					num*=10;
					num+=(*p-'0');
				}
				p++;
			} 
			if(num==0) num=1;
			len+=num;
			if(len>50) break;
			for(int i=0;i<num;i++) push(*p);
			p++;
		}
		
		if(len>50) printf("TOO LONG\n");
		else
		{
			push('\0');
			puts(str);
		}
	}
	return 0;
}
