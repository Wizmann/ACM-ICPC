#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long ans=0;
int sort[2000000];
int temp[2000000];

int *st;

inline void init()
{
	st=temp;
}

inline void push(int n)
{
	*st=n;
	st++;
}

void merge(int *array,int h,int mid,int l)
{
	init();
	int i=h,j=mid+1;
	while(i<=mid&&j<=l)
	{
		if(array[i]<=array[j])
		{
			push(array[i]);
			i++;
		}
		else
		{
			ans+=mid-i+1;
			push(array[j]);
			j++;
		}
	}
	while(i<=mid) push(array[i++]);
	while(j<=l) push(array[j++]);
	
	memcpy(array+h,temp,(st-temp)*sizeof(int));
}

inline void mergesort(int *array,int h,int l)
{
	if(h<l)
	{
		int mid=(h+l)/2;
		mergesort(array,h,mid);
		mergesort(array,mid+1,l);
		
		merge(array,h,mid,l);
	}
}




int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);	
	for(int i=0;i<n;i++) scanf("%d",&sort[i]); 
	
	mergesort(sort,0,n-1);
	
	printf("%lld\n",ans);
	return 0;
}
