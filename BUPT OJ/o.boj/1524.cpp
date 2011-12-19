#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char matrix[3][6];
char *p;

void push(int n)
{
	*p=n;
	p++;
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	int flag=1;
	while(counter--)
	{
		char input[30];
		int num[3];
		char temp[5];
		//fflush(stdin);
		scanf("%s",input);
		char *r=input;
		
		for(int i=0;i<3;i++)
		{
			strncpy(temp,r,2);
			r+=3;
			num[i]=atoi(temp);
		}
		
		memset(matrix,0,sizeof(matrix));
		for(int i=0;i<3;i++)
		{
			p=matrix[i];
			while(num[i]>0)
			{
				push(num[i]%2);
				num[i]/=2;
			}
		}
		printf("%d ",flag++);
		for(int i=0;i<6;i++)
		{
			for(int k=0;k<3;k++) printf("%d",matrix[k][5-i]);
		}
		printf(" ");
		for(int i=0;i<3;i++)
		{
			for(int k=0;k<6;k++) printf("%d",matrix[i][5-k]);
		}
		printf("\n");
	}
	return 0;
}