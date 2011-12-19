//Result:wizmann	2287	Accepted	236K	32MS	C++	1234B
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
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define SIZE 1010
#define elif else if

int tj[SIZE],qw[SIZE];

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		memset(tj,0,sizeof(tj));
		memset(qw,0,sizeof(qw));
		for(int i=0;i<n;i++) scanf("%d",tj+i);
		for(int i=0;i<n;i++) scanf("%d",qw+i);
		
		sort(tj,tj+n);
		sort(qw,qw+n);
		int win=0,lose=0;
		int ta,tb,qa,qb;
		ta=qa=0;
		tb=qb=n-1;
		int cnt=0;
		while(cnt<n)
		{
			cnt++;
			if(tj[tb]>qw[qb])
			{
				win++;
				tb--;qb--;
			}
			elif(tj[tb]<qw[qb])
			{
				lose++;
				ta++;qb--;
			}
			else
			{
				if(tj[ta]>qw[qa])
				{
					win++;
					ta++;qa++;
				}
				else
				{
					if(tj[ta]<qw[qb]) lose++;
					ta++;qb--;
				}
			}
		}
		int ans=200*(win-lose);
		print(ans);
	}
	return 0;
}
