#include <stdio.h>
//#include <time.h>

inline int prim(int n)
{
	if(n==1) return 1;	
	if(n==2) return 0;
	if(n%2==0) return 1;
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0) return 1;
	}
	return 0;
}

inline void rev(int n,int *p)
{
	if(n<10) *p=*p*10+n;
	else
	{
		*p=*p*10+n%10;
		rev(n/10,p);
	}
}

int main()
{
	int a,b;
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&a,&b)!=-1)
	{
		int sum=0;
		int re=0;
		for(int i=a;i<=b;i++)
		{
			if(i%2==0&&i!=2) continue;
			if(i%3==0&&i!=3) continue;
			if(i%5==0&&i!=5) continue;
			rev(i,&re);
			if(re==i&&prim(i)==0)
			{
				//printf("RE:%d\n",re);
				sum++;
			}
			re=0;
		}
		printf("%d\n",sum);
	}
	//printf("THE TIME USED:%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
