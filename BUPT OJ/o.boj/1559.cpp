#include <stdio.h>
#include <string.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int len;
	char string[25];
	char *p;
	scanf("%s",string);
	p=string;
	while(*p!='\0')
	{
		if(*p=='#')
		{
			*p=0;
			break;
		}
		p++;
	}
	len=strlen(string);
	int n;
	scanf("%d",&n);
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		temp= temp>0? temp:-temp;
		temp%=len;
		printf("%c",string[temp]);
	}
	printf("\n");
	return 0;
}