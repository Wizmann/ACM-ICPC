//Result:2012-08-18 16:06:15	Accepted	2491	203MS	1088K	989 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010

struct node
{
	int st,end;
	node(){}
	node(int ist,int iend)
	{
		st=ist;end=iend;
	}
	inline int getmid() const 
	{
		return (st+end+1)>>1;
	}
	inline int gettime() const
	{
		return (end-st+2)>>1;
	}
	friend bool operator < (const node& a,const node& b)
	{
		if(a.getmid()==b.getmid()) return a.st<b.st;
		else return a.getmid()<b.getmid();
	}
};

node wed[SIZE];
int n;

bool slove()
{
	int t=0;
	for(int i=0;i<n;i++)
	{
		t=max(t,wed[i].st);
		t+=wed[i].gettime();
		if(t>wed[i].end) return false;
	}
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			wed[i]=node(a,b);
		}
		sort(wed,wed+n);
		if(slove()) puts("YES");
		else puts("NO");
	}
	return 0;
}
