//Result:2012-08-15 14:04:25	Accepted	4362	296MS	916K	2061 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 52
#define N 1005

struct node
{
	int pos,cost;
	friend bool operator < (const node& a,const node& b)
	{
		return a.pos<b.pos;
	}
};

void pushin(deque<int> &dq,int val)
{
	if(dq.empty()) dq.push_back(val);
	else
	{
		int sz=dq.size();
		while(sz)
		{
			if(dq[sz-1]>val)
			{
				sz--;
				dq.pop_back();
			}
			else break;
		}
		dq.push_back(val);
	}
}	

int main()
{
	node ball[SIZE][N];
	int dp[SIZE][N];
	const int INF=1<<25;
	int T,a,m,n,x;
	input(T);
	while(T--)
	{
		deque<int> dq;
		scanf("%d%d%d",&m,&n,&x);
		memset(ball,0,sizeof(ball));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a);
				ball[i][j].pos=a;
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a);
				ball[i][j].cost=a;
			}
		}
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<m;i++)
		{
			sort(ball[i],ball[i]+n);
		}
		for(int i=0;i<n;i++)
		{
			dp[0][i]=abs(x-ball[0][i].pos)+ball[0][i].cost;
		}
		for(int i=1;i<m;i++)
		{
			
			dq.clear();
			int ptr=0;
			for(int j=0;j<n;j++)
			{
				while(ball[i-1][ptr].pos<=ball[i][j].pos && ptr<n)
				{
					pushin(dq,dp[i-1][ptr]-ball[i-1][ptr].pos);
					ptr++;
				}
				if(!dq.empty() && dp[i][j]>dq[0]+ball[i][j].pos+ball[i][j].cost)
				{
					dp[i][j]=dq[0]+ball[i][j].pos+ball[i][j].cost;
				}
			}
			dq.clear();
			ptr=n-1;
			for(int j=n-1;j>=0;j--)
			{
				while(ball[i-1][ptr].pos>=ball[i][j].pos && ptr>=0)
				{
					pushin(dq,dp[i-1][ptr]+ball[i-1][ptr].pos);
					ptr--;
				}
				if(!dq.empty() &&  dp[i][j]>dq[0]-ball[i][j].pos+ball[i][j].cost)
				{
					dp[i][j]=dq[0]-ball[i][j].pos+ball[i][j].cost;
				}
			}
		}
		int ans=INF;
		for(int i=0;i<n;i++)
		{
			ans=min(ans,dp[m-1][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}


