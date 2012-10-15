//Result:Wizmann	SGU 523	Accepted	891 KB	31 ms	Visual Studio 8 C++	1204 B	2012-10-05 18:30:12	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

struct press
{
	int fl,pos;
	press(){}
	press(int ifl,int ipos)
	{
			fl=ifl;pos=ipos;
	}
	friend bool operator < (const press &a,const press &b)
    {
        return a.pos>b.pos;
    }
};

int n,f;
priority_queue<press> pq;
char ok[SIZE];
bool first;

void slove()
{
	int now=f;
	while(!pq.empty())
	{
		int next=pq.top().fl;
		pq.pop();
		while(!ok[next] && !pq.empty())
		{
			next=pq.top().fl;
			pq.pop();
		}
		if(!ok[next] && pq.empty()) break;

		int add=1;
		if(next<now) add=-1;
		while(1)
		{
			if(ok[now])
			{
				ok[now]=0;
				if(first) first=false;
				else printf(" ");
				printf("%d",now);
			}
			if(now==next) break;
			else now+=add;
		}
	}
}

int main()
{
	int a;
	while(input(n>>f))
	{
	    first=true;
		pq=priority_queue<press>();
		memset(ok,0,sizeof(ok));

		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			ok[a]=1;
			pq.push(press(a,i));
		}
		slove();
		puts("");
	}
	return 0;
}
