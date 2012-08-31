//Result:2012-08-24 09:21:43	Accepted	4395	718MS	736K	1580B	G++	Wizmann
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

char dp[SIZE];

void makeDP(int val)
{
	if(val>0)
	{
		for(int i=SIZE-1;i>=0;i--)
		{
			if(dp[i])
			{
				int c=(i+val);
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
				int c=(i+val);
				if(c>0) dp[c]=1;
			}
		}
	}
}


int main()
{
	int T,n;
	double gg,tmp;
	input(T);
	while(T--)
	{
		//dp.reset();
		memset(dp,0,sizeof(dp));
		scanf("%lf%d",&gg,&n);
		dp[BASE]=1;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&tmp);
			int tt=(int)((tmp*10000.)+(tmp>0?eps:-eps));
			makeDP(tt);
		}
		//print(gg);
		//print("OK");
		double dis=1e10;
		int ptr=INF;
		//printf("%.d\n",int((gg*10000.)+(gg>0?eps:-eps))+BASE);
		int gate=int((gg*10000.)+(gg>0?eps:-eps))+BASE;
		//print(">>"<<gate);
		for(int i=gate;i<BASE+20000;i++)
		{
			if(dp[i])
			{
				//print(">>"<<i);
				if(dis>fabs(gg*10000.+BASE-i))
				{
					dis=fabs(gg*10000.+BASE-i);
					ptr=i;
				}
				break;
			}
		}

		for(int i=gate;i>=BASE-20000;i--)
		{
			if(dp[i])
			{
				//print(">>"<<i);
				if(dis>=fabs(gg*10000.+BASE-i))
				{
					dis=fabs(gg*10000.+BASE-i);
					ptr=i;
				}
				break;
			}
		}
		printf("%.4lf\n",(double)(ptr-BASE)/10000);
	}
	return 0;
}


