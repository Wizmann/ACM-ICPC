#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 500000

int array[N];
int temp[N];

int *st;
long long ans;

inline void init()
{
	st=temp;
}

inline void push(int n)
{
	*st=n;
	st++;
}

inline void merge(int *sort,int l,int mid,int h)
{
	init();
	int i=l,j=mid+1;
	
	while(i<=mid&&j<=h)
	{
		if(sort[i]<=sort[j])
		{
			push(sort[i]);
			i++;
		}
		else
		{
			ans+=mid-i+1;
			push(sort[j]);
			j++;
		}
	}
	
	while(i<=mid) push(sort[i++]);
	while(j<=h) push(sort[j++]);
	
	memcpy(array+l,temp,sizeof(int)*(st-temp));
}

void mergesort(int *sort,int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		mergesort(sort,l,mid);
		mergesort(sort,mid+1,h);
		
		merge(sort,l,mid,h);
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n)
	{
		ans=0;
		for(int i=0;i<n;i++) scanf("%d",&array[i]);
		
		mergesort(array,0,n-1);
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
		


