//Result:1543 	Accepted	4127MS	240K	G++	1084B	2011-11-02 14:29:28
#include <cstdio>
#include <iostream>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation
#define SIZE 12

int n,m;
int array[SIZE];
int ans=0;
char bs[SIZE];


void dfs(int mod,int num)
{
	if(num==n)
	{
		if(!mod) ans++;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!bs[i])
			{
				bs[i]=1;
				char buffer[32];
				sprintf(buffer,"%d%d",mod,array[i]);
				int t=0;
				for(int j=0;buffer[j];j++)
				{
					t=t*10+buffer[j]-'0';
				}
				dfs(t%m,num+1);
				bs[i]=0;
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	input(n>>m);
	for(int i=0;i<n;i++) input(array[i]);
	dfs(0,0);
	print(ans);
	return 0;
}
