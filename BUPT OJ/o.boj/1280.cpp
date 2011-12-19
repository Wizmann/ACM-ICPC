#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len(int n)
{
	int res=0;
	while(n>0)
	{
		n/=10;
		res++;
	}
	return res;
}

int main()
{
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		int num[20];
		memset(num,-1,sizeof(num));
		char ip[100];
		memset(ip,0,sizeof(ip));
		scanf("%s",ip);
		
		char *p=ip;
		char *q=ip;
		int foot=0;
		while(*p!='\0')
		{
			q=p;
			char temp[20];
			memset(temp,0,sizeof(temp));
			while(*p!='.'&&*p!='\0') p++;
			strncpy(temp,q,(int)(p-q));
			num[foot]=atoi(temp);
			if(num[foot]>255) num[foot]=-99;
			else if(num[foot]==0)
			{
				if(strcmp(temp,"0")==0);//Kick your ass
				else num[foot]=-99;
			}
			else if(strlen(temp)!=len(num[foot])) num[foot]=-99;
			foot++;
			p++;
		}
		
		int flag=1;
		for(int i=0;i<20;i++)
		{
			if(num[i]==-99)
			{
				flag=0;
				break;
			}
			
			if(i<=3&&num[i]==-1)
			{
				flag=0;
				break;
			}
			
			if(i>3&&num[i]!=-1)
			{
				flag=0;
				break;
			}
		}
		
		if(flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}