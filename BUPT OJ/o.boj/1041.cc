#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define SIZE 1000000
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define mul(x) ((long long)(x)*(x))

int num[SIZE];
long long cost[SIZE];
int n,k;

int main()
{
	freopen("input.txt","r",stdin);
	int shop;
	while(input(n>>k))
	{
		if(n+k==0) break;
		if(k==1)
		{
			print(n);
			continue;
		}
		shop = log(n)/log(k)+1;
		cost[0]=1;
		for(int i=0;i<shop;i++) cost[i+1]=cost[i]*k;
		memset(num,0,sizeof(num));
		
		for(int i=0;i<n;i++)
		{
			long long tmin=mul(n);
			int pos=0;
			for(int j=0;j<shop;j++)
			{
				long long delta=cost[j]*(num[j]*2+1);
				if(delta<tmin)
				{
					tmin=delta;
					pos=j;
				}
				if(num[j]==0) break;
			}
			num[pos]++;
		}
		long long sum=0;
		for(int i=0;i<shop;i++) sum+=cost[i]*mul(num[i]);
		
		print(sum);
	}
	return 0;
}


