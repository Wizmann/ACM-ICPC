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
		

//Result:wizmann	2299	Accepted	6564K	438MS	G++	1118B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 500100
#define INF 1<<30

int baum[SIZE];

int lowbit(int x)
{
	return x & (-x);
}

void add(int pos,int val)
{
	while(pos<SIZE)
	{
		baum[pos]+=val;
		pos+=lowbit(pos);
	}
}

int sum(int pos)
{
	int res=0;
	while(pos>0)
	{
		res+=baum[pos];
		pos-=lowbit(pos);
	}
	return res;
}

int sum(int l,int r)
{
	return sum(r)-sum(l-1);
}

struct node
{
	int val,nr;
	
	friend bool operator < (const node &a,const node &b)
	{
		return a.val<b.val;
	}
};


node array[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(input(n) && n)
	{
		memset(baum,0,sizeof(baum));
		memset(array,0,sizeof(array));
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&(array[i].val));
			array[i].nr=i+1;
		}
		sort(array,array+n);
		for(int i=0;i<n;i++)
		{
			int pos=array[i].nr;
			ans+=sum(pos+1,n);
			add(pos,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
			
			
		



