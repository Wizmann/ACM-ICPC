//Result:wizmann	1042	Accepted	736K	250MS	G++	1537B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32

struct node
{
	int fish,lake;

	node(){}
	node(int i_fish,int i_lake)
	{
		fish=i_fish;
		lake=i_lake;
	}
	
	friend bool operator < (const node& a,const node& b)
	{
		if(a.fish==b.fish) return a.lake>b.lake;
		else return a.fish<b.fish;
	}
};

int n,h;
int f[SIZE],d[SIZE],t[SIZE];
int ans[SIZE];
int res;

void slove(int end)
{
	priority_queue<node> pq;
	int time=h;
	for(int i=0;i<end;i++) time-=t[i];
	int spent[SIZE];
	memset(spent,0,sizeof(spent));
	int fish=0;

	for(int i=0;i<=end;i++)
	{
		pq.push(node(f[i],i));
	}
	for(int i=0;i<time;i++)
	{
		node now=pq.top();
		fish+=now.fish;
		pq.pop();
		spent[now.lake]++;

		int v=now.fish-d[now.lake];
		if(v>0) pq.push(node(v,now.lake));
		else pq.push(node(0,now.lake));
	}
	if(fish>res)
	{
		res=fish;
		for(int i=0;i<n;i++) ans[i]=spent[i];
	}
}



int main()
{
	freopen("input.txt","r",stdin);
	while(input(n) && n)
	{
		input(h);
		h*=12;
		memset(ans,0,sizeof(ans));
		res=-1;
		for(int i=0;i<n;i++) scanf("%d",&f[i]);
		for(int i=0;i<n;i++) scanf("%d",&d[i]);
		for(int i=0;i<n-1;i++) scanf("%d",&t[i]);

		for(int i=0;i<n;i++) slove(i);
		for(int i=0;i<n;i++) 
		{
			if(i) printf(", ");
			printf("%d",ans[i]*5);
		}
		puts("");
		printf("Number of fish expected: %d\n",res);
		puts("");
	}
	return 0;
}


