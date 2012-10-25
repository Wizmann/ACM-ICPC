//Result:2012-10-17 11:34:09 	Accepted 	3659 	C++ 	1140 	7188 	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256000

typedef long long llint;

struct edge
{
	int st,end,cost;
	edge(){}
	edge(int ist,int iend,int icost)
	{
		st=ist;end=iend;cost=icost;
	}
	friend bool operator < (const edge& a,const edge& b)
	{
		return a.cost<b.cost;
	}
};

int father[SIZE];
edge array[SIZE];
int num[SIZE];
llint sum[SIZE];
int n;

int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}

void init()
{
	for(int i=0;i<SIZE;i++)
	{
		father[i]=i;
		num[i]=1;
	}
	memset(sum,0,sizeof(sum));
}

llint slove()
{
	llint ans=-1;
	for(int i=n-2;i>=0;i--)
	{
		int a=array[i].st;
		int b=array[i].end;
		llint cost=array[i].cost;

		a=findfather(a);
		b=findfather(b);

		llint a2b=num[a]*cost+sum[b];
		llint b2a=num[b]*cost+sum[a];

		if(a2b>b2a)
		{
			father[a]=b;
			num[b]+=num[a];
			sum[b]=a2b;
			ans=max(ans,a2b);
		}
		else
		{
			father[b]=a;
			num[a]+=num[b];
			sum[a]=b2a;
			ans=max(ans,b2a);
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(input(n))
	{
		init();
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			array[i]=edge(a,b,c);
		}
		sort(array,array+n-1);
		print(slove());
	}
	return 0;
}

