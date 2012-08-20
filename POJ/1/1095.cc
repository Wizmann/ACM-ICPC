//Result:wizmann	1095	Accepted	712K	16MS	G++	1079B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20

int branch[SIZE];
int sum[SIZE];

void init()
{
	branch[0]=branch[1]=1;
	sum[0]=0;sum[1]=1;
	
	for(int i=2;i<SIZE;i++)
	{
		for(int j=0;j<i;j++)
		{
			branch[i]+=branch[j]*branch[i-j-1];
		}
	}
	for(int i=2;i<SIZE;i++)
	{
		sum[i]+=sum[i-1]+branch[i];
	}
}

void slove(int n)
{
	if(n==0) return;
	if(n==1) printf("X");
	else
	{
		int i,j;
		for(i=0;i<SIZE;i++)
		{
			if(sum[i]>=n) break;
		}
		n-=sum[i-1];
		//i指的是，在此(子)树中，共有多少个节点
		
		//由于树的构建是先右后左，所以j表示的是左子树的节点数
		for(j=0;j<i;j++)
		{
			int t=branch[j]*branch[i-j-1];
			if(t<n) n-=t;
			else break;
		}
		
		//那么首先是右子树在发生变化，从1到L[n-i-1]。
		//继续增长，右子树的形态复位为1，而左子树的形态增加1.
		//因此右子树相当于秒针，左子树相当于分针。
		//对于s，该树的左子树编号为(s-1)/L[n-i-1]+1，右子树编号为(s-1)% L[n-i-1]+1。
		if(j)//如果左子树有节点
		{
			printf("(");
			slove(sum[j-1]+(n-1)/branch[i-j-1]+1);
			printf(")");
		}
		printf("X");
		if(j!=i-1)
		{
			printf("(");
			slove(sum[i-j-2]+(n-1)%branch[i-j-1]+1);
			printf(")");
		}
	}
}

int main()
{
	int n;
	init();
	while(input(n) && n)
	{
		slove(n);
		puts("");
	}
	return 0;
}
