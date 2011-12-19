#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[12000];

int main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%s",string);
	int m,n;
	scanf("%d%d",&m,&n);
	char search[20];
	for(int i=0;i<n;i++)
	{
		scanf("%s",search);
		if(strstr(string,search)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}