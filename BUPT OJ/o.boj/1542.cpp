#include <stdio.h>

void print1()
{
	printf("  *\n * *\n* * *\n\n");
}

void print2()
{
	printf("  *\n * *\n*   *\n * *\n  *\n\n");
}

void print3()
{
	printf("***\n* *\n***\n\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int in;
		scanf("%d",&in);
		switch(in)
		{
			case 1:print1();break;
			case 2:print2();break;
			case 3:print3();break;
		}
	}
	return 0;
}