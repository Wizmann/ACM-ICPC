#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char alpha[26];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	char temp[15];
	char value[15];
	while(counter--)
	{
		memset(alpha,-1,sizeof(alpha));
		scanf("%s",temp);
		for(int i=1;i<=10;i++)
		{
			alpha[temp[i-1]-'A']=i==10?0:i;
		}
		
		scanf("%s",value);
		
		char *p=value;
		char print[15];
		char res[15]={0};
		while(*p!='\0')
		{
			if(alpha[*p-'A']>=0)
			{
				sprintf(print,"%d",alpha[*p-'A']);
				strcat(res,print);
			}
			p++;
		}
		printf("%d\n",atoi(res));
	}
	return 0;
}