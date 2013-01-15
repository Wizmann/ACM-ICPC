//Result:Wizmann	UVA 11292	Accepted	0 KB	48 ms	C++ 4.5.3	854 B	2013-01-15 20:52:09
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20480
#define pq priority_queue

int main()
{
	freopen("input.txt","r",stdin);
	int n,m,t;
	pq< int,vector<int>,greater<int> > head,knight;

	while(input(n>>m) && n+m)
	{
		while(!head.empty()) head.pop();
		while(!knight.empty()) knight.pop();
		for(int i=0;i<n;i++)
		{
			input(t);
			head.push(t);
		}
		for(int i=0;i<m;i++)
		{
			input(t);
			knight.push(t);
		}

		int ok=0,cost=0;
		while(!head.empty() && !knight.empty())
		{
			int hh=head.top();
			head.pop();
			int kk=knight.top();
			knight.pop();

			if(hh>kk)
			{
				head.push(hh);
			}
			else
			{
				ok++;
				cost+=kk;
			}
		}

		if(ok==n) print(cost);
		else print("Loowater is doomed!");
	}
	return 0;
}


