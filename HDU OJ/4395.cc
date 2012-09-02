//Result:2012-08-31 10:43:44	Accepted	4395	718MS	736K	1398 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define BASE 200000
#define SIZE 240000
#define MULTI 10000
#define INF 1<<30
#define EPS (1e-8)

inline double eps(double x)
{
	return (x>0?EPS:-EPS);
}
	

char dp[SIZE+100];

void makeDP(int val)
{
	if(val>0)
	{
		for(int i=SIZE;i>=0;i--)
		{
			if(dp[i] && i+val<SIZE) dp[i+val]=1;
		}
	}
	else
	{
		for(int i=0;i<SIZE;i++)
		{
			if(dp[i] && i+val>=0) dp[i+val]=1;
		}
	}
}

int main()
{
	freopen("1006.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,n;
	double goal,tmp;
	input(T);
	while(T--)
	{
		int val;
		scanf("%lf%d",&goal,&n);
		memset(dp,0,sizeof(dp));
		dp[BASE]=1;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&tmp);
			val=(tmp+eps(tmp))*MULTI;
			makeDP(val);
		}

		val=int((goal+eps(goal))*MULTI)+BASE;
		goal=goal*MULTI+BASE;
		double dis=1e100;
		int ptr=INF;

		for(int i=val;i<BASE+20000;i++)
		{
			if(dp[i])
			{
				if(fabs(goal-i)<=dis && i<ptr)
				{
					dis=fabs(goal-i);
					ptr=i;
				}
				break;
			}
		}
		for(int i=val;i>BASE-20000;i--)
		{
			if(dp[i])
			{
				if(fabs(goal-i)<=dis && i<ptr)
				{
					dis=fabs(goal-i);
					ptr=i;
				}
				break;
			}
		}

		printf("%.4lf\n",(double)(ptr-BASE)/MULTI);
	}
	return 0;
}


		
