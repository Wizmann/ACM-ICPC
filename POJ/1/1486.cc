//Result:wizmann	1486	Accepted	752K	0MS	G++	2299B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32

int n;

struct Cpoint
{
	int x,y;
	Cpoint(){}
	Cpoint(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

struct Cslide
{
	int xmin,xmax;
	int ymin,ymax;
	Cslide(){}
	Cslide(int ixmin,int ixmax,int iymin,int iymax)
	{
		xmin=ixmin;xmax=ixmax;
		ymin=iymin;ymax=iymax;
	}
	
	bool inSlide(const Cpoint &p)
	{
		if(p.x>=xmin && p.x<=xmax &&
			p.y>=ymin && p.y<=ymax) return true;
		else return false;
	}
};

Cslide slide[SIZE];
int g[SIZE][SIZE];
char visit[SIZE];
int pre[SIZE];
pair<int,int> edge[SIZE];

bool deal(int x)
{
	for(int i=0;i<n;i++) if(g[x][i])
	{
		if(!visit[i])
		{
			visit[i]=1;
			if(pre[i]==-1 || deal(pre[i]))
			{
				pre[i]=x;
				return true;
			}
		}
	}
	return false;
}
				
			

int hungary()
{
	int sum=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(deal(i)) sum++;
	}
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,d;
	int cas=1;
	while(input(n) && n)
	{
		printf("Heap %d\n",cas++);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			slide[i]=Cslide(a,b,c,d);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			for(int j=0;j<n;j++)
			{
				if(slide[j].inSlide(Cpoint(a,b)))
				{
					g[j][i]=1;
				}
			}
		}
		int ind=0;
		int sum=hungary();
		//print(sum);
		for(int i=0;i<n;i++)
		{
			if(pre[i]!=-1)
			{
				edge[ind++]=make_pair(i,pre[i]);
			}
		}
		ind=0;
		pair<int,int> ans[SIZE];
		for(int i=0;i<sum;i++)
		{
			g[edge[i].second][edge[i].first]=0;
			int t=hungary();
			if(t!=sum)
			{
				//print(edge[i].second<<' '<<edge[i].first);
				ans[ind++]=make_pair(edge[i].second,edge[i].first);
			}
			g[edge[i].second][edge[i].first]=1;
		}
		if(ind==0) puts("none");
		else
		{
			sort(ans,ans+ind);
			for(int i=0;i<ind;i++)
			{
				if(i) printf(" ");
				printf("(%c,%d)",'A'+ans[i].first,ans[i].second+1);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}





