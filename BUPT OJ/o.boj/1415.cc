#include <cstdio>

int main()
{
	int n,c;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		if(!n||!c) printf("0\n");
		else
		{
			int t=c/n/2;
			int sign=0;
			if(c>n+2*n*t) sign=1; 
			printf("%d\n",t+sign);
		}
	}
	return 0;
}
