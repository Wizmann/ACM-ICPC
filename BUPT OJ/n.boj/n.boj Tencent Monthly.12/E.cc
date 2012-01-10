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

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation

int mat[128][128];
int sum[128];

int check(int n)
{
	int ans=0,t=0;
	for(int i=0;i<n;i++)
	{
		t+=sum[i];
		ans=max(t,ans);
		if(t<0) t=0;
	}
	return ans;
}

int main()
{
	freopen("E.txt","r",stdin);
	int n;
	while(input(n) && n)
	{
		int ans=0;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&mat[i][j]);
		}
		for(int i=0;i<n;i++)
		{
			memset(sum,0,sizeof(sum));
			for(int j=i;j<n;j++)
			{
				for(int k=0;k<n;k++) sum[k]+=mat[j][k];
				ans=max(check(n),ans);
			}
		}
		print(ans);
	}
	return 0;
}
