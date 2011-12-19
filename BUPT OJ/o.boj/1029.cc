//Result:1029 	Accepted	161MS	836K	G++	1006B	2011-11-14 11:52:50
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define llint long long
#define SIZE 10010

int n;
int array[SIZE];
int pos[SIZE];
int list[100010];
bitset<SIZE> bs;
priority_queue<int,vector<int>, greater<int> > pq;

int main()
{
	freopen("input.txt","r",stdin);
	input(n);
	bs.reset();
	int minVal=1<<20;
	for(int i=0;i<n;i++)
	{
		input(array[i]);
		pq.push(array[i]);
		minVal=min(minVal,array[i]);
	}
	for(int i=0;i<n;i++)
	{
		pos[i]=pq.top();
		list[pq.top()]=i;
		pq.pop();
	}
	
	llint ans=0;
	for(int i=0;i<n;i++)
	{
		if(bs[i]) continue;
		int len=0;
		int sum=0;
		int mint=1<<20;
		int p=i;
		while(1)
		{
			bs[p]=1;
			len++;
			sum+=pos[p];
			mint=min(mint,pos[p]);
			p=list[array[p]];
			if(p==i) break;
		}
		ans+=min(sum-mint+mint*(len-1), sum+mint+(len+1)*minVal);
	}
	print(ans);
	return 0;
}
