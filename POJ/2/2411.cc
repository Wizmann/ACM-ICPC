//Result:wizmann	2411	Accepted	272K	141MS	C++	953B	2011-09-23 22:23:41

/*
 * 参考：http://www.cppblog.com/NARUTOACM/archive/2009/12/22/103716.html
 * 0表示该格子为向右横排，或者向上竖排，1表示该格子为向下竖排
 * 上小到大一行一行考察，以f(i,j)表示在第i行状态为j时的总数，
 * 于是f(h,0)即为所求。即最后一排状态全为0，
 * 因为有1的话就会对下一排产生影响。
 * 所以一行中满足要求的就有1、00序列，
 * 不满足要求的有10，因为单个格子无法用小矩形填充
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int SIZE=(1<<11)+1;

long long dp[12][SIZE];
//最多12行，每行最多有2^11种状态

bool check(int nst)
{
	while(1)
	{
		if(!(nst&1)) nst>>=1;//合法情况: ...01
		else if(nst&1 && !(nst&2)) return false;//非法情况：..10
		else nst>>=2;//合法情况:...00
		if(nst==0) return true;
	}
}

void init(int w)
{
	int st=(1<<w)-1;
	for(int i=0;i<=st;i++)
	{
		if(check(st-i)) dp[1][i]=1;//如果这个状态是合法的，则标记1
		else dp[1][i]=0;//反之，则标记0
	}
}

long long sloveDP(int h,int w)
{
	if(h%2&&w%2) return 0;
	init(w);
	int status=(1<<w)-1;//状态个数
	for(int i=2;i<=h;i++)
	{
		for(int j=0;j<=status;j++)
		{
			dp[i][j]=0;
			for(int k=0;k<=status;k++)
			{
				if(dp[i-1][k]&&!(j&k)&&check(status-(j|k))) dp[i][j]+=dp[i-1][k];
				//如果( 上一个状态==存在 && 竖向放置的小块不冲突 && 
			}
		}
	}
	return dp[h][0];
}
int main()
{
	freopen("input.txt","r",stdin);
	int h,w;
	while(scanf("%d%d",&h,&w)&&(h+w))
	{
		if(h<w) swap(h,w);//减少枚举次数
		printf("%lld\n",sloveDP(h,w));
	}
	return 0;
}
