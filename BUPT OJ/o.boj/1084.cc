//Result:1084	Accepted	424MS	7676K	G++	 2007B	2012-09-13 21:45:05	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50009
#define N 50010

struct _link
{
	int val,next;
	_link(){}
	_link(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

_link hash[SIZE+5];
int head[SIZE+5];
int array[SIZE+5];
int n,ind;
int maxi[N][16],mini[N][16];

void initRMQ()
{
	int m=floor(log2(double(n)));
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			maxi[j][i]=maxi[j][i-1];
			if(j+(1<<(i-1))<=n) maxi[j][i]=max(maxi[j][i],maxi[j+(1<<(i-1))][i-1]);
			mini[j][i]=mini[j][i-1];
			if(j+(1<<(i-1))<=n) mini[j][i]=min(mini[j][i],mini[j+(1<<(i-1))][i-1]);
		}
	}
}

int query_max(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return max(maxi[l][m],maxi[r-(1<<m)+1][m]);
}

int query_min(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return min(mini[l][m],mini[r-(1<<m)+1][m]);
}

int getHash(int x)
{
	return (x%SIZE+SIZE)%SIZE;
}

void addHash(int x,int val)
{
	int now=getHash(x);
	hash[ind]=_link(val,head[now]);
	head[now]=ind++;
}

pair<int,int> memo[N];

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	int sum=0;
	ind=0;
	scanf("%d",&n);
	int ans=0;
	memset(head,-1,sizeof(head));
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==0) a=-1;
		memo[i]=make_pair(b,a);
	}
	sort(memo,memo+n);
	for(int i=0;i<n;i++)
	{
		a=memo[i].second;
		b=memo[i].first;
		array[i]=a;
		mini[i][0]=maxi[i][0]=b;
	}
	initRMQ();
	for(int i=0;i<n;i++)
	{
		sum+=array[i];
		if(sum==0)
		{
			int minix=query_min(0,i);
			int maxix=query_max(0,i);

			ans=max(abs(maxix-minix),ans);
		}
		int now=getHash(sum);
		for(int j=head[now];j!=-1;j=hash[j].next)
		{
			int minix=query_min(hash[j].val+1,i);
			int maxix=query_max(hash[j].val+1,i);

			ans=max(ans,abs(minix-maxix));
		}
		addHash(sum,i);
	}

	print(ans);
	return 0;
}

	
