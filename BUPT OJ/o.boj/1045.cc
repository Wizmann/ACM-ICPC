//Result:1045 	Accepted	2MS	96K	G++	591B	2011-08-25 19:09:52	Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define eps 1e-3

int n;
int rec[5],t[5];

long long C(int a,int b)
{
	double temp=1;
	for(int i=0;i<b;i++)
	{
		temp*=((double)(a-i)/(i+1));
	}
	return (long long)(temp+eps);
}

int main()
{
	freopen("input.txt","r",stdin);
	long long ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++) scanf("%d",&t[j]);
		int sum=0;
		for(int j=0;j<3;j++) sum+=t[j]-rec[j];
		for(int j=0;j<3;j++)
		{
			ans*=C(sum,t[j]-rec[j]);
			sum-=(t[j]-rec[j]);
		}
		memcpy(rec,t,sizeof(t));
	}
	printf("%lld\n",ans);
	return 0;
}
