//Result:1180	Accepted	100MS	26156K	G++	 1952B	2012-06-15 00:57:56
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdlib>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 23456789
#define QUEUE 500000

struct node
{
	int num;
	int step;
	node(){}
	node(int i_num,int i_step)
	{
		num=i_num;
		step=i_step;
	}
	
	friend bool operator < (const node& a,const node& b)
	{
		return a.num<b.num;
	}
};

char visit[SIZE];
const int BEGIN=12348765;
node queue[QUEUE];
int front,rear;
int ind;
node mark[QUEUE];

inline int make1(int x)
{
	int a=x/10000;
	int b=x%10000;

	return b*10000+a;
}

inline int make2(int x)
{
	int a=x/10000;
	a=a/10+(a%10)*1000;
	int b=x%10000;
	b=b/10+(b%10)*1000;
	return a*10000+b;
}

inline int make3(int x)
{
	int a=x/10000;
	int b=x%10000;

	int eins=(a/100)%10;
	a-=eins*100;
	int zwei=(a/10)%10;
	a-=zwei*10;
	int drei=(b/100)%10;
	b-=drei*100;
	int vier=(b/10)%10;
	b-=vier*10;

	a+=drei*100;
	a+=eins*10;
	b+=vier*100;
	b+=zwei*10;
	return a*10000+b;
}

inline void q_push(const node& a)
{
	queue[rear++]=a;
}

inline void q_pop()
{
	front++;
}

inline bool q_empty()
{
	return front==rear;
}

inline node q_front()
{
	return queue[front];
}

int bfs()
{
	front=rear=0;
	q_push(node(BEGIN,0));
	while(!q_empty())
	{
		node now=q_front();
		q_pop();
		if(visit[now.num%SIZE]) continue;
		else
		{
			visit[now.num%SIZE]=1;
			mark[ind++]=now;
		}
		
		int next_step=now.step+1;
		q_push(node(make1(now.num),next_step));
		q_push(node(make2(now.num),next_step));
		q_push(node(make3(now.num),next_step));
	}
	return -1;
}


int main()
{
	freopen("input.txt","r",stdin);
	int now;
	ind=0;
	bfs();
	sort(mark,mark+ind);
	while(scanf("%d",&now)!=EOF)
	{
		node* ptr=lower_bound(mark,mark+ind,node(now,-1));
		if(ptr->num==now) printf("%d\n",ptr->step);
		else printf("-1\n");
	}
	return 0;
}
