//Result:1923 	Accepted	3MS	220K	G++	557B	2011-11-30 10:30:08
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define max(a,b) ((a)>(b)?(a):(b))
#define input(x) cin>>x

int main()
{
	freopen("input.txt","r",stdin);
	long long gain,farmer,cost,money,dtime;
	while(input(gain>>farmer>>cost>>money>>dtime))
	{
		long long ans=money;
		for(int i=1;i<=dtime;i++)
		{
			if( (dtime-i+1)*gain>cost )
			{
				long long t=ans/cost;
				farmer+=t;
				ans-=t*cost;
			}
			ans+=farmer*gain;
		}
		print(ans);
	}
	return 0;
}
