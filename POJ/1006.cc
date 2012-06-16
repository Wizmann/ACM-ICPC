//Result:wizmann	1006	Accepted	720K	94MS	G++	1017B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl

const int cycle[]={23,28,33};
int mod[3];

int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	else
	{
		if(a%b==0) return b;
		else return gcd(b,a%b);
	}
}

int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

void init()
{
	for(int i=0;i<3;i++)
	{
		int a=i;
		int b=(i+1)%3;
		int c=(i+2)%3;
		int l=lcm(cycle[a],cycle[b]);
		mod[c]=l;
		while(mod[c]%cycle[c]!=1) mod[c]+=l;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int array[4];
	int cas=1;
	int MOD=cycle[0]*cycle[1]*cycle[2];
	init();
	while(input(array[0]) && array[0]>=0)
	{
		for(int i=1;i<4;i++) input(array[i]);
		long long ans=0;
		for(int i=0;i<3;i++) ans+=array[i]*mod[i];
		ans%=MOD;
		ans-=array[3];
		if(ans<=0) ans+=MOD;
		
		printf("Case %d: the next triple peak occurs in %lld days.\n",cas++,ans);
	}
	return 0;
}
		


