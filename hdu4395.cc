#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define BASE 200000
#define SIZE 240000

const double eps=1e-8;
const int INF=1<<25;

bitset<SIZE> dp;

void makeDP(int val)
{
	if(val>0)
	{
		for(int i=SIZE-1;i>=0;i--)
		{
			if(dp[i])
			{
				int a=i-BASE;
				int b=val;
				int c=(a+b)+BASE;
				if(c<SIZE) dp[c]=1;
			}
		}
	}
	else
	{
		for(int i=0;i<SIZE;i++)
		{
			if(dp[i])
			{
				int a=i-BASE;
				int b=val;
				int c=(a+b)+BASE;
				if(c>0) dp[c]=1;
			}
		}
	}
}


int main()
{
	freopen("1006.in","r",stdin);
	int T,n;
	double gg,tmp;
	input(T);
	while(T--)
	{
		dp.reset();
		scanf("%lf%d",&gg,&n);
		dp[BASE]=1;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&tmp);
			int tt=(tmp*10000.)+(tmp>0?eps:-eps);
			makeDP(tt);
		}
		//print("OK");
		double dis=1e10;
		int ptr=INF;
		int gate=(gg*10000.)+(gg>0?eps:-eps)+BASE;
		for(int i=gate;i<BASE+20000;i++)
		{
			if(dp[i])
			{
				if(dis>fabs(gg*10000.-i))
				{
					dis=fabs(gg*10000.-i);
					ptr=i;
				}
				break;
			}
		}

		for(int i=gate;i>=BASE-20000;i--)
		{
			if(dp[i])
			{
				if(dis>=fabs(gg*10000.-i))
				{
					dis=fabs(gg*10000.-i);
					ptr=i;
				}
				break;
			}
		}
		printf("%.4lf\n",(double)(ptr-BASE)/10000.+eps);
	}
	return 0;
}


