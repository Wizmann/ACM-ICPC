#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000010

char str[MAX];
int next[MAX];
int len;
int cnt=1;

void getnext()
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
	while(scanf("%d",&len),len)
	{
		scanf("%s",str);
		printf("Test case #%d\n",cnt++);
		getnext();
		
		for(int i=0;i<len;i++) printf("%d ",next[i]);
		printf("\n");
		
		for(int i=2;i<=len;i++)
		{
			if(i%(i-next[i])==0)
			{
				int count=i/(i-next[i]);
				if(count!=1) printf("%d %d\n",i,count);
			}
		}
		printf("\n");
	}
	return 0;
}
		
		
