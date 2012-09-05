//Result:2012-08-15 15:01:42	Accepted	4365	281MS	12848K	1026 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10020
#define MOD 100000007
typedef long long llint;


bitset<SIZE> g[SIZE];
int n;


int fill_g(int a,int b)
{
	 if(g[a][b]) return 0;
	 else
	 {
		g[a][b]=g[b][a]=1;
		g[n-1-a][b]=g[b][n-1-a]=1;
		g[a][n-1-b]=g[n-1-b][a]=1;
		g[n-1-a][n-1-b]=g[n-1-b][n-1-a]=1;
		return 1;
	}
}

int fastPow(int a,int b)
{
	if(b==0) return 1;
	else if(b==1) return a%MOD;
	else
	{
		llint tmp=(llint)fastPow(a,b>>1);
		tmp=(tmp*tmp)%MOD;
		if(b%2==1) tmp=tmp*a;
		return tmp%MOD;
	}
}
		

int main()
{
	freopen("input.txt","r",stdin);
	int p,c;
	int a,b;
	while(input(n>>p>>c))
	{
		int sum=0;
		for(int i=0;i<n;i++) g[i].reset();
		for(int i=0;i<p;i++)
		{
			scanf("%d%d",&a,&b);
			sum+=fill_g(a,b);
		}
		sum=(1+((n+1)/2))*((n+1)/2)/2-sum;
		printf("%d\n",fastPow(c,sum));
	}
	return 0;
}
			
			
