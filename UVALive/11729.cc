//Result:Wizmann	UVA 11729	Accepted	0 KB	36 ms	C++ 4.5.3	708 B	2013-01-15 22:11:19
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

struct task
{
	int talk,exec;
	task(){}
	task(int italk,int iexec)
	{
		talk=italk;
		exec=iexec;
	}
	friend bool operator < (const task& a,const task& b)
	{
		return a.exec>b.exec;
	}
};

task job[SIZE];
int n;

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,cas=1;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			job[i]=task(a,b);
		}
		sort(job,job+n);
		int s,ans;
		s=ans=0;
		for(int i=0;i<n;i++)
		{
			s+=job[i].talk;
			ans=max(ans,s+job[i].exec);
		}
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}
	
