#include <stdio.h>
#include <string.h>

typedef struct num
{
	char string[110];
	int lng;
	
	num()
	{
		memset(string,0,sizeof(string));
		lng=0;
	}
	
	void setnum(char *ch)
	{
		lng=strlen(ch);
		for(int i=0;i<lng;i++)
		{
			string[i]=ch[lng-i-1];
		}
	}
	
	void operator = (const char *input)
	{
		lng=strlen(input);
		for(int i=0;i<lng;i++)
		{
			string[i]=input[lng-i-1]-'0';
		}
	}
	
	num operator + (const num& right)
	{
		num *temp=new num;
		int g=0;
		int l=max(right);
		for(int i=0;i<l;i++)
		{
			int sum=g+right.string[i]+string[i];
			temp->string[i]=sum%10;
			g=sum/10;
		}
		if(g==1)
		{
			temp->string[l]=1;
			temp->lng=l+1;
		}
		else temp->lng=l;
		temp->print();
		return *temp;
	}
	
	int max(const num right)
	{
		return lng>right.lng?lng:right.lng;
	}
	
	void print()
	{
		for(int i=0;i<lng;i++) printf("%d",string[lng-1-i]);
		printf("\n");
	}
}num;

int main()
{
	freopen("input.txt","r",stdin);
	char input[110];
	while(scanf("%s",input)!=-1)
	{
		num a;
		a=input;
		num b;
		scanf("%s",input);
		b=input;
		a+b;
	}	
	return 0;
}