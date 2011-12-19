#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
	priority_queue< int,vector<int>,greater<int> > heap;
	long long ans=0,sum;	
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%d",&temp);heap.push(temp);}
	while(heap.size()>1){sum=heap.top();heap.pop();sum+=heap.top();heap.pop();ans+=sum;heap.push(sum);}	
	printf("%lld\n",ans);
	return 0;
}
