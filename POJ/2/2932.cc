//Result:wizmann	2932	Accepted	7568K	3657MS	C++	2870B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 40010

const double eps=1e-8;
double xx;

struct point 
{
    double x,y;
    point(){}
    point(double ix,double iy)
    {
        x=ix;y=iy;
    }
};

struct circle
{
    point c;
    double r;
    circle(){}
    circle(point ip,double ir)
    {
        c=ip;r=ir;
    }
};

circle array[SIZE];


inline double mul(double x)
{
	return x*x;
}

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}




struct node
{
	int id;
	bool io;
	double x;

	node(){}
	node(int iid,bool iio,double ix)
	{
		id=iid;io=iio;
		x=ix;
	}
	
	double getY() const
	{
		double dis=sqrt(mul(array[id].r)-mul(xx-array[id].c.x));
		
		if(io) return array[id].c.y-dis;
		else return array[id].c.y+dis;
	}

	node getFriend()
	{
		node res=(*this);
		res.io=!res.io;
		return res;
	}

	bool operator < (const node& b) const
	{
		double ay=getY();
		double by=b.getY();
		//cout<<ay<<' '<<by<<endl;
		if(zero(ay-by)!=0) return ay<by;
		else if(id!=b.id) return id<b.id;
		else return io>b.io;
		
	}
};

node sweap[SIZE<<1];
int dp[SIZE];
int cnt;
int n;



bool cmp(const node& a,const node& b)
{
	return a.x<b.x;
}

void slove()
{
	memset(dp,0,sizeof(dp));
	set<node> st;
	set<node>::iterator pre,now,next;
	node tmp;
	for(int i=0;i<cnt;i++)
	{
		tmp=sweap[i];
		if(!sweap[i].io)
		{
			st.erase(tmp);
			st.erase(tmp.getFriend());
		}
		else
		{
			xx=tmp.x;
			st.insert(tmp);
			
			/*
			for(set<node>::iterator iter=st.begin();iter!=st.end();iter++)
			{
				printf("%.2lf  -> %d  %s\n",iter->getY(),iter->id,(iter->io?"true":"false"));
			}
			puts("");			
			*/
			
			pre=now=next=st.find(tmp);
			next++;
			if(pre==st.begin() or next==st.end())
			{
				dp[tmp.id]=1;
			}
			else
			{
				pre--;
				int id1=pre->id,id2=next->id;
				if(id1==id2) dp[tmp.id]=dp[id1]+1;
				else dp[tmp.id]=max(dp[id1],dp[id2]);
			}
			st.insert(tmp.getFriend());
		}
	}
}

int ans[SIZE];


int main()
{
	freopen("input.txt","r",stdin);
	double a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&c,&b,&a);
			array[i]=circle(point(a,b),c);
			sweap[cnt++]=node(i,1,a-c);
			sweap[cnt++]=node(i,0,a+c);
		}
		sort(sweap,sweap+cnt,cmp);
		slove();
		int sz=0;
		for(int i=0;i<n;i++)
		{
			if(dp[i]==1)
			{
				ans[sz++]=i;
			}
		}
		sort(ans,ans+sz);
		printf("%d\n",sz);
		for(int i=0;i<sz;i++)
		{
			if(i) printf(" ");
			printf("%d",ans[i]+1);
		}
		puts("");
	}
	return 0;
}

