//Result:wizmann	3150	Accepted	4752K	1391MS	G++	1506B

#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#include <algorithm>
#include <string>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<30
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define SIZE 512


long long mat[SIZE][SIZE];
long long num[SIZE];
long long com[SIZE][SIZE];
int n,m,d,t;

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>m>>d>>t))
	{
		for(int i=0;i<n;i++) input(num[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(min(abs(i-j),n-abs(i-j))<=d) mat[i][j]=1;
				else mat[i][j]=0;
			}
		}
		while(t!=0)
		{
			if(t & 1)
			{
				for(int i=0;i<n;i++)
				{
					com[i][0]=0;
					for(int k=0;k<n;k++) com[i][0]=com[i][0]+mat[i][k]*num[k];
				}
				for(int i=0;i<n;i++) num[i]=com[i][0]%m;
			}
			for(int i=0;i<n;i++)
			{
				com[0][i]=0;
				for(int j=0;j<n;j++)
				{
					com[0][i]=com[0][i]+mat[0][j]*mat[j][i];
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==0) mat[i][j]=com[i][j]%m;
					else mat[i][j]=mat[i-1][(j-1+n)%n];
				}
			}
			t>>=1;
		}
		for(int i=0;i<n-1;i++)
		{
			printf("%lld ",num[i]);
		}
		printf("%lld\n",num[n-1]);
	}
	return 0;
}


