<<<<<<< HEAD
//Result:2012-08-31 10:43:44	Accepted	4395	718MS	736K	1398 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
=======
//Result:2012-08-24 09:21:43	Accepted	4395	718MS	736K	1580B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iostream>
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define BASE 200000
#define SIZE 240000
<<<<<<< HEAD
#define MULTI 10000
#define INF 1<<30
#define EPS (1e-8)

inline double eps(double x)
{
	return (x>0?EPS:-EPS);
}
	

char dp[SIZE+100];
=======

const double eps=1e-8;
const int INF=1<<25;

char dp[SIZE];
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d

void makeDP(int val)
{
	if(val>0)
	{
<<<<<<< HEAD
		for(int i=SIZE;i>=0;i--)
		{
			if(dp[i] && i+val<SIZE) dp[i+val]=1;
=======
		for(int i=SIZE-1;i>=0;i--)
		{
			if(dp[i])
			{
				int c=(i+val);
				if(c<SIZE) dp[c]=1;
			}
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
		}
	}
	else
	{
		for(int i=0;i<SIZE;i++)
		{
<<<<<<< HEAD
			if(dp[i] && i+val>=0) dp[i+val]=1;
=======
			if(dp[i])
			{
				int c=(i+val);
				if(c>0) dp[c]=1;
			}
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
		}
	}
}

<<<<<<< HEAD
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
=======

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
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
		dp[BASE]=1;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&tmp);
<<<<<<< HEAD
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
=======
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
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
					ptr=i;
				}
				break;
			}
		}
<<<<<<< HEAD
		for(int i=val;i>BASE-20000;i--)
		{
			if(dp[i])
			{
				if(fabs(goal-i)<=dis && i<ptr)
				{
					dis=fabs(goal-i);
=======

		for(int i=gate;i>=BASE-20000;i--)
		{
			if(dp[i])
			{
				//print(">>"<<i);
				if(dis>=fabs(gg*10000.+BASE-i))
				{
					dis=fabs(gg*10000.+BASE-i);
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
					ptr=i;
				}
				break;
			}
		}
<<<<<<< HEAD

		printf("%.4lf\n",(double)(ptr-BASE)/MULTI);
=======
		printf("%.4lf\n",(double)(ptr-BASE)/10000);
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
	}
	return 0;
}


<<<<<<< HEAD
		
=======
>>>>>>> 496da4b53e34566d610925224305ebca91bac60d
