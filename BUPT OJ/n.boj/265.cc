//Result:265	Accepted	751ms	7512kb	G++	995B	2012-04-20 11:18:51	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100005

typedef long long llint;

llint a[SIZE];
llint f[SIZE];
llint n,s,w,q,r;

void init(int n,llint s,llint w)
{
	llint g=s;
	for(int i=1;i<=n;i++)
	{
		a[i]=(g/7)%10;
		if(g&1) g=(g/2)^w;
		else g/=2;
	}
}

int main()
{
	while(input(n>>s>>w>>q>>r))
	{
		if(n+s+w+q+r==0) break;
		init(n,s,w);
		llint ans=0;
		if(q==2 || q==5)
		{
			s=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=0) s++;
				if(a[i]%q==r) ans+=s;
			}
		}
		else
		{
			memset(f,0,sizeof(f));
			f[n]=1;
			for(int i=n-1;i>=1;i--) f[i]=(f[i+1]*10)%q;
			map<int,int> m;
			m[r]=1;
			llint x=0;
			for(int i=n;i>=1;i--)
			{
				x=(x+a[i]*f[i])%q;
				if(a[i]) ans+=m[x];
				m[(r*f[i-1]+x)%q]++;
			}
		}
		print(ans);
	}
	return 0;
}
