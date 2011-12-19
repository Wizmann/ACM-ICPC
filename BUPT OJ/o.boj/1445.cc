#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[20010],b[20010];

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int na,nb;

int find(int x)
{
	int l=0,r=nb-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(b[mid]<x) l=mid+1;
		else r=mid-1;
	}
	//printf("L:%d\n",l);
	return l;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long ans=0;
		scanf("%d%d",&na,&nb);
		for(int i=0;i<na;i++) scanf("%d",&a[i]);
		for(int i=0;i<nb;i++) scanf("%d",&b[i]);
		qsort(b,nb,sizeof(int),cmp);
		for(int i=0;i<na;i++) ans+=find(a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
