#include <stdio.h>
#include <stdlib.h>

void print(int n,int type)
{
	char ch;
	if(type==1) ch='*';
	else ch=' ';
	for(int i=0;i<n;i++) printf("%c",ch);
}

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=-1)
	{
		for(int i=0;i<b;i++)
		{
			print(a-1,-1);
			print(1,1);
			print(a-2,-1);
		}
		printf(" \n");
		for(int i=0;i<a-2;i++)
		{
			for(int k=0;k<b;k++)
			{
				print(a-2-i,-1);
				printf("*");
				print(2*i+1,-1);
				printf("*");
				print(a-i-3,-1);		
			}
			printf(" \n");
		}
		for(int i=0;i<b;i++)
		{
			printf("*");
			print(a*2-3,-1);
		}
		printf("*\n");
		
		for(int i=a-3;i>=0;i--)
		{
			for(int k=b;k>0;k--)
			{
				print(a-2-i,-1);
				printf("*");
				print(2*i+1,-1);
				printf("*");
				print(a-i-3,-1);		
			}
			printf(" \n");
		}
		for(int i=0;i<b;i++)
		{
			print(a-1,-1);
			print(1,1);
			print(a-2,-1);
		}
		printf(" \n\n");
	}
	return 0;
}
