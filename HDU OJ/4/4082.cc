//Result:2012-09-14 15:20:30	Accepted	4082	0MS	588K	2544 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE=(18*18*18+1234);
const double inf=1e100;
const double eps=1e-8;

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

inline int mul(int x)
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


struct triangle
{
	int edge[3];
	triangle(){}
	triangle(int a1,int a2,int a3)
	{
		edge[0]=a1;
		edge[1]=a2;
		edge[2]=a3;
	}
	void make_sort()
	{
		sort(edge,edge+3);
	}
};

point array[22];
triangle tri[SIZE];


int pntDis(const point& a,const point& b)
{
	return mul(a.x-b.x)+mul(a.y-b.y);
}

bool simi(int a,int b)
{
	double t1=(double)tri[a].edge[0]/tri[b].edge[0];
	double t2=(double)tri[a].edge[1]/tri[b].edge[1];
	double t3=(double)tri[a].edge[2]/tri[b].edge[2];

	if(zero(t1-t2)==0 && zero(t2-t3)==0 && zero(t1-t3)==0) return 1;
	else return 0;
}



int father[SIZE];
int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}



int main()
{
	freopen("input.txt","r",stdin);
	int n,a,b;
	while(input(n) && n)
	{
		int sz=0;
		set<pair<int,int> > judge;
		int ind=0;
		for(int i=0;i<SIZE;i++) father[i]=i;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(judge.find(make_pair(a,b))==judge.end())
			{
				array[sz++]=point(a,b);
				judge.insert(make_pair(a,b));
			}
			else continue;
		}
		for(int i=0;i<sz;i++)
		{
			for(int j=i+1;j<sz;j++)
			{
				for(int k=j+1;k<sz;k++)
				{
					int len1=pntDis(array[i],array[j]);
					int len2=pntDis(array[i],array[k]);
					int len3=pntDis(array[j],array[k]);
					if(zero(sqrt(len1)+sqrt(len2)-sqrt(len3))<=0 || 
						zero(sqrt(len1)+sqrt(len3)-sqrt(len2))<=0 || 
						zero(sqrt(len2)+sqrt(len3)-sqrt(len1))<=0) continue;
					tri[ind]=triangle(len1,len2,len3);
					tri[ind].make_sort();
					ind++;
				}
			}
		}

		for(int i=0;i<ind;i++)
		{
			for(int j=i+1;j<ind;j++)
			{
				if(simi(i,j)) father[findfather(j)]=findfather(i);
			}
		}
		
		map<int,int> mp;
		for(int i=0;i<ind;i++)
		{
			mp[findfather(i)]++;
		}

		int ans=0;
		for(map<int,int>::iterator iter=mp.begin();iter!=mp.end();iter++)
		{
			ans=max(ans,iter->second);
		}
		print(ans);
	}
	return 0;
}
