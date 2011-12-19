#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int alpha1[26];
int alpha2[26];

void init(int *alpha,char *p)
{
	while(*p!='\0')
	{
		alpha[*p-'a']++;
		p++;
	}
}

void print(char ch,int n)
{
	n= n<0? -n:n;
	for(int i=0;i<n;i++)
	{
		printf("%c",ch);
	}
}


int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char temp[1050];
		scanf("%s",temp);
		init(alpha1,temp);
		
		char sig;
		scanf(" %c ",&sig);
		
		scanf("%s",temp);
		init(alpha2,temp);
		
		if(sig=='+')
		{
			for(int k=0;k<26;k++)
			{
				alpha1[k]+=alpha2[k];
			}
		}
		if(sig=='-')//可能有负数 
		{
			for(int k=0;k<26;k++)
			{
				alpha1[k]-=alpha2[k];
			}
		}
		if(sig=='*')
		{
			for(int k=0;k<26;k++)
			{
				alpha1[k]*=alpha2[k];
			}
		}
		
		for(int k=0;k<26;k++)
		{
			print(k+'a',alpha1[k]);
		}
		printf("\n");
		memset(alpha1,0,sizeof(alpha1));
		memset(alpha2,0,sizeof(alpha2));
	}
	return 0;	
}