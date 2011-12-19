//Result:Accepted	408K	0MS	G++	270B
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	int n,h,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d:%d",&h,&m);
		if(m!=0) puts("0");
		else
		{
			if(h==12) puts("24");
			else printf("%d\n",(12+h)%24);
		}
	}
	return 0;
}
