#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	char string[250];
	while(n)
	{
		int len;
		scanf("%s",string);
		len=strlen(string);
		len/=n;
		
		char **matrix=(char**)malloc(sizeof(char*)*len);
		for(int i=0;i<len;i++)
		{
			matrix[i]=(char*)calloc(n,sizeof(char));
		}
		
		int tot=0;
		char *p=string;	
		for(int l=0;l<len;/*Kiss my ass*/)	
		{
			if(l<len)
			{
				for(int i=0;i<n;i++)
				{
					matrix[l][i]=*(p++);
				}
				l++;
			}
			
			if(l<len)
			{
				for(int i=n-1;i>=0;i--)
				{
					matrix[l][i]=*(p++);
				}
				l++;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<len;k++)
			{
				printf("%c",matrix[k][i]);
			}
		}
		printf("\n");		
		scanf("%d",&n);
	}
	return 0;
}