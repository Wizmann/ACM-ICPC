//Result:wizmann	2452	Accepted	7140K	3250MS	G++	1493B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define log2(x) (log(double(x))/log(2.0))

int maxi[50010][16];
int mini[50010][16];
int num[50010];
int n;

inline int maxnum(int a,int b){return num[a]>num[b]?a:b;}
inline int minnum(int a,int b){return num[a]<num[b]?a:b;}

void init()
{
	int m=0,t=n;
	while(t){t>>=1;m++;}
	for(int i=1;i<=n;i++) maxi[i][0]=mini[i][0]=i;
	for(int i=1;i<=m;i++)
	{
		int l=n-(1<<i)+1;
		for(int j=1;j<=l;j++)
		{
			maxi[j][i]=maxnum(maxi[j][i-1],maxi[j+(1LL<<(i-1))][i-1]);
			mini[j][i]=minnum(mini[j][i-1],mini[j+(1<<(i-1))][i-1]);
		}
	}
}

int queryMaxi(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return maxnum(maxi[l][m],maxi[r-(1<<m)+1][m]);
}

int queryMini(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return minnum(mini[l][m],mini[r-(1<<m)+1][m]);
}

int find(int x,int l,int r)
{
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(num[x]<num[queryMini(x+1,mid)]) return find(x,mid+1,r);
	else return find(x,l,mid);
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		int ans=-1;
		memset(num,0,sizeof(num));
		memset(maxi,0,sizeof(maxi));
		memset(mini,0,sizeof(mini));
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);		
		init();
		for(int i=1;i<n;i++)
		{
			int j=find(i,i+1,n);
			int k=queryMaxi(i,j);
			//cout<<j<<" "<<k<<endl;
			ans=max(k-i,ans);
		}
		printf("%d\n",ans>0?ans:-1);
	}
	return 0;
}
