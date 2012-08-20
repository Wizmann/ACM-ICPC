//Result:wizmann	1005	Accepted	412K	0MS	G++	461B	2011-09-06 22:57:25
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define mul(x) ((x)*(x))
#define pi acos(-1.0)
#define water 50.0

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		double sum=pi*(mul(a)+mul(b))/2;
		int ans=(int)((sum+water)/water);
		printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
	}
	puts("END OF OUTPUT.");
	return 0;
}

