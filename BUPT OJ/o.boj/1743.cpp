#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n!=1)
	{
		int r=0,s=0,c=0;
		char input[40000];
		gets(input);
		char *p=input;
		while(*p!='\0')
		{
			switch(*p)
			{
				case 'R':r++;break;
				case 'S':s++;break;
				case 'C':c++;break;
				default:break;
			}
			p++;
		}
		
		if(r&&!s&&!c) printf("C\n");
		else if(!r&&s&&!c) printf("R\n");
		else if(!r&&!s&&c) printf("S\n");
		else if(r&&s&&!c) printf("R C\n");
		else if(r&&!s&&c) printf("S C\n");
		else if(!r&&s&&c) printf("S\n");
		else if(r&&s&&c) printf("S C\n");
		
		scanf("%d",&n);
	}
	return 0;	
}
