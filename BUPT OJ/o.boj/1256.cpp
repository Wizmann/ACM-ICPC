#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alpha[]={
	-1,1,2,3,-1,1,2,-1,-1,2,2,4,5,5,-1,1,2,6,2,3,-1,1,-1,2,-1,2
};

int main()
{
	char string[25];
	while(scanf("%s",string)!=-1)
	{
		char out[20];
		char *p=out;
		int len=strlen(string);
		for(int i=0;i<len;i++)
		{
			*p=alpha[string[i]-'A'];
			p++;
		}
		(*p)=-99;//结束记号
		
		p=out;
		char temp=-99;
		while(*p!=-99)
		{
			if(*p==-1)
			{
				temp=-99;
			}
			else
			{
				if(*p!=temp)
				{
					printf("%d",*p);
					temp=*p;
				}
			}
			p++;			
		}
		printf("\n");
	}
	return 0;
} 


//打字母表专用 
//int main()
//{
//	FILE *fp;
//	fp=fopen("output.txt","w");
//	for(int i=0;i<26;i++)
//	{
//		printf("%c:",'A'+i);
//		int n;
//		scanf("%d",&n);
//		fprintf(fp,"%d,",n);
//	}
//	return 0;
//}