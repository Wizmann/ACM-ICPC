#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[500];
char *st;

void push(int i)
{
	*st=i;
	st++;
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		st=stack;
		while(n)
		{
			if(n%2)
			{
				push(1);
				n=(n-1)/(-2);
			}
			else
			{
				push(0);
				n/=(-2);
			}
		}
		while(st>stack)
		{
			printf("%d",*(--st));
		}
		printf("\n");
	}
	return 0;
}