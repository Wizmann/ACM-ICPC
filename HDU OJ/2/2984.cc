#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int mini,n;
double b;

double tri(double x,double r)
{
	return (x-r)/(1.+pow(x-mini,b))+r;
}

double slove(int l,double ex)
{
	int r=10000000;
	while(l<r-1)
	{
		int lt=(l+r)/2;
		int rt=(lt+r)/2;
		double ltVal=tri(lt,ex);
		double rtVal=tri(rt,ex);
		if(ltVal>=rtVal) r=rt;
		else l=lt;
	}
	return max(tri(l,ex),tri(r,ex));
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	while(input(n>>mini>>b))
	{
		double maxn=mini;
		for(int i=0;i<n-1;i++)
		{
			maxn=slove(mini,maxn);
		}
		printf("Case %d: %.2f\n",cas++,maxn);
	}
	return 0;
}
