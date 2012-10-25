//Result:2012-10-15 21:07:49	 Accepted	3665	C++	230	11600	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000010
#define INF 1LL<<60
#define MAXVAL 1000000000000LL
#define N 45

typedef long long llint;

llint dp[N][10240];
int head[N];
llint zwei[SIZE];

llint fastpow(llint a,llint b)
{
	llint k=1;
	while(b)
	{
		if(b&1) k=k*a;
		a=a*a;
		b>>=1;
	}
	return k;
}


void init()
{
	memset(dp,0,sizeof(dp));
	memset(head,0,sizeof(head));
	for(llint i=2;i<SIZE;i++)
	{
		zwei[i]=i*i+i+1;
	}
	for(llint i=2;;i++)
	{
		llint sum=1LL+i+(i*i)+(i*i*i);
		if(sum>MAXVAL) break;
		dp[3][i]=sum;
		head[3]=i+1;
	}
	for(int i=4;i<N;i++)
	{
		for(int j=2;j<head[i-1];j++)
		{
			llint sum=dp[i-1][j]+fastpow(j,i);
			if(sum>MAXVAL) break;
			dp[i][j]=sum;
			head[i]=j+1;
		}
	}
}

void sloveZwei(llint &ir,llint &ik,llint x)
{
	int ptr=upper_bound(zwei+2,zwei+SIZE,x)-zwei-1;
	if(zwei[ptr]==x)
	{
		if(ir*ik>ptr*2)
		{
			ir=2;
			ik=ptr;
		}
	}
}


pair<llint,llint> slove(llint x)
{
	llint r,k;
	r=1;
	k=x-1;
	sloveZwei(r,k,x);
	for(int i=3;i<N;i++)
	{
		int ptr=upper_bound(dp[i]+2,dp[i]+head[i],x)-dp[i]-1;
		if(dp[i][ptr]==x)
		{
			llint tmpk=ptr;
			llint tmpr=i;
				if(tmpk*tmpr<r*k)
			{
				r=tmpr;k=tmpk;
			}
			else if(tmpk*tmpr==r*k && tmpr<r)
			{
				r=tmpr;k=tmpk;
			}
		}
	}
	return make_pair(r,k);
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.ans","w",stdout);
	llint x;
	init();
	while(input(x))
	{
		pair<llint,llint> a,b;
		a=slove(x);
		b=slove(x+1);

		if(a.first*a.second<b.first*b.second)
		{
			print(a.first<<' '<<a.second);
		}
		else if(a.first*a.second==b.first*b.second)
		{
			if(a.first<b.first) print(a.first<<' '<<a.second);
			else print(b.first<<' '<<b.second);
		}
		else print(b.first<<' '<<b.second);
	}
	return 0;
}


