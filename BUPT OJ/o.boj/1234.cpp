#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[1500];

void print()
{
	printf("%s\n",string);
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(string,0,sizeof(string));
		int max=-1;//最大下标 
		for(int i=0;i<n;i++)
		{
			char cmd[10];
			scanf("%s",cmd);
			if(strcmp(cmd,"delete")==0)
			{
				if(max<1) printf("error\n");//最大下标为0的时候，ERROR 
				else
				{
					max--;
					int len=strlen(string);
					*(string+len-1)='\0';
					print();
				}
			}
			else if(*cmd=='a')
			{
				char insert[1200];
				scanf("%s",insert);
				int len=strlen(insert);
				max+=len;
				strcat(string,insert);
				print();
			}
			else if(strcmp(cmd,"double")==0)
			{
				if(max==-1) printf("error\n");
				else
				{
					char temp[1200];
					strcpy(temp,string);
					int len=strlen(temp);
					max+=len;
					strcat(string,temp);
					print();
				}
			}
			else if(*cmd=='c')
			{
				int hand1,hand2;
				scanf("%d%d",&hand1,&hand2);
				if(hand1>max||hand2>max) printf("error\n");
				else
				{
					char temp;
					temp=string[hand1];
					string[hand1]=string[hand2];
					string[hand2]=temp;
					print();
				}
			}
		}
	}
	return 0;
}