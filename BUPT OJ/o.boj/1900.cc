#include <stdio.h>
int main()
{
	int n,m,s,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		s=0;
		for(i=2;i<=n;i++) s=(s+m)%i;
		printf("%d\n",s+1);
	}
	return 0;
}