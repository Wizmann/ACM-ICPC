//Result:wizmann	3034	Accepted	800K	625MS	G++	2530B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define mul(x) ((x)*(x))
#define elif else if

typedef struct node
{
	int x,y,w;
	
	inline void setnode(int a,int b,int c)
	{
		x=a;y=b;w=c;
	}
}node;

node step[128];

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;
	return ta->w-tb->w;
}

int n,d,m,sz,ex;
char g[16][32][32];
int dp[16][32][32];

void init()
{
	//预处理5步内所有可能的走法（d<=5）
	sz=0;
	for(int x=-5;x<=5;x++)
	{
		for(int y=-5;y<=5;y ++)
		{
			if(mul(x)+mul(y)<=25)
			{
				step[sz].x=x;
				step[sz].y=y;
				step[sz].w=ceil(sqrt(double(mul(x)+mul(y))));
				sz++;
            }
		}
	}
	qsort(step,sz,sizeof(node),cmp);
}

int getSum(int t, int x, int y, int xx, int yy, int dx, int dy)
{
	int sum = 0;
	do{
		x += dx;
		y += dy;
		sum += g[t][x][y];
	}while(!(x == xx && y == yy));
	return sum;
}

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}


int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	init();
	while(input(n>>d>>m))
	{
		int T=-1;
		memset(g,0,sizeof(g));
		memset(dp,0,sizeof(dp));
		if(n+d+m==0) break;
		for(int i=0;i<m;i++)
		{
			input(a>>b>>c);
			g[c][a+d][b+d]=1;
			//因为把地图的范围开到了n+2*d,也就是从n-d到n+d
			//所以把所有的点加了一个d
			T=max(T,c);
		}
		T++;
		
		ex=n+2*d;
		int sum;
		for(int i=1;i<T;i++)
		{
			for(int x=0;x<=ex;x++)
			{
				for(int y=0;y<=ex;y++)
				{
					for(int j=0;j<sz;j++)
					{
						if(step[j].w>d) break;
						int dx=step[j].x;
						int dy=step[j].y;
						int xx=x+dx,yy=y+dy;
                        if(j==0) sum=g[i][x][y];
                        else
                        {
							int tmp=gcd(abs(dx),abs(dy));
							dx=dx/tmp;
							dy=dy/tmp;
							//算出移动的单位向量，神GCD
							sum=g[i][x][y]+getSum(i,x,y,xx,yy,dx,dy);
							//把一条线上所有经过的点全部包括在内
						}
						dp[i+1][xx][yy]=max(dp[i+1][xx][yy],dp[i][x][y]+sum);
					}
				}
			}
		}
		int ans = 0;
		for(int x=d;x<n+d;x++)
		{
			for(int y=d;y<n+d;y++) ans=max(ans,dp[T][x][y]);
		}
        printf("%d\n", ans);
	}
	return 0;
}
			
