#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[1000010];
int next[1000010];
int len,get;

void get_next()
{
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0&&str[i]!=str[j]) j=next[j];
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d",&len,&get);
	scanf("%s",str);
	
	get_next();
	for(int i=0;i<len;i++)
	{
		if(next[i]==get)
		{
			for(int j=i-next[i];j<i;j++) printf("%c",str[j]);
			printf("\n");
			break;
		}
	}
	return 0;
}
