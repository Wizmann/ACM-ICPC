//Result:wizmann	3761	Accepted	8576K	547MS	G++	912B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define K 1000010
#define MOD 20100713

long long mul[K];

void init()
{
	mul[0]=1;
	for(int i=1;i<K;i++)
	{
		mul[i]=(mul[i-1]*i)%MOD;
	}
}

long long fastmod(long long a,long long b)//return (a^b)%MOD
{
	if(b==0) return 1;
	else if(b==1) return a%MOD;
	else
	{
		long long t=fastmod(a,b/2);
		t=(t*t)%MOD;//WA here,do MOD every step if possible
		if(b&1) return (t*a)%MOD;
		else return t;
	}
}

/*
 * 由冒泡排序的性质，每一次排序，对于每一个数x来说，逆序性质d(x)=d(x)-1
 * 所以K＝max(foreach d(x))
 * 
 * 对于最小的数p，若使其逆序性质小于等于K，则有K+1种放置方法
 * 对于次小数q，若同上，对于（2～N）数列，也有K＋1种放置方法
 * 所以方法数为(k+1)^(n-k)，又由于k个数可以自由排列，乘上k!
 * 得到结果F(n,k)，即n个数，用少于K次排序可以完成的排列数
 * 
 * 所以我们最终的答案就是F(n,k)-F(n,k-1)
 * 优化后的式子为long long res=mul[k]*(fastmod(k+1,n-k)-fastmod(k,n-k));
 * 
 * 总结：这玩意真不是人想的。。。－ －。。。
 * By Moody _"Kuuy"_ Wizmann @ 3^Nokia
 * 
 * 2012-5-12 00:53AM
 * 
 * I love Lisa.么么哒～
 */



long long slove(int n,int k)
{
	//printf("%lld %lld %lld\n",fastmod(k+1,n-k),fastmod(k,n-k),mul[k]);
	long long res=mul[k]*(fastmod(k+1,n-k)-fastmod(k,n-k));
	res%=MOD;
	return res<0?res+MOD:res;
}

int main()
{
	init();
	int T,a,b;
	input(T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		print(slove(a,b));
	}		
	return 0;
}
