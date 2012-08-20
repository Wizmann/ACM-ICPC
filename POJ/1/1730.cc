//Result:wizmann	1730	Accepted	748K	32MS	G++	1444B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1<<16
#define abs(x) ((x)>0?(x):-(x))

typedef long long llint;

int pind;
llint prime[SIZE];
vector<int> fac;

void init()
{
	pind=1;
	prime[0]=2;
	for(int i=3;i<=(SIZE);i+=2)
	{
		bool flag=true;
		for(int j=0;j<pind && prime[j]*prime[j]<=i;j++)
		{
			if(i%prime[j]==0)
			{
				flag=0;
				break;
			}
		}
		if(flag) prime[pind++]=i;
	}
}					

void judge(llint x)
{
	fac.clear();
	for(int i=0;i<pind;i++)
	{
		//print(x);
		llint sum=0;
		if(x%prime[i]==0)
		{
			while(x%prime[i]==0)
			{
				sum++;
				x/=prime[i];
			}
		}
		if(sum) fac.push_back(sum);
	}
	if(x!=1) fac.push_back(1);
}

llint gcd(llint a,llint b)
{
	if(a<b) return gcd(b,a);
	else
	{
		if(a%b==0) return b;
		else return gcd(b,a%b);
	}
}			

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	init();
	llint x;

	while(scanf("%lld",&x)!=EOF && x)
	{
		//print(x);
		llint sig=x/abs(x);
		judge(x*sig);
		llint ans=-1;
		for(int i=0;i<(int)fac.size();i++)
		{
			if(!i) ans=fac[i];
			else ans=gcd(ans,fac[i]);
		}
		if(ans==-1) ans=1;
		if(sig>0) printf("%lld\n",ans);
		else
		{
			while(!(ans&1)) ans/=2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
