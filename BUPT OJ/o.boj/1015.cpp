#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long GCD(long long a,long long b)
{
	if(b==0) return a;
	
	if(a>=b)
	{
		if(a%b==0) return b;
		else
		{
			return GCD(b,a%b);
		}
	}
	else return GCD(b,a);
}

long long LCM(long long a,long long b)
{
	return (a*b)/GCD(a,b);
}

void plus(long long a,long long b,long long c,long long d)
{
	long long mother=LCM(a,c);
	long long son=b*(mother/a)+d*(mother/c);
	bool flag=true;
	if(son<0)
	{
		son=-son;
		flag=false;
	}
	if(!flag) printf("-");
	
	long long g=GCD(son,mother);
	printf("%lld/%lld\n",son/g,mother/g);
}

void mul(long long a,long long b,long long c,long long d)
{
	long long mother=a*c;
	long long son=b*d;
	long long g=GCD(mother,son);
	
	printf("%lld/%lld\n",son/g,mother/g);
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	
	char sig;
	int a,b,c,d;
	
	while(counter--)
	{
		do
		{
			scanf("%c",&sig);
		}while(sig!='+'&&sig!='-'&&sig!='*'&&sig!='/');
		
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		if(sig=='+') plus(a,b,c,d);
		else if(sig=='-') plus(a,b,c,-d);
		else if(sig=='*') mul(a,b,c,d);
		else if(sig=='/') mul(a,b,d,c);
	}
	return 0;
}