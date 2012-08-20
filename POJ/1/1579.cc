//Result:wizmann	1579	Accepted	748K	0MS	G++	936B	2012-06-09 23:46:44
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 24

int dp[SIZE][SIZE][SIZE];

inline int w(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0) return 1;
	else if(a>20 || b>20 || c>20) return w(20,20,20);
	else return dp[a][b][c];
}

void init()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			for(int k=0;k<SIZE;k++)
			{
				if(i<j && j<k)
				{
					dp[i][j][k]=w(i,j,k-1)+w(i,j-1,k-1)-w(i,j-1,k);
				}
				else
				{
					dp[i][j][k]=w(i-1,j,k)+w(i-1,j-1,k)+w(i-1,j,k-1)-w(i-1,j-1,k-1);
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	init();
	while(input(a>>b>>c))
	{
		
		if(a==-1 && b==-1 && c==-1) break;
		else
		{
			printf("w(%d, %d, %d) = ",a,b,c);
			print(w(a,b,c));
		}
	}
	return 0;
}
