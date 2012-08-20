//Result:wizmann	1228	Accepted	268K	79MS	C++	2943B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const double inf=1e100;
const double eps=1e-8;

inline int zero(double x)
{
    if(x<-eps) return -1;
    else if(fabs(x)<eps) return 0;
    else return 1;
}

struct point
{
	double x,y;
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
	friend bool operator == (const point& pa,const point& pb)
	{
		return (!zero(pa.x-pb.x)) && (!zero(pa.y-pb.y));
	}
};

struct line
{
	double a,b,c;
	line(){}
	line(double i_a,double i_b,double i_c)
	{
		a=i_a;b=i_b;c=i_c;
	}
};

double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double pointDis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

line makeline(point p1,point p2)
{
	line res;
	int sig=1;
	res.a=p2.y-p1.y;
	if(zero(res.a)<0)
	{
		sig=-1;
		res.a=sig*res.a;
	}
	res.b=sig*(p1.x-p2.x);
	res.c=sig*(p1.y*p2.x-p2.y*p1.x);
	return res;
}

struct cmp
{
    point p;
    cmp(const point &i_p)
    {
        p=i_p;
    }
    bool operator()(const point &a,const point &b)
	{
		if(zero(xmult(a,b,p))==0)	return pointDis(a,p)<pointDis(b,p);
		return zero(xmult(a,b,p))>0;
	}
};


int n;
point polygen[SIZE];

int findtop()
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(polygen[i].y<polygen[res].y) res=i;
		else if(polygen[i].y==polygen[res].y && polygen[i].x<polygen[res].x) res=i;
	}
	return res;
}

bool slove()
{
	bitset<SIZE> visit;
	int edge=0;
	visit.reset();
	for(int i=0;i<n;i++) if(!visit[i])
	{
		bitset<SIZE> inque;
		int now=i;
		line l=makeline(polygen[now],polygen[(now+1)%n]);
		deque<int> dq;
		dq.push_back(now);
		int ptr=now+1;
		while(1)
		{
			if(!inque[ptr] && zero(l.a*polygen[ptr].x+l.b*polygen[ptr].y+l.c)==0)
			{
				inque[ptr]=1;
				dq.push_back(ptr);
				ptr=(ptr+1)%n;
			}
			else break;
		}
		ptr=(now-1+n)%n;
		while(1)
		{
			if(!inque[ptr] && zero(l.a*polygen[ptr].x+l.b*polygen[ptr].y+l.c)==0)
			{
				inque[ptr]=1;
				dq.push_front(ptr);
				ptr=(ptr-1+n)%n;
			}
			else break;
		}
		//print(dq.size());
		if(dq.size()<3) return false;
		else
		{
			edge++;
			dq.pop_front();
			dq.pop_back();
			for(int j=0;j<(int)dq.size();j++) visit[dq[j]]=1;
		}
	}
	return edge>=3;
}
		
		

int main()
{
	freopen("a.txt","r",stdin);
	int T;
	double a,b;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			polygen[i]=point(a,b);
		}
		int ptr=findtop();
		swap(polygen[0],polygen[ptr]);
		for(int i=1;i<n;i++)
		{
			sort(polygen+i,polygen+n,cmp(polygen[i-1]));
		}
		if(slove()) print("YES");
		else print("NO");
	}
	return 0;
}
	
