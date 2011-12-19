#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define G 10.000

int main()
{
	freopen("input.txt","r",stdin);
	
	int cas=1;
	int H,L,V;
	while(scanf("%d%d%d",&H,&L,&V)!=EOF)
	{
		printf("Case %d:\n",cas++);
		double k=(double)L/V * sqrt((double)G/(H+L));
		int K=(int)k;
		if(k-K>1e-6) K++;
		printf("%d\n",K);
	}
	return 0;	
}