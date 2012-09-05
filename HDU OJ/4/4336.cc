//Result:2012-08-03 11:34:36	Accepted	4336	453MS	272K	861 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20

const double eps=1e-4;

int n;
double card[SIZE+5];
int end;

double dfs(int pos,int step=0,double val=0.0)
{
	if(end==step) return 1./(val+card[pos]);
	else
	{
		double res=0,add=0;
		if(pos>=0) add=card[pos];
		for(int i=pos+1;i<n;i++)
		{
			res+=dfs(i,step+1,val+add);
		}
		return res;
	}
}

int main()
{
	double ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		int sig=1;
		for(int i=0;i<n;i++) scanf("%lf",card+i);
		for(int i=0;i<n;i++)
		{
			end=i+1;
			double t=dfs(-1);
			if(t<eps) break;
			else
			{
				ans+=t*sig;
				sig*=-1;
			}
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}

		



