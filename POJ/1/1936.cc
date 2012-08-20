#include <cstdio>
#include <cstdlib>
#include <cstring>

char a[100100],b[100100];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char *pa,*pb;
	int n;
	while(scanf("%s%s",a,b)!=EOF)
	{
	
		if(strlen(a)>strlen(b))
		{
			pa=a;
			pb=b;
		}
		else
		{
			pa=b;
			pb=a;
		}
		//pa是长的。。。
		n=strlen(pb);
		
		for(/*pb*/;*pb!='\0';pb++)
		{
			for(/*pa*/;*pa!='\0';pa++)
			{
				if(*pa==*pb)
				{
					n--;
					pa++;
					break;
				}
			}
		}
		
		if(!n) puts("Yes");
		else puts("No");
	}
	return 0;
}
		
		
