#include <cstdio>
#include <cstdlib>
#include <cstdlib>

int num[15010];
int baum[15010];
int n;

inline int lowbit(int x)
{
	return x&(-x);
}

int query(int a)
{
	int res=0;
	while(a>0)
	{
		res+=baum[a];
		a-=lowbit(a);
	}
	return res;
}

void ins(int a)
{
	while(a<=15000)
	{
		++baum[a];
		a+=lowbit(a);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		num[query(a+1)]++;
		ins(a+1);
	}
	
	for(int i=0;i<n;i++) printf("%d\n",num[i]);
	return 0;
}
