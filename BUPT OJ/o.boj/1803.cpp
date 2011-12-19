#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F(char c)
{
	return c-'a'+1;
}

int attack(char *string)
{
	int att=0;
	int i=1;
	char *temp=string;
	while(*temp!='\0')
	{
		att+=i*F(*temp);
		i++;
		temp++;
	}
	return att%100;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		char temp[25];
		scanf("%s",temp);
		a=attack(temp);
		printf("%d ",a);
		scanf("%s",temp);
		b=attack(temp);
		printf("%d\n",b);
		if(a>b) printf("win\n");
		else if(a==b) printf("tie\n");
		else printf("lose\n");
	}
	return 0;
}