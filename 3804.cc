#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define LEN 1e5
#define eps 1e-4
#define SIZE 55

struct node
{
	int loop,pace;
	double dis;

	node(){}
	node(int i_loop,int i_pace)
	{
		loop=i_loop;
		pace=i_pace;
		dis=0;
	}

	void forward(double pre)
	{
		dis+=min(pre,LEN/pace);
	}

	friend bool operator < (const node& a,const node& b)
	{
		return a.pace>b.pace;
	}
};

int n;
node people[SIZE];

int slove()
{
	/*
	   |   UPPER     |
	  L|*************|R
	  E|             |I
	  F|   LOwER     |G
	  T|*************|H
	   |             |T
	*/
	int ans=0;
	int remain=n;
	priority_queue<node> left,right;
	deque<node> upper,lower;
	for(int i=0;i<n;i++)
	{
		left.push(people[i]);
	}
	while(remain)
	{
		int sz;
		sz=upper.size();
		double speed=LEN;
		for(int i=0;i<sz;i++)
		{
			upper[i].forward(speed);
			speed=min(speed,LEN/upper[i].pace);
			if(upper[i].dis+eps>LEN)
			{
				node now=upper[i];
				upper.pop_front();
				right.push(now);
			}
		}

		sz=lower.size();
		speed=LEN;
		for(int i=0;i<sz;i++)
		{
			lower[i].forward(speed);
			speed=min(speed,LEN/upper[i].pace);
			if(lower[i].dis+eps>LEN)
			{
				node now=lower[i];
				lower.pop_front();
				left.push(now);
			}
		}

		while(!left.empty())
		{
			node now=left.top();
			now.dis=0;
			now.loop--;
			if(now.loop>=0) upper.push_front(now);
			else remain--;
		}
		while(!right.empty())
		{
			node now=right.top();
			now.dis=0;
			lower.push_front(now);
		}
		ans++;
	}
	return ans;
}

int main()
{
	int a,b;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			people[i]=node(b,a);
		}
		print(slove());
	}
	return 0;
}



