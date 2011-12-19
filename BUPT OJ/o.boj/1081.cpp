#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	char temp[100];
	while(counter--)
	{
		scanf("%s",temp);
		if(*temp=='a'||*temp=='e'||*temp=='i'||*temp=='o'||*temp=='u')
		{
			printf("%scow",temp);
		}
		else
		{
			printf("%s%cow",temp+1,*temp);
		}
		printf("\n");
	}
	return 0;
}