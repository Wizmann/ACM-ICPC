//Result:wizmann	3519	Accepted	364K	0MS	C++	1284B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define DICE 6
#define eps 1e-8
#define ROLL (1.0/6)

double dp[SIZE][SIZE];
char back[SIZE],delay[SIZE];//Hash存储
int n,t,b,d;

inline bool iszero(double i_fval)
{
	return fabs(i_fval)<eps;
}

void slove()
{
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!iszero(dp[j][i]))
			{
				for(int k=1;k<=DICE;k++)
				{
					int next=j+k;
					int pos=i+1;
					if(next>n) next=n-(next-n);
					if(!back[next])
					{
						if(delay[next]) pos++;
						dp[next][pos]+=dp[j][i]*ROLL;
					}
					else
					{
						dp[0][i+1]+=dp[j][i]*ROLL;
					}
				}
			}
		}
	}
}
						

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>t>>d>>b) && n+t)
	{
		int tmp;
		memset(dp,0,sizeof(dp));
		memset(back,0,sizeof(back));
		memset(delay,0,sizeof(delay));
		for(int i=0;i<d;i++)
		{
			input(tmp);delay[tmp]=1;
		}
		for(int i=0;i<b;i++)
		{
			input(tmp);back[tmp]=1;
		}
		dp[0][0]=1.0;
		slove();
		double ans=0;
		for(int i=0;i<=t;i++) ans+=dp[n][i];
		printf("%.6lf\n",ans);
	}
	return 0;
}
			


