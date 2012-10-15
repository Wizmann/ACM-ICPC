//Result:2012-10-13 13:18:44	Accepted	3548	296MS	8344K	1427 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const double inf=1e9;

inline int mul(double x)
{
	return x*x;
}

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

double pntDis(const point&a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double dis[SIZE][SIZE];
int n;
point array[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	int cas=1;
	while(T--)
	{
		input(n);
		printf("Case %d: ",cas++);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			array[i]=point(a,b);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dis[i][j]=dis[j][i]=pntDis(array[i],array[j]);
			}
		}

		double ans=inf;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(dis[i][j]*2>=ans) continue;
				else
				{
					for(int k=j+1;k<n;k++) if(k!=i && k!=j)
					{
						int dx1=array[i].x-array[k].x;
						int dx2=array[i].x-array[j].x;
						int dy1=array[i].y-array[k].y;
						int dy2=array[i].y-array[j].y;

						if(dx1*dy2==dx2*dy1) continue;
						double tmp=dis[i][j]+dis[i][k]+dis[j][k];
						ans=min(ans,tmp);
					}
				}
			}
		}
		if(ans>=inf) puts("No Solution");
		else printf("%.3lf\n",ans);
	}
	return 0;
}

/*
Case 1: 11.4340
Case 2: 13.4179
Case 3: 13.9804
Case 4: 16.2801
Case 5: 13.1710
Case 6: 9.5215
Case 7: 11.4340
Case 8: 10.2426
Case 9: 14.5117
Case 10: 15.9303
*/

