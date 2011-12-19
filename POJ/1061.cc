#include <cstdio>
#include <cstdlib>
#include <cstring>

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
	long long e=x*(b/d)%n;
	if(e<0) e+=n;
	return e;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int sx,sy,m,n,L;
	scanf("%d%d%d%d%d",&sx,&sy,&m,&n,&L);
	
	int a=m-n;
	int b=sy-sx;
	if(a<0)
	{
		a=-a;
		b=-b;
	}
	//ax=b(mod L)
	
	int temp=ml(a,b,L);
	if(temp==-1) puts("Impossible");
	else printf("%d\n",temp);
	
	return 0;
}
	
	
