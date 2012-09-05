//Result:2012-09-01 13:14:48	Accepted	4000	187MS	708K	1133 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100

typedef long long llint;

const llint MOD=100000007LL;

struct BIT
{
	int baum[SIZE];
	static inline int lowbit(int x){return x&(-x);}
	void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int pos,int val)
	{
		while(pos<SIZE)
		{
			baum[pos]+=val;
			pos+=lowbit(pos);
		}
	}
	int sum(int pos)
	{
		int res=0;
		while(pos>0)
		{
			res+=baum[pos];
			pos-=lowbit(pos);
		}
		return res;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

int n;
BIT bit;

int main()
{
	int T,tmp,cas=1;
	input(T);
	while(T--)
	{
		llint ans=0;
		input(n);
		bit.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			int lx=bit.sum(1,tmp);//左边有多少比i小的
			int rx=(n-i)-(tmp-lx-1);//右边有多少比i大的
			//rx=(数列中有多少比i大的）-（左边比i大的）==右边比i大的
			ans-=(llint)lx*rx;
			if(rx>=2) ans+=(llint)rx*(rx-1)/2;
			bit.add(tmp,1);
		}
		printf("Case #%d: ",cas++);
		print(ans%MOD);
	}
	return 0;
}



