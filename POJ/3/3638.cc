//Result:wizmann	3638	Accepted	1008K	625MS	C++	1228B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 222
#define INF 1<<25

double val[SIZE][SIZE],dp[SIZE][SIZE];
int array[SIZE];
int n,acc;

void init()
{
	//预处理，找出i,j两点的插值误差和，时间复杂度O(n^3)
	//val[i][j]代表的是以i,j两点为插点，i->j中间的误差和
	memset(val,0,sizeof(val));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			double t=(double)(array[i]-array[j])/(i-j);
			for(int k=i+1,pos=1;k<j;k++,pos++)
			{
				val[i][j]+=fabs(array[k]-array[i]-t*pos);
			}
			val[j][i]=val[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=acc-2;j++) dp[i][j]=INF;
	}
}
				
double slove()
{
	acc-=2;//acc - point(start) - point(end) => acc-=2
	//dp[i][j]代表的是从0->i中，有j个插值时的最小误差
	for(int i=0;i<n;i++)
	{
		dp[i][0]=val[0][i];
		//特判，如果确定点只有两个，那么中间的插点为0个
		//第i个位置的最小误差就是val[0][i]
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=acc;j++)
		{
			for(int k=0;k<i;k++)
			{
				dp[i][j]=min(dp[i][j],dp[k][j-1]+val[k][i]);
				//dp[i][j]=min( dp[i][j]，(以k为上一个插点的DP值＋k->i的插值和) )
			}
		}
	}
	return dp[n-1][acc];
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		input(n>>acc);
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++) input(array[i]);
		init();
		printf("%.4lf\n",slove()/n);
	}
	return 0;
}
		
