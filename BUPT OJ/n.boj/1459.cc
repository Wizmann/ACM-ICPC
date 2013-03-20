//Result:1459	Accepted	1755ms	17684kb	G++	1480B	2013-03-12 17:59:58	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const int INF = 1<<28;

struct point
{
	int x,y;
	
	point(){}
	point(int ix,int iy):x(ix),y(iy){}

	friend bool operator < (const point& a,const point& b)
	{
		return a.x+a.y<b.x+b.y;
	}
};

point array[SIZE*SIZE];
int n;
char visit[SIZE*SIZE];

bool conflict(const point& father,const point& son)
{
	if( (father.x>=son.x && father.y>=son.y) ||
		(father.x<=son.x && father.y<=son.y) ) return false;
	else return true;
}

void slove()
{
	vector<point> ans;
	for(int i=n*n;i>=0;i--)
	{
		if(visit[i]) continue;
		else
		{
			ans.push_back(array[i]);
			for(int j=i-1;j>=0;j--)
			{
				if(conflict(array[i],array[j])) visit[j]=1;
			}
		}
		if(int(ans.size())==2*n-1) break;
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<(int)ans.size();i++)
	{
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
}

int main()
{
	int T,x;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&x);
				array[x]=point(i,j);
			}
		}
		slove();
	}
	return 0;
}
