/*
Permutation
Time Limit: 1000MS		Memory Limit: 32768KB

Description
There is an arrangement of N numbers and a permutation relation that alter one arrangement into another.
For example, when N equals to 6 the arrangement is 123456 at first. The replacement relation is 312546 (indicate 1->2, 2->3, 3->1, 4->5, 5->4, 6->6, the relation is also an arrangement distinctly).
After the first permutation, the arrangement will be 312546. And then it will be 231456.
In this permutation relation (312546), the arrangement will be altered into the order 312546, 231456, 123546, 312456, 231546 and it will always go back to the beginning, so the length of the loop section of this permutation relation equals to 6.
Your task is to calculate how many kinds of the length of this loop section in any permutation relations.
 
Input
Input contains multiple test cases. In each test cases the input only contains one integer indicates N. For all test cases, N<=1000.
 
Output
For each test case, output only one integer indicates the amount the length of the loop section in any permutation relations.
 
Sample Input
1
2
3
10
 
Sample Output
1
2
3
16
*/


//Result:2012-08-08 15:37:37	Accepted	4345	0MS	8476K	1236 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1010

typedef long long llint;

int prime[SIZE];
int cnt;

void init()
{
	cnt=0;
	bitset<SIZE+10> bs;
	for(int i=4;i<SIZE+10;i+=2) bs[i]=1;
	for(int i=3;i<SIZE+10;i+=2)
	{
		for(int j=2;i*j<SIZE+10;j++)
		{
			bs[i*j]=1;
		}
	}
	prime[0]=2;cnt++;
	for(int i=3;i<SIZE+10;i+=2)
	{
		if(!bs[i]) prime[cnt++]=i;
	}
}


llint dp[SIZE+10][SIZE+10];
llint ans[SIZE+10];

llint dfs(int x,int t)
{
	if(dp[x][t]!=-1) return dp[x][t];
	else
	{
		if(prime[t]>x)
		{
			return dp[x][t]=1;
		}
		dp[x][t]=dfs(x,t+1);
		int k=prime[t];
		while(k<=x)
		{
			dp[x][t]+=dfs(x-k,t+1);
			k*=prime[t];
		}
		return dp[x][t];
	}
}
	

int main()
{
	int x;
	init();
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<SIZE;i++)
	{
		ans[i]=dfs(i,0);//求一个数是由多少不同质数之和组成
	}
	while(input(x)) print(ans[x]);
	return 0;
}
	
	
	
