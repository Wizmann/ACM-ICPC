#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define min(a,b) ((a)>(b)?(b):(a))

struct node
{
	int pos,ok;
};

int n;

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;
	return ta->pos-tb->pos;
}

node home[100001];

int main()
{
	freopen("input.txt","r",stdin);
	int sum;
	while(scanf("%d",&n),n)
	{
		memset(home,0,sizeof(home));
		sum=0;
		int ans=1<<30;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&(home[i].pos));
			sum+=home[i].pos;
		}
		for(int i=0;i<n;i++) scanf("%d",&home[i].ok);
		qsort(home,n,sizeof(node),cmp);
		int tsum=0;
		for(int i=0;i<n;i++)
		{
			sum-=home[i].pos;
			int t=sum;
			t-=(n-i-1)*(home[i].pos);
			t+=i*home[i].pos-tsum;
			tsum+=home[i].pos;
			if(!home[i].ok) continue;
			ans=min(t,ans);
		}

		printf("%d\n",abs(ans));
	}
	return 0;
}

