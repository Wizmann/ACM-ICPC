#include <stdio.h>

int main()
{
	freopen("input.txt","r",stdin);
	
	char num[500];
	scanf("%s",num);
	int neun=0,eins=0,zwei=0;
	char *p=num;
	for(int i=0;/*Nothing's Here*/;i++)
	{
		if(*p=='9') neun++;
		else if(*p=='1') eins++;
		else if(*p=='2') zwei++;
		else if(*p=='\0') break;
		
		p++;
	}
	printf("%d\n%d\n%d\n",neun,eins,zwei);
	return 0;
}