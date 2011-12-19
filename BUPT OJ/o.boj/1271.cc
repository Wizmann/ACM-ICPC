#include <cstdio>
#include <cmath>

int stack[25];
int array[25];
int *st;
int n,k;
int res=0;

inline void push(int i)
{
	*st=i;
	st++;
}

inline void pop()
{
	*st=0;
	st--;
}

inline void init()
{
	st=stack;
}

int prim(int n)
{
	if(n%2==0) return 0;
	int up=(int)sqrt(n)+1;
	for(int i=3;i<=up;i+=2)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

void sum(int pos)
{
	if(st-stack==k)
	{
		int ans=0;
		for(int i=0;i<k;i++)
		{
			ans+=stack[i];
		}
		//printf("%d\n",ans);
		if(prim(ans)) res++;
	}	
	else if(pos==n) return;	
	else
	{
		for(int i=pos;i<n;i++)
		{
			push(array[i]);
			sum(i+1);
			pop();
		}
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	st=stack;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",array+i);
	sum(0);
	printf("%d\n",res);
	return 0;
}
			
