#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ti=1;

typedef struct str
{
	char s[210];
	int l;
	int max;
	
	void setstr()
	{
		scanf("%s",s);
		l=strlen(s);
		max=1;
	}
	
	bool cmp(str a)
	{
		if(a.l<=l) return false;
		else 
		{
			if(strncmp(a.s,s,l)==0) return true;
			else return false;
		}
	}
}str;

str array[205];

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++) array[i].setstr();
		int ans=1;
		for(int i=1;i<n;i++)
		{
			int max=1;
			for(int j=i-1;j>=0;j--)
			{
				if(array[j].max+1>max)
				{
					if(array[j].cmp(array[i])) max=array[j].max+1;
				}
			}
			array[i].max=max;
			if(max>ans) ans=max;
		}
		printf("Case #%d:\n",ti++);
		printf("%d\n",ans);
	}
	return 0;
}
