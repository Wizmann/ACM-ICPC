#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isbn[20];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char ch;
	int sum=0;
	int set;
	for(int i=10;i>=1;i--)
	{
		scanf("%c",&ch);
		if(ch>='0'&&ch<='9')
		{
			isbn[i]=ch-'0';
			sum+=(ch-'0')*i;
		}
		else if(ch=='?') set=i;
		else if(ch=='X') sum+=i*10;
	}
	
	int flag=0;
	if((sum+10)%11==0&&set==1)
	{
		printf("X\n");
		flag=1;
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			if( (sum+set*i)%11==0 )
			{
				printf("%d\n",i);
				flag=1;
				break;
			}
		}
	}
	if(flag==0) printf("-1\n");
	return 0;
}