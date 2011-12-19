#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char number[15];
char *p=number;

void push(int n)
{
	*p=n;
	p++;
}

int cmp(const void *a,const void *b)
{
	return *(char*)a-*(char*)b;
}

int main()
{
	
	unsigned int n;
	scanf("%d",&n);
	
	int len=0;
	memset(number,0,sizeof(number));
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	
	if(!n)
	{
		printf("10\n");
		return 0;
	}
	
	while(n>1)
	{
		int i;
		for(i=9;i>0;i--)
		{
			if(n%i==0)
			{
				push(i+'0');
				n/=i;
				len++;
				break;
			}
		}
		if(i==1)
		{
			printf("-1\n");
			exit(0);
		}

	}
	
	qsort(number,len,sizeof(char),cmp);
	for(int i=0;i<len;i++) printf("%c",number[i]);
	printf("\n");
	
	return 0;
}