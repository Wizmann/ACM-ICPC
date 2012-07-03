//Result:wizmann	3696	Accepted	1156K	172MS	G++	2437B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <vector>

using namespace std;
typedef long long llint;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 45000

inline int mul(int x)
{
	return x*x;
}

int prime[SIZE],hash[SIZE];
int ind,sz;
int prime_factor[SIZE];
vector<llint> factor;

void init()
{
	ind=0;
	bitset<SIZE> p;
	for(int i=2;i<SIZE/2;i++)
	{
		if(p[i]) continue;
		else
		{
			for(int j=2;i*j<SIZE;j++) p[i*j]=1;
		}
	}

	for(int i=2;i<SIZE;i++)
	{
		if(!p[i]) prime[ind++]=i;
	}
}
llint gcd(llint a,llint b)
{
	if(a<b) return gcd(b,a);
	else if(a%b==0) return b;
	else return gcd(b,a%b);
}

llint eular(llint y)
{
	llint ans=1;
	for(int i=0;i<ind && mul(prime[i])<=y;i++)
	{
		if(y%prime[i]==0)
		{
			ans*=(prime[i]-1);
			y/=prime[i];
		}
		while(y%prime[i]==0)
		{
			y/=prime[i];
			ans*=prime[i];
		}
	}
	if(y!=1) ans*=(y-1);
	return ans;
}

void dfs(llint iter,llint val=1)
{
	if(iter==sz) factor.push_back(val);
	else
	{
		llint num=hash[iter];
		llint t=prime_factor[iter];
		llint t_val=val;
		for(int i=0;i<t;i++)
		{
			dfs(iter+1,t_val*num);
			t_val*=num;
		}
		dfs(iter+1,val);
	}
}

llint safemul(llint a,llint b,llint c)
{
	llint ans=0;
	while(b)
	{
		if(b&1) ans+=a;
		if(b>=2) a=(a+a)%c;
		ans%=c;
		b>>=1;
	}
	return ans;
}

llint fastmod(llint a,llint b,llint c)
{
	if(b==0) return 1;
	else if(b==1) return a%c;
	else
	{
		llint tmp=fastmod(a,b>>1,c)%c;
		tmp=safemul(tmp,tmp,c);
		if(b&1) return (tmp*a%c)%c;
		else return tmp%c;
	}
}

int slove(int x)
{
	factor.clear();
	memset(hash,0,sizeof(hash));
	sz=0;
	memset(prime_factor,0,sizeof(prime_factor));
	llint y=9LL*x/gcd(8,x);
	if(gcd(10,y)!=1) return 0;
	llint e=eular(y);
	//print(e<<' '<<y);
	for(int i=0;i<ind && prime[i]*prime[i]<=e;i++)
	{
		while(e%prime[i]==0)
		{
			prime_factor[sz]++;
			e/=prime[i];
		}
		hash[sz]=prime[i];
		sz++;
	}
	hash[sz]=e;
	prime_factor[sz++]++;
	dfs(0,1);
	sort(factor.begin(),factor.end());
	for(int i=0;i<(int)factor.size();i++)
	{
		if(fastmod(10,factor[i],y)==1) return factor[i];
	}
	return 0;
}


int main()
{
	int x,cas=1;
	init();
	while(scanf("%d",&x)!=EOF && x)
	{
		printf("Case %d: ",cas++);
		print(slove(x));
	}
	return 0;
}

