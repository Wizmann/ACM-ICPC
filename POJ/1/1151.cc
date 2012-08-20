//Result:wizmann	1151	Accepted	832K	0MS	G++	3310B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

struct node
{
	int st,end;
	double len;
	int cov;

	node(){}
	node(int ist,int iend,double ilen)
	{
		cov=0;
		st=ist;end=iend;
		len=ilen;
	}
	
	bool equal(int a,int b)
	{
		return st==a && end==b;
	}
	
	int getmid()
	{
		return (st+end)>>1;
	}
	
	bool endnode()
	{
		return end-st<=1;
	}
};

struct point
{
	double x,y;
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

struct segment
{
	point p1,p2;

	segment(){}
	segment(const point& a,const point& b)
	{
		p1=a;p2=b;
	}
};

struct line
{
	double y;
	int x1,x2;
	int flag;
	line(){}
	line(int ix1,int ix2,double iy,int iflag)
	{
		x1=ix1;x2=ix2;
		y=iy;flag=iflag;
	}
	friend bool operator < (const line& a,const line& b)
	{
		return a.y<b.y;
	}
};

const int ROOT=0;


node stree[SIZE<<2];
int n;
map<double,int> hash;
map<int,double> anti_hash;
int sz,ind;
line edge[SIZE<<1];


inline int left(int x)
{
	return (x<<1)+1;
}
inline int right(int x)
{
	return left(x)+1;
}

void stree_init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r,anti_hash[r+1]-anti_hash[l]);
	if(l<r)
	{
		int mid=(l+r)>>1;
		stree_init(l,mid,left(pos));
		stree_init(mid+1,r,right(pos));
	}
}

void update(int l,int r,int cov,int pos=ROOT)
{
	if(stree[pos].equal(l,r))
	{
		stree[pos].cov+=cov;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(r<=mid) update(l,r,cov,left(pos));
		else if(l>mid) update(l,r,cov,right(pos));
		else
		{
			update(l,mid,cov,left(pos));
			update(mid+1,r,cov,right(pos));
		}
	}
}

double query(int pos=ROOT)
{
	double res=0;
	if(stree[pos].cov>0) res+=stree[pos].len;
	else if(stree[pos].st!=stree[pos].end)
	{
		res+=query(left(pos));
		res+=query(right(pos));
	}
	return res;
}

int main()
{
	double bx,by,ex,ey;
	int cas=1;
	while(input(n) && n)
	{
		hash.clear();
		anti_hash.clear();
		vector<double> itemx;
		vector<segment> seg;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&bx,&by,&ex,&ey);
			itemx.push_back(bx);
			itemx.push_back(ex);
			seg.push_back(segment(point(bx,by),point(ex,by)));
			seg.push_back(segment(point(bx,ey),point(ex,ey)));
		}
		sort(itemx.begin(),itemx.end());
		sz=itemx.size();
		ind=0;
		double ans=0;
		for(int i=0;i<sz;i++)
		{
			if(hash.find(itemx[i])==hash.end())
			{
				//print(itemx[i]<<' '<<ind);
				hash[itemx[i]]=ind;
				anti_hash[ind]=itemx[i];
				ind++;
			}
		}
		sz=seg.size();
		for(int i=0;i<(int)seg.size();i+=2)
		{
			edge[i]=line(hash[seg[i].p1.x],hash[seg[i].p2.x]-1,seg[i].p1.y,1);
			edge[i+1]=line(hash[seg[i+1].p1.x],hash[seg[i+1].p2.x]-1,seg[i+1].p1.y,-1);
		}
		sort(edge,edge+sz);
		stree_init(0,ind-1);
		update(edge[0].x1,edge[0].x2,edge[0].flag);
		for(int i=1;i<sz;i++)
		{
			ans+=fabs(edge[i-1].y-edge[i].y)*query();
			update(edge[i].x1,edge[i].x2,edge[i].flag);
		}
		printf("Test case #%d\n",cas++);
		printf("Total explored area: %.2f\n\n",ans); 
	}
	return 0;
}

