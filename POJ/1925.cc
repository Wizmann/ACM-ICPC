//Result:wizmann	1925	Accepted	8164K	719MS	C++	1482B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define mul(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define elif else if
#define INF 1<<25
#define SIZE 5005
#define DIST 2000005

int n;
typedef struct node
{
	int x,y;
	double scale;
	
	inline void setNode(int a,int b,double t)
	{
		x=a;y=b;scale=t;
	}
}node;

node hause[SIZE];
int dp[DIST];

int main()
{
	int t,a,b;
	input(t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
		{
			double t;
			input(a>>b);
			t=mul(b)-mul(b-hause[1].y);
			hause[i].setNode(a,b,t);
		}
		memset(dp,-1,sizeof(dp));
		dp[hause[1].x] = 0;
		
		for(int i=2;i<=n;i++)
		{
			for(int j=hause[i].x-1;j>=hause[1].x;j--)
			{
				if(dp[j]==-1) continue;
				int gap=hause[i].x-j;
				if(mul(gap)>hause[i].scale) break;
				int aim =2*hause[i].x-j;
				if( (dp[aim]==-1 || dp[aim]>dp[j]+1) ) dp[aim]=dp[j]+1;

				if(aim >= hause[n].x && (dp[hause[n].x]==-1 || dp[hause[n].x]>dp[aim])) dp[hause[n].x]=dp[aim];
			}
		}
		if(dp[hause[n].x]<=0) print(-1);
		else printf("%d\n", dp[hause[n].x]);
	}
	return 0;
}
