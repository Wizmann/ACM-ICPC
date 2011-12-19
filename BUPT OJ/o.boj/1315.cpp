#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int abs(int a,int b)
{
	return a-b>0?a-b:b-a;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	scanf("\n");
	char a[26];
	char b[26];
	char temp[50];
	char *p;
	char sig;
	int flag=1;
	while(counter--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		gets(temp);
		p=temp;
		while(*p!='\0')
		{
			a[*p-'a']++;
			p++;
		}
		
		gets(temp);
		p=temp;
		while(*p!='\0')
		{
			b[*p-'a']++;
			p++;
		}
		
		
		int sum=0;
		for(int i=0;i<26;i++)
		{
			sum+=abs(a[i],b[i]);
		}
		
		printf("Case #%d:  %d\n",flag++,sum);
	}
	return 0;
}