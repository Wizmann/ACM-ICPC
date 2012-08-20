//Result:wizmann	2392	Accepted	744K	407MS	G++	894B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 512
#define MAXN 40010

struct node
{
	int h,a,c;
	
	friend bool operator < (const node& na,const node& nb)
	{
		return na.a<nb.a;
	}
};

int n;
node array[SIZE];
bitset<MAXN> dp;

int main()
{
	freopen("input.txt","r",stdin);
	input(n);
	for(int i=0;i<n;i++)
	{
		input(array[i].h>>array[i].a>>array[i].c);
	}
	sort(array,array+n);
	dp.reset();
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<array[i].c;j++)
		{
			for(int k=array[i].a;k>=0;k--)
			{
				if(dp[k] && k+array[i].h<=array[i].a)
				{
					dp[k+array[i].h]=1;
				}
			}
		}
	}
	int ans=-1;
	for(int i=MAXN;i>=0;i--)
	{
		if(dp[i])
		{
			ans=i;
			break;
		}
	}
	print(ans);
	return 0;
}

