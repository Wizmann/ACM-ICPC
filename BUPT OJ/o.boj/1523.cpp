#include <stdio.h>

int main()
{
	freopen("input.txt","r",stdin);
	
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		char code[1050];
		gets(code);
		char alpha[30];
		gets(alpha);
		char *p=code;
		printf("%d ",i+1);
		while(*p!='\0')
		{
			if(*p==' ') printf(" ");
			else printf("%c",alpha[*p-'A']);
			p++;
		}		
		printf("\n");
	}
	return 0;
}