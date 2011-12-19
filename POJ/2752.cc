#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[400010];
int next[400010];
int result[400010];
int len;

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
	while(scanf("%s",str)!=EOF)
	{
		memset(result,0,sizeof(result));
		len=strlen(str);
		get_next();
		
		int pos=len;
		int pad=0;
		while(pos!=0)
		{
			result[++pad]=pos;
			pos=next[pos];
		}
		while(pad>1)
		{
			printf("%d ",result[pad]);
			pad--;
		}
		printf("%d\n",result[pad]);
	}
	return 0;
}
