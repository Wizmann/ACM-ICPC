#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000

const char alpha[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};

int plist[N];

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	char temp[100];
	char *p;
	scanf("\n");
	for(int i=0;i<n;i++)
	{
		gets(temp);
		p=temp;
		while(*p!='\0')
		{
			if(*p>='0'&&*p<='9') plist[i]=plist[i]*10+(*p-'0');
			else if(*p>='A'&&*p<='Z')
			{
				if(alpha[*p-'A']>0) plist[i]=plist[i]*10+alpha[*p-'A'];
			}
			/*else do nothing*/
			p++;
		}
	}
	
	qsort(plist,n,sizeof(int),cmp);
	
	/*Debug
	for(int i=0;i<n;i++) printf("%d->%d\n",i,plist[i]);
	*/
	
	int t=plist[0],num=1;
	char print[100];
	int flag=0;
	for(int i=1;i<n+1;i++)
	{
		if(plist[i]==t&&i<n) num++;
		else
		{
			if(num>1)
			{
				memset(print,0,sizeof(print));
				sprintf(print,"%d",t);
				if(strlen(print)<7)
				{
					int len=strlen(print);
					char tp[100];
					for(int i=0;i<7-len;i++) tp[i]='0';
					tp[7-len]='\0';
					strcat(tp,print);
					strcpy(print,tp);
				}
				for(int j=0;j<3;j++) printf("%c",print[j]);
				printf("-");
				for(int j=3;print[j]!='\0';j++) printf("%c",print[j]);
				printf(" %d\n",num);
				flag++;
			}
			num=1;
			t=plist[i];
		}
	}
	if(!flag) printf("No duplicates.\n");
	return 0;
}
