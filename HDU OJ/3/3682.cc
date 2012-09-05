//Result:2012-09-05 13:05:49	Accepted	3682	31MS	372K	2112 B	C++	Wizmann
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
#define SIZE 1024

struct point
{
	int x,y,z;
	point(){x=y=z=-1;}
	point(int ix,int iy,int iz)
	{
		x=ix;y=iy;z=iz;
	}
	friend bool operator < (const point &a,const point &b)
	{
		if(a.x!=b.x) return a.x<b.x;
		else if(a.y!=b.y) return a.y<b.y;
		else return a.z<b.z;
	}
};


set<point> st;
int n,m;
map<point,int> value;

point array[SIZE];


void setValue(char v,int val,point &p)
{
	if(v=='X') p.x=val;
	else if(v=='Y') p.y=val;
	else if(v=='Z') p.z=val;
	else print("ERROR");//TEST BUG!!!!
}

bool getCross(int a,int b,point &p)
{
	int av[3]={array[a].x,array[a].y,array[a].z};
	int bv[3]={array[b].x,array[b].y,array[b].z};
	int cv[3]={0};
	
	for(int i=0;i<3;i++)
	{
		if(av[i]==bv[i] && av[i]==-1) return false;
	}
	
	bool flag=false;
	for(int i=0;i<3;i++)
	{
		if(av[i]==bv[i]) flag=true;
		if(av[i]!=-1) cv[i]=av[i];
		else cv[i]=bv[i];
	}
	if(!flag) return false;
	else
	{
		p.x=cv[0];p.y=cv[1];p.z=cv[2];
		return true;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	char cmd[512];
	char a[10],b[10];
	int av,bv;
	while(T--)
	{
		int ind=0;
		int ans=0;
		input(n>>m);
		st.clear();
		value.clear();
		for(int i=0;i<m;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++)
			{
				if(cmd[j]==',' || cmd[j]=='=') cmd[j]=' ';
			}
			sscanf(cmd,"%s%d%s%d",a,&av,b,&bv);
			point p;
			setValue(*a,av,p);
			setValue(*b,bv,p);
			if(st.find(p)==st.end())
			{
				st.insert(p);
				array[ind++]=p;
			}
		}
		st.clear();
		for(int i=0;i<ind;i++)
		{
			for(int j=i+1;j<ind;j++)
			{
				point p;
				if(getCross(i,j,p))
				{
					value[p]++;
				}
			}
		}
		for(map<point,int>::iterator iter=value.begin();iter!=value.end();iter++)
		{
			if(iter->second==3) ans+=2;
			else if(iter->second==1) ans+=1;
			else exit(-1);
		}
		print(n*ind-ans);
	}
	return 0;
}
