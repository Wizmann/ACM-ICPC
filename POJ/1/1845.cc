//Result:wizmann	1845	Accepted	192K	16MS	C++	1020B
/*
 *ans=MUL(1+pi^2+...pi^n*b)
 *MUL( (pi^n-1)/(p1-1) )中间有加减法运算，所以不能用快速幂取模
 *但是可以采用时间复杂度相同的二分运算，如下：
 *对每个1 +p+..+p^n 
 *n为奇数 : (1+p^n/2) + p^(n/2+1)*(1+...p^n/2)
 *n为偶数 : (1+p^n/2) + p^(n/2)*(p+...p^n/2)
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <iostream>

#define MOD 9901
#define LInt long long

using namespace std;

bitset<7100> bs;

void getPrim()
{
	for(int i=2;i<7100;i++)
	{
		if(bs[i]==0)
		{
			for(int j=2;i*j<7100;j++) bs[i*j]=1;
		}
	}
}

LInt fastPow(LInt a,LInt b)
{
	if(b==0) return 1;
	LInt t=fastPow(a,b/2);
	if(b%2) return (t*t*a)%MOD;
	else return (t*t)%MOD;
}

LInt cal(LInt a,LInt b)
{
	if(b==0) return 1;
	LInt ans=fastPow(a,b/2+1);
	ans=(ans+1)%MOD;
	if(b%2) ans=ans*cal(a,b/2)%MOD;
	else
	{
		ans=ans*cal(a,(b-1)/2)%MOD;
		ans+=fastPow(a,b/2);
	}
	return ans%MOD;
}

int main()
{
	freopen("input.txt","r",stdin);
	bs.reset();
	getPrim();
	LInt a,b;
	scanf("%lld%lld",&a,&b);
	LInt ans=1;
	for(int i=2;i<7100;i++)
	{
		if(a==1) break;
		if(bs[i]) continue;
		else if(a%i==0)
		{
			LInt c=0;
			while(a%i==0){c++;a/=i;}
			ans=ans*cal(i,b*c)%MOD;
		}
	}
	if(a!=1) ans*=cal(a,b)%MOD;
	printf("%lld\n",ans%MOD);
	return 0;
}
