//Result:2012-07-26 19:33:59	Accepted	4311	156MS	3676K	1266 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define INF 1LL<<60

typedef long long llint;

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

int xs[SIZE+5],ys[SIZE+5];
llint sumx[SIZE+5],sumy[SIZE+5];
int n;
point array[SIZE+5];

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		input(n);
		memset(sumx,0,sizeof(sumx));
		memset(sumy,0,sizeof(sumy));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			array[i]=point(a,b);
			xs[i]=a;ys[i]=b;
		}
		sort(xs,xs+n);
		sort(ys,ys+n);

		for(int i=0;i<n;i++)
		{
			if(i)
			{
				sumx[i]+=sumx[i-1];
				sumy[i]+=sumy[i-1];
			}
			sumx[i]+=xs[i];
			sumy[i]+=ys[i];
		}
		llint ans=INF;
		for(int i=0;i<n;i++)
		{
			llint res=0;
			int x=array[i].x;
			int y=array[i].y;

			llint p=upper_bound(xs,xs+n,x)-xs-1;
			res+=(p+1)*x-sumx[p];
			res+=(sumx[n-1]-sumx[p])-x*(n-p-1);

			p=upper_bound(ys,ys+n,y)-ys-1;
			res+=(p+1)*y-sumy[p];
			res+=(sumy[n-1]-sumy[p])-y*(n-p-1);

			ans=min(ans,res);
		}
		print(ans);
	}
	return 0;
}

