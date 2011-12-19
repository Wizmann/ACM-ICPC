#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

#define SIZE 80100

int maxi[SIZE][20];
int n;

void init()
{
	int m=floor(log2(n));
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			maxi[j][i]=maxi[j][i-1];
			if(j+(1<<(i-1))<=n) maxi[j][i]=max(maxi[j][i],maxi[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return max(maxi[l][m],maxi[r-(1<<m)+1][m]);
}

int findPos(int l,int r,int val)
{
	if(l==r)
	{
		if(maxi[l][0]<val) return l;
		else return 0;
	}
	else if(l<r)
	{
		int m=(l+r)>>1;
		if(query(l,m)>=val) return findPos(l,m-1,val);
		else
		{
			int res=findPos(m+1,r,val);
			if(res) return res;
			else return m;
		}
	}
	else return 0;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&maxi[i][0]);	
	init();
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=findPos(i+1,n,maxi[i][0]);
		//printf("%d\n",t);
		if(t) ans+=(t-i);
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	//printf("%.5lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
