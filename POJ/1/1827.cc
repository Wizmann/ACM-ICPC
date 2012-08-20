//Result:1827	Accepted	3480K	1516MS	G++	966B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010

struct node
{
	int strong,need;

	friend bool operator < (const node& a,const node& b)
	{
		if(a.strong!=b.strong) return a.strong>b.strong;
		else return a.need>b.need;
	}
};


set< int,greater<int> > numSet;
int n,m;
node array[SIZE];

int main()
{
	while(input(n>>m) && n+m)
	{
		numSet.clear();
		int ans=0;
		for(int i=1;i<=m;i++) numSet.insert(i);
		for(int i=0;i<n;i++) scanf("%d",&array[i].need);
		for(int i=0;i<n;i++) scanf("%d",&array[i].strong);
		sort(array,array+n);
		set<int>::iterator iter;
		for(int i=0;i<n;i++)
		{
			iter=numSet.lower_bound(array[i].need);
			if(iter==numSet.end())
			{
				ans+=array[i].strong;
			}
			else numSet.erase(*iter);
		}
		print(ans);
	}
	return 0;
}
