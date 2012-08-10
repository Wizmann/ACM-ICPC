//Result:5815	Pair of Touching Circles	Accepted	C++	2.072	2012-08-05 13:32:11
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000


const double eps=1e-7;

inline int mul(int x)
{
	return x*x;
}

typedef long long llint;

struct node
{
	int x,y;
	node(){}
	node(int ix,int iy){x=ix;y=iy;}
};

llint slove(int a,int b,int x,int y)
{
	int ta=(x-a+1);
	int tb=(y-b+1);
	if(ta<0 or tb<0) return 0;
	else return (llint)ta*tb;
}

vector<node> g[1500];

void init()
{
	for(int i=1;i<SIZE;i++)
	{
		for(int j=i;j<SIZE;j++)
		{
			int k=mul(i)+mul(j);
			int t=sqrt(k);
			if(k==mul(t))
			{
				g[t].push_back(node(i,j));
				
			}
		}
	}
}

int main()
{
	int T,x,y;
	input(T);
	init();
	int cas=1;
	while(T--)
	{
		printf("Case %d: ",cas++);
		llint ans=0;
		scanf("%d%d",&x,&y);
		int r=max(x,y)/2+1;

		for(int i=1;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				int a=(i+j)*2;
				int b=max(i,j)*2;
				llint t=slove(a,b,x,y)+slove(a,b,y,x);
				if(i!=j) t*=2;
				ans+=t;
			}
		}
		for(int i=1;i<1500;i++)
		{
			for(int j=0;j<(int)g[i].size();j++)
			{
				int a=g[i][j].x+i;
				int b=g[i][j].y+i;
				for(int k=1;k<i;k++)
				{
					int l=max(a,2*max(k,i-k));
					int c=max(b,2*max(k,i-k));
					ans+=(slove(l,c,x,y)+slove(l,c,y,x))*2;
				}
			}
		}
		print(ans);
	}
	return 0;
}
