#include <cstdio>

char stack[30];
char *st=stack;

void push(char i)
{
	*st=i;
	st++;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(n==0) printf("0");
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
	
	while(st>stack) printf("%d",*(--st));
	printf("\n");
	
	return 0;
}