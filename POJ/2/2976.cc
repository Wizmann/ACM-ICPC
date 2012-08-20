//Result:wizmann	2976	Accepted	196K	94MS	C++	1025B

/*
 * 设我们要求的最终值为v
 * 则一定会满足以下条件:100*SUM(a)/SUM(b)=v
 * 所以理论情况下 RES=100*SUM(a)-v*SUM(b)==0
 * 当v'>v时，RES<0
 * 当v'<v时，RES>0
 * 
 * 又因为我们求的是能得到的最高分
 * 所以RES必为此时能取到的最大值
 * 我们将每一个节点用100*a-v*b的值来排序，找出最大的n-k个
 * 求和即为答案
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

const double eps=1e-2;

using namespace std;

typedef struct node
{
	int a,b;
	double val;

	inline void makeval(double mid){val=(double)a*100-mid*b;
	}
}node;

int n,k;
node array[1010];

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;
	if(ta->val>tb->val) return -1;
	else return +1;
}

int main()
{
	while(1)
	{
		memset(array,0,sizeof(array));
		scanf("%d%d",&n,&k);
		if(n+k==0) break;
		for(int i=0;i<n;i++) scanf("%d",&array[i].a);
		for(int i=0;i<n;i++) scanf("%d",&array[i].b);
		double l=0,r=100,mid;
		while(fabs(l-r)>eps)
		{
			mid=(l+r)/2;
			for(int i=0;i<n;i++) array[i].makeval(mid);
			qsort(array,n,sizeof(node),cmp);
			double sum=0;
			for(int i=0;i<n-k;i++) sum+=array[i].val;
			if(sum>0) l=mid;
			else r=mid;
		}
		printf("%.0f\n",mid);
	}
	return 0;
}
