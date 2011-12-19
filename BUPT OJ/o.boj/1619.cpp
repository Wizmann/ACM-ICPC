#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char temp[100];
		int n;
		scanf("%d%s",&n,temp);
		int len=strlen(temp);
		temp[n-1]=-1;
		printf("%d ",i+1);
		for(int k=0;k<len;k++)
		{
			if(temp[k]==-1) continue;
			else printf("%c",temp[k]);
		}
		printf("\n");
	}
	return 0;
}