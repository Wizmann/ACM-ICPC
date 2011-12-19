#include <cstdio>
#include <cstdlib>
#include <cstring>

char stack[50];
char *st;

inline void init()
{
	memset(stack,0,sizeof(stack));
	st=stack;
}

inline void push(char c)
{
	*st=c;
	st++;
}

inline void print()
{
	while(st--!=stack) printf("%c",*st);
	printf("\n");
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		while(n)
		{
			if(n%26==0)
			{
				push('Z');
				n/=26;
				n--;
			}
			else
			{
				push('A'+n%26-1);
				n/=26;
			}
		}
		print();
	}	
	return 0;
}
