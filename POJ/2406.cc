#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[1000100];
int next[1000100];
int len;

void get_next()
{
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0&&str[i]!=str[j]) j=next[j];
	}
}

void printnext()
{
	for(int i=0;i<len;i++) printf("%d ",next[i]);
	printf("\n");
}

int main()
{
	//freopen("input.txt","r",stdin);
	while(gets(str))
	{
		if(*str=='.') break;
		len=strlen(str);
		get_next();
		printnext();
		for(int i=len;i>=1;i++)
		{
			if(i%(i-next[i])==0)
			{
				printf("%d\n",i/(i-next[i]));
				break;
			}
		}
	}
	return 0;
}
	
