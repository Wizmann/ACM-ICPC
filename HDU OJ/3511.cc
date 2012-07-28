//Result:2012-07-27 15:09:17	Accepted	3511	687MS	8964K	2667 B	G++	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010

const double eps=1e-8;
double xx;

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
	point p;
	double r;
	circle(){}
	circle(point ip,double ir)
	{
		p=ip;r=ir;
	}
};

circle array[SIZE];

struct mark
{
	point p;
	int id;
	bool io;

	mark(){}
	mark(point ip,int iid,bool iio)
	{
		p=ip;id=iid;io=iio;
	}
	
	mark getFriend()
	{
		mark res=(*this);
		res.io=!res.io;
		return res;
	}

	double y_axis() const
	{
		double a=sqrt(mul(array[id].r)-mul(xx-array[id].p.x));
		
		if(io) return p.y-a;
		else return p.y+a;
	}

	bool operator < (const mark &b) const
	{
		double y1=y_axis();
		double y2=b.y_axis();
		//print(y1<<' '<<y2);
		if(zero(y1-y2)) return y1<y2;
		else if(id!=b.id) return id<b.id;
		return io>b.io;
	}
};

mark markio[SIZE<<1];
int cnt,n;
int dp[SIZE];


bool cmp(const mark& a,const mark& b)
{
	return a.p.x<b.p.x;
}

void slove()
{
	set<mark> st;
	set<mark>::iterator now,next,pre;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<cnt;i++)
	{
		if(!markio[i].io)
		{
			mark tmp=markio[i];
			st.erase(tmp);
			tmp=tmp.getFriend();
			st.erase(tmp);
		}
		else
		{
			xx=markio[i].p.x;
			mark tmp=markio[i];
			st.insert(tmp);
			
			/*
			for(set<mark>::iterator iter=st.begin();iter!=st.end();iter++)
			{
				printf("%.2lf %.2lf -> %d  -> %2.lf\n",iter->p.x,iter->p.y,iter->id,iter->y_axis());
			}
			puts("");
			*/
			
			next=pre=now=st.find(tmp);
			next++;
			if(pre==st.begin() or next==st.end()) dp[tmp.id]=1;
			else
			{
				pre--;
				int id1=pre->id,id2=next->id;
				if(id1==id2) dp[tmp.id]=dp[id1]+1;
				else dp[tmp.id]=max(dp[id1],dp[id2]);
			}
			tmp=tmp.getFriend();
			st.insert(tmp);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b,c;
	while(input(n))
	{
		cnt=0;
		memset(markio,0,sizeof(markio));
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a,&b,&c);
			array[i]=circle(point(a,b),c);
			markio[cnt++]=mark(point(a-c,b),i,1);
			markio[cnt++]=mark(point(a+c,b),i,0);
		}
		sort(markio,markio+cnt,cmp);
		slove();
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans=max(dp[i],ans);
		}
		print(ans);
	}
	return 0;
}
