#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	int *word=(int*)malloc(sizeof(int)*n);
	char input[20];
	scanf("%s",input);
	char *p=input;
	for(int i=0;i<n;i++)
	{
		if(*p!='\0') word[i]=(int)(*p);
		else break;
		p++;
	}
	int **matrix=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++) matrix[i]=(int*)malloc(sizeof(int)*n);
	
	for(int y=0;y<n;y++)
	{
		for(int x=0;x<n;x++)
		{
			scanf("%d",&matrix[y][x]);
		}
	}
	
	int *result=(int*)malloc(sizeof(int)*n);
	memset(result,0,sizeof(int)*n);
	
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			result[x]+=word[y]*matrix[y][x];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		result[i]%=26;
		printf("%c",'a'+result[i]);
	} 
	printf("\n");
	return 0;
	
}