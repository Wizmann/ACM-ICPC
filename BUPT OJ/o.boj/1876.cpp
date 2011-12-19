#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mod(char ch)
{
	return ch-'a'+'A';
}

int main()
{	
	int n;
	scanf("%d",&n);
	char str[60];
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		for(int j=0;j<strlen(str);j++)
		{
			if(str[j]>='a'&&str[j]<='z') printf("%c",str[j]);
			else
			{
				j++;
				printf("%c",mod(str[j]));
			}
		}
		printf("\n");		
	}
	return 0;
}