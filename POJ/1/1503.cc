#include <cstdio>
#include <cstring>
#include <cstdlib>

char num[1000];
char input[1000];

void makeNum(int len)
{
	char *p=input;
	char *q=input+len-1;
	char mid;
	while(q>=p)
	{
		mid=*q-'0';
		*q=*p-'0';
		*p=mid;
		p++;
		q--;
	}
}
	

int main()
{
	freopen("input.txt","r",stdin);
	int len,g;
	while(1)
	{
		scanf("%s",input);
		len=strlen(input);
		if(*input=='0'&&len==1) break;
		makeNum(len);
		
		g=0;
		for(int i=0;i<len;i++)
		{
			g+=input[i]+num[i];
			num[i]=g%10;
			g/=10;
		}
		for(int i=len;g>0;i++)
		{
			g+=num[i];
			num[i]=g%10;
			g/=10;
		}
	}
	char *p=num+999;
	while(*p==0) p--;
	while(p>=num)
	{
		printf("%d",*p);
		p--;
	}
	printf("\n");
	
	return 0;
}
		
		
