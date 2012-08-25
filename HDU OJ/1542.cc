//Result:2012-08-20 20:49:47	Accepted	1542	15MS	604K	3411 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 1<<30

inline int left(int x){return (x<<1)+1;}
inline int right(int x){return (x<<1)+2;}

struct node
{
	int l,r;
	int val;

	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
		val=0;
	}
	inline int getmid(){return (l+r)>>1;}
	inline int equal(int il,int ir){return l==il && r==ir;}
	inline bool has_next(){return l!=r;}
};

struct line
{
	double x;
	double l,r;
	bool inout;

	line(){}
	line(double il,double ir,double ix,int io)
	{
		l=il;r=ir;inout=io;x=ix;
	}
	friend bool operator < (const line& a,const line& b)
	{
		if(a.x==b.x) return b.inout;
		else return a.x<b.x;
	}
};

node stree[SIZE<<2];
map<double,int> hash;
int n,ind,sz;
line sweap[SIZE<<1];

const int ROOT=0;
map<int,double> anti_hash;

void stree_init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r);
	if(l<r)
	{
		int mid=(l+r)>>1;
		stree_init(l,mid,left(pos));
		stree_init(mid+1,r,right(pos));
	}
}

double stree_query(int l,int r,int pos=ROOT)
{
	if(stree[pos].equal(l,r) && stree[pos].val!=-1)
	{
		//print(anti_hash[r]<<' '<<anti_hash[l]);
		return (double)(anti_hash[r+1]-anti_hash[l])*(stree[pos].val==0?0:1);
	}
	else if(stree[pos].has_next())
	{
		int mid=stree[pos].getmid();
		if(r<=mid) return stree_query(l,r,left(pos));
		else if(l>mid) return stree_query(l,r,right(pos));
		else
		{
			return stree_query(l,mid,left(pos))+stree_query(mid+1,r,right(pos));
		}
	}
	else return 0;
}

void stree_insert(int l,int r,bool inout,int pos=ROOT)
{
	if(stree[pos].equal(l,r) && stree[pos].val!=-1)
	{
		if(inout) stree[pos].val+=1;
		else stree[pos].val-=1;
	}
	else
	{
		if(stree[pos].val!=-1)
		{
			stree[left(pos)].val=stree[pos].val;
			stree[right(pos)].val=stree[pos].val;
			stree[pos].val=-1;
		}
		int mid=stree[pos].getmid();
		if(r<=mid) stree_insert(l,r,inout,left(pos));
		else if(l>mid) stree_insert(l,r,inout,right(pos));
		else
		{
			stree_insert(l,mid,inout,left(pos));
			stree_insert(mid+1,r,inout,right(pos));
		}
	}
}

double slove()
{
	double ans=0;
	double last=-INF;
	for(int i=0;i<(n<<1);i++)
	{
		double val=0;
		int l=hash[sweap[i].l];
		int r=hash[sweap[i].r];
		if(last!=-INF)
		{
			val=sweap[i].x-last;
			//print(">>"<<val<<' '<<stree_query(0,sz));
			ans+=val*stree_query(0,sz);
		}
		last=sweap[i].x;
		stree_insert(l,r-1,sweap[i].inout);
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b,c,d;
	double val[SIZE<<1];
	int cas=1;
	while(input(n) && n)
	{
		printf("Test case #%d\nTotal explored area: ",cas++);
		memset(sweap,0,sizeof(sweap));
		ind=sz=0;
		memset(val,0,sizeof(val));
		hash.clear();
		anti_hash.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			sweap[i<<1]=line(b,d,a,1);
			sweap[(i<<1)+1]=line(b,d,c,0);
			val[ind++]=d;
			val[ind++]=b;
		}
		sort(val,val+ind);
		sort(sweap,sweap+(n<<1));
		for(int i=0;i<ind;i++)
		{
			if(val[i]!=val[i+1])
			{
				hash[val[i]]=sz;
				//print(val[i]<<":"<<sz);
				anti_hash[sz]=val[i];
				sz++;
			}
		}
		stree_init(0,sz);
		printf("%.2lf\n",slove());
		puts("");
	}
	return 0;
}



