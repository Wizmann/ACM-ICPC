#include <cstdio>
#include <cstring>
#include <cstdlib>

long long x,y;

long long ee(long long a,long long b)
{
	long long ret;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	else
	{
		ret=ee(b,a%b);
		long long t=x;
		x=y;
		y=t-a/b*y;
		return ret;
	}
}

long long ml(long long a,long long b,long long n)
{
	long long d=ee(a,n);
	if(b%d) return -1;
	long long e=x*(b/d)%n+n;
	return e%(n/d);
}
		

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int a,b,c,mul;
	while(scanf("%d%d%d%d",&a,&b,&c,&mul)!=EOF)
	{
		if(a==0&&b==0&&c==0&&mul==0) break;
		
		long long temp=ml(c,b-a,1LL<<mul);
		if(temp==-1) printf("FOREVER\n");
		else printf("%lld\n",temp);
	}
	return 0;
}
		
		
