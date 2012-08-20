//Result:wizmann	3557	Accepted	804K	94MS	G++	718B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 25

double dp[SIZE];
int n;
double p;
int C[SIZE][SIZE];

void init()
{
	for(int i=0;i<SIZE;i++)
	{
		C[i][0]=C[i][i]=1;
	}
	for(int i=2;i<SIZE;i++)
	{
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
}

int main()
{
	input(n>>p);
	init();
	dp[1]=1.;
	for(int i=2;i<=n;i++)
	{
		double ans=0;
		/* dp[i]为在当前情况下，构成i个点的连通点集的概率
		 * 
		 * 若要计算dp[i]，则要从i-1的点中，划分出一个j-1的子集，所以共有C(i-1,j-1)的子集
		 * 然后再将这个j-1子集，加上新加入的点，若使这j个点构成连通点集，概率为dp[j]
		 * 若使这i个点不连通，则在上面所说的两个字集之间没有连通的边，一共有j*(i-j)种可能的边
		 * 所以概率为(1-p)^(j*(i-j))
		 * 
		 * 将j=(1,i-1)的所有情况加到一起，得到的就是有i个点的情况下，不能构成连通图的概率
		 * 所以dp[i]=1-sigma(C[i-1][j-1]*dp[j]*pow(1-p,double(j*(i-j)))
		 * 
		 */ 
		
		for(int j=1;j<i;j++)
		{
			ans+=C[i-1][j-1]*dp[j]*pow(1-p,double(j*(i-j)));
		}
		dp[i]=1-ans;
	}
	
	print(dp[n]);
	return 0;
}

