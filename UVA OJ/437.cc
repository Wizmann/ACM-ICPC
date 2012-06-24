//Result:437	The Tower of Babylon	Accepted	C++	0.008	2012-06-23 06:45:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

struct node
{
	int a,b,h;
	node(){}
	node(int i_a,int i_b,int i_h)
	{
		a=i_a;b=i_b;h=i_h;
	}
	friend bool operator < (const node& x, const node& y)
	{
		return (x.a*x.b)>(y.a*y.b);
	}
	
	bool make_up(const node& x)
	{
		return (a<x.a && b<x.b) || (a<x.b && b<x.a);
	}
};

node box[SIZE];
int n,ind;
int dp[SIZE];

int slove(int pos)
{
	if(dp[pos]) return dp[pos];
	
	for(int i=0;i<ind;i++) if(pos!=i)
	{
		if(box[pos].make_up(box[i]))
		{
			dp[pos]=max(dp[pos],box[pos].h+slove(i));
		}
	}
	dp[pos]=max(dp[pos],box[pos].h);
	return dp[pos];
}

int main()
{
	freopen("i.txt","r",stdin);
	int d[3];
	int cas=0;
	while(input(n) && n)
	{
		ind=0;
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%d",&d[j]);
			}
			for(int j=0;j<3;j++)
			{
				box[ind]=node(d[j],d[(j+1)%3],d[(j+2)%3]);
				ind++;
			}
		}
		printf("Case %d: maximum height = ",++cas);
		for(int i=0;i<ind;i++) 
		{
			ans=max(ans,slove(i));
		}
		print(ans);
	}
	return 0;
}

		

