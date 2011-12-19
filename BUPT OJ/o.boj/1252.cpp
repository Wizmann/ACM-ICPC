#include <stdio.h>

#define LOCAL

int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		int a,b,sum=-1;
		int day;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a+b>8&&a+b>sum)
			{
				sum=a+b;
				day=i;
			}
		}
		if(sum==-1) printf("0\n");
		else printf("%d\n",day+1);
		scanf("%d",&n);
	}
	return 0;
}
