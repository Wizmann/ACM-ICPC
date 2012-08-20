#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
priority_queue<int,vector<int>,greater<int> > heap;

int main()
{
	//freopen("input.txt","r",stdin);
	int n,t;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		heap.push(t);
	}
	
	long long ans=0;
	while(heap.size()>1)
	{
		int temp=heap.top();
		heap.pop();
		temp+=heap.top();
		heap.pop();
		ans+=temp;
		heap.push(temp);
	}
	
	printf("%lld\n",ans);
	return 0;
}
