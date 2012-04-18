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
		
		double speed=LEN;
		for(int i=0;i<(int)upper.size();i++)
		{
			upper[i].forward(speed);
			speed=min(speed,LEN/upper[i].pace);
			if(upper[0].dis+eps>=LEN)
			{
				node now=upper[0];
				upper.pop_front();
				right.push(now);
				i--;
			}
		}

		speed=LEN;
		for(int i=0;i<(int)lower.size();i++)
		{
			lower[i].forward(speed);
			speed=min(speed,LEN/upper[i].pace);
			if(lower[0].dis+eps>=LEN)
			{
				node now=lower[0];
				lower.pop_front();
				left.push(now);
				i--;
			}
		}

		while(!left.empty())
		{
			node now=left.top();
			left.pop();
			now.dis=0;
			now.loop--;
			if(now.loop>=0) upper.push_back(now);
			else remain--;
		}
		while(!right.empty())
		{
			node now=right.top();
			right.pop();
			now.dis=0;
			lower.push_back(now);
		}
		if(remain) ans++;
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
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



