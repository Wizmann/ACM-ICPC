#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

typedef struct bit
{
	char num[40];
	int len;
	
	bit()
	{
		memset(num,0,sizeof(num));
		len=1;
	}
	
	bit operator = (const char* right)
	{
		for(int i=0;i<len;i++)
		{
			num[i]=right[len-i-1]-'0';
		}
		return *this;
	}
	
	void plus_eins()
	{
		int g=0;
		if(num[0]==1)
		{
			g=1;
			num[0]=0;
		}
		else
		{
			num[0]++;
			goto turf;
		}
		for(int i=1;i<len;i++)
		{
			if(num[i]+g==2)
			{
				num[i]=0;
				g=1;
			}
			else
			{
				num[i]++;
				g=0;
				break;
			}
		}
		if(g==1)
		{
			num[len]=1;
			len++;
		}
		turf:
		print();
	}
	
	void print()
	{
		for(int i=0;i<len;i++) printf("%d",num[len-i-1]);
		printf("\n");
	}
}bit;

int main()
{
	#ifdef DEBUG
	freopen("input.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		bit temp;
		scanf("%d",&temp.len);
		char number[40];
		scanf("%s",number);
		temp=number;
		temp.plus_eins();
	}
	return 0;
}