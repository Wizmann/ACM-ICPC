#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[2000];
char *st;

inline void push(char c)
{
	*st=c;
	st++;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,n,pos,num;
	scanf("%d",&t);
	while(t--)
	{
		memset(str,0,sizeof(str));
		st=str;
		pos=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&num);
			for(/*pos*/;pos<num;pos++) push('(');
			push(')');
		}
		//puts(str);
		bool first=true;
		int len=strlen(str);
		int ans=0;
		for(int i=0;i<len;i++)
		{
			ans=0;
			if(str[i]==')')
			{
				for(int k=i;k>=0;k--)
				{
					if(str[k]=='('||str[k]=='U') ans++;
					if(str[k]=='(')
					{
						if(first)
						{
							printf("%d",ans);
							first=false;
						}
						else printf(" %d",ans);
						str[k]='U';
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
