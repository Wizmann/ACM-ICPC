//Result: 992554	Wizmann	0.144	C++	2012-04-19 06:21:48
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 55
#define INF 1<<25

struct node
{
	int loop,pace;
	int id;

	node(){}
	node(int i_id,int i_loop,int i_pace)
	{
		id=i_id;
		loop=i_loop;
		pace=i_pace;
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
	   |   UPPER(0)  |
	  L|*************|R
	  E|             |I
	  F|   LOwER(1)  |G
	  T|*************|H
	   |             |T
	*/
	int ans=0;
	deque<node> track[2];
	priority_queue<node> rest;
	for(int i=0;i<n;i++) rest.push(people[i]);
	while(!rest.empty())
	{
		track[0].push_back(rest.top());
		rest.pop();
	}
	while(1)
	{
		if(track[0].empty() && track[1].empty()) break;
		
		int cost=INF;
		if(!track[0].empty()) cost=min(cost,track[0][0].pace);
		if(!track[1].empty()) cost=min(cost,track[1][0].pace);
		
		ans+=cost;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<(int)track[i].size();j++)
			{
				track[i][j].pace-=cost;
			}
		}
		
		for(int i=0;i<2;i++)
		{
			while(!track[i].empty() && track[i][0].pace==0)
			{
				node now=track[i][0];
				now.pace=people[now.id].pace;
				if(i==1) now.loop--;
				if(now.loop>0) rest.push(now);
				track[i].pop_front();
			}
			
			int htime=-1;
			if(!track[i^1].empty()) htime=track[i^1][0].pace;
			for(int j=0;j<(int)track[i^1].size();j++)
			{
				track[i^1][j].pace=max(htime,track[i^1][j].pace);
			}
			while(!rest.empty())
			{
				node now=rest.top();
				rest.pop();
				now.pace=max(now.pace,htime);
				track[i^1].push_back(now);
			}
		}
	}
	return ans;
}


int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int a,b;
	while(input(n) && n)
	{
		memset(people,0,sizeof(people));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			people[i]=node(i,b,a);
		}
		printf("%d\n",slove());
	}
	return 0;
}
