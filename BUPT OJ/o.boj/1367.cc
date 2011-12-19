#include <cstdio>
#include <cstdlib>
#include <cstring>

#define lowbit(x) (x&(-x))
#define SIZE 10010

int baum[SIZE];
int m,n,k;

inline void init()
{
	memset(baum,0,sizeof(baum));
	for(int i=0;i<=n;i++) baum[i]=lowbit(i);
}

int sum(int x)
{
	int res=0;
	while(x>0)
	{
		res+=baum[x];
		x-=lowbit(x);
	}
	return res;
}

int find(int val)
{
	int l=1,r=n;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(sum(m)>=val)  r=m-1;
		else l=m+1;
	}
	return l;
}

void letout(int x)
{
	while(x<SIZE)
	{
		baum[x]--;
		x+=lowbit(x);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		scanf("%d%d%d",&n,&k,&m);
		if(!n&&!k&&!m) break;
		
		init();
		int t;
		for(int i=1;i<=n;i++)
		{
			t=find(m);
			letout(t);
			
			if(i!=n) m=( (k+m-2) %(n-i)+(n-i) )%(n-i)+1;
		}
		printf("%d\n",t);
	}
	return 0;
}
