//Result:2012-06-26 17:54:39	 Accepted	3621	C++	180	188	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 0x7fffffffffffffff

typedef long long llint;

inline llint max(llint a,llint b)
{
	if(a>b) return a;
	else return b;
}

int hash[SIZE];

void init()
{
	memset(hash,-1,sizeof(hash));
	for(int i=0;i<10;i++) hash[i+'0']=i;
	for(int i=0;i<26;i++) hash[i+'A']=i+10;
	for(int i=0;i<26;i++) hash[i+'a']=i+36;
}

inline int ord(char x)
{
	return hash[int(x)];
}

llint convert(char* str,llint base)
{
	llint x=1;
	llint ans=0;
	for(int i=strlen(str)-1;i>=0;i--)
	{
		ans+=ord(str[i])*x;
		x*=base;
	}
	return ans;
}
			
llint slove(llint bignum,llint fac)
{
	llint ans=0;
	llint div=fac;
	while(bignum)
	{
		ans+=bignum/div;
		bignum/=div;
	}
	return ans;
}
		

int main()
{
	init();
	char x[SIZE];
	llint base;
	while(input(x>>base))
	{
		llint bignum=convert(x,base);
		llint ans=INF;
		for(int i=2;i<=62;i++)
		{
			int cnt=0;
			if(base==0) break;
			if(base % i==0)
			{
				while(base % i==0)
				{
					cnt++;
					base/=i;
				}
			}
			if(cnt) ans=min(ans,slove(bignum,i)/cnt);
		}
		print(ans);
	}
	return 0;
}		
	
