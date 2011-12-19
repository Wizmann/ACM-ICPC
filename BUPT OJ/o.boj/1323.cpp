#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int HDD=1048576;
		int file;
		char name[100];
		bool full=false;
		while(n--)
		{
			scanf("%d",&file);
			HDD-=file;
			if(HDD<0) full=true;
			gets(name);
		}
		
		if(full) printf("Out of Space\n");
		else printf("%d MB(s) left\n",HDD);
	}
	return 0;
}
