//Result: Wizmann	3264	Accepted	6424K	1672MS	C++	 964B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define log2(x) (log(double(x))/log(2.0))

int maxi[50010][16];
int mini[50010][16];
int n,ask;

void init()
{
	int m=floor(log2((double)n));
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

int query(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return max(maxi[l][m],maxi[r-(1<<m)+1][m])-min(mini[l][m],mini[r-(1<<m)+1][m]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	scanf("%d%d",&n,&ask);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&maxi[i][0]);
		mini[i][0]=maxi[i][0];
	}
		
	init();
	while(ask--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
	}
	return 0;
}
	
