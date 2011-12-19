#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen("input.txt","r",stdin);
	
	char string[100];
	scanf("%s",string);
	int flag=0;
	char temp[15];
	while(strcmp(string,"#"))
	{
		memset(temp,0,sizeof(temp));
		char *p=string;
		while(*p!='\0')
		{
			char out[3];
			if(*p>='0'&&*p<='9')
			{
				sprintf(out,"%c",*p);
				strcat(temp,out);
			}
			else if(*temp!='\0')
			{
				printf("a[%d]:%s\n",flag++,temp);
				memset(temp,0,sizeof(temp));
			}
			if(*(p+1)=='\0'&&*temp!='\0')
			{
				printf("a[%d]:%s\n",flag++,temp);
				memset(temp,0,sizeof(temp));
			}
			p++;
		}
		scanf("%s",string);
	}
	printf("Total:%d\n",flag);
	return 0;
}