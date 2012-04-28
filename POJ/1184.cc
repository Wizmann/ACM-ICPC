//Result：wizmann	1184	Accepted	4648K	32MS	G++	2598B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000000
#define INF 1<<25

/*
* 0: 0
* 1: 0, 1
* 2: 0, 1, 2
* 3: 0, 1, 2, 3
* 4: 0, 1, 2, 3, 4
* 5: 0, 5
* 6: 0, 1, 5
* 7: 0, 1, 2, 5
* 8: 0, 1, 2, 3, 5
* 9: 0, 1, 2, 3, 4, 5
*/
//光标移动只有这10种情况


struct node
{
	int state;
	int visit;
	int step;
};

int start,end,v[6];
bitset<12> hash[SIZE];

void toArray(int num,int *a)
{
	for(int i=5;i>=0;i--)
	{
		a[i]=num%10;
		num/=10;
	}
}

int toNum(int *a)
{
	int ans=0;
	for(int i=0;i<6;i++)
	{
		ans=ans*10+a[i];
	}
	return ans;
}

int swapArray(int p1,int p2,int *a)
{
	swap(a[p1],a[p2]);
	int ans=toNum(a);
	swap(a[p2],a[p1]);
	return ans;
}

int check(node& in)
{
	//通过直接找求绝对值差的方法，加快搜索收敛的速度
	int a[6],res=0;
	toArray(in.state,a);
	int vi=in.visit;
	
	if(vi<=4)
	{
		for(int i=vi+1;i<6;i++)
		{  
			if(a[i]!=v[i]) return -1;
		}
		for(int i=0;i<=vi;i++)
		{
			res+=abs(a[i]-v[i]);
		}
	}
	else
	{
		vi-=5;
		for(int i=vi+1;i<5;i++)
		{   
			if(a[i]!=v[i]) return -1;
		}

		for(int i=0;i<=vi;i++)
		{
			res+=abs(a[i]-v[i]);   
		}
		res+=abs(a[5]-v[5]);
	}
	return res;
}

int bfs()
{
	queue<node> q;
	int ori,visit,tmp,a[6],res;
	int ans=INF;
	
	node p;
	p.state=start;
	p.step=0;
	p.visit=0;
	q.push(p);
	hash[start][0]=1;

	while(!q.empty())
	{
		node now=q.front();
		q.pop();

		ori=now.state;
		visit=now.visit;
		res=check(now);

		if(res!=-1) ans=min(ans,now.step+res);
		now.step++;
		if(now.step>=ans) continue;

		toArray(now.state,a);
		//(x,0)交换
		if(now.visit>0)
		{
			if(now.visit>=5) tmp=swapArray(0,now.visit-5,a);
			//如果visit状态超过9，就通过减5找到替换位置
			else tmp=swapArray(0,now.visit,a);

			if(!hash[tmp][now.visit])
			{
				now.state=tmp;
				q.push(now);
				hash[tmp][now.visit]=1;
			}
		}

		//(x,5)交换
		if(now.visit<5)
		{
			tmp=swapArray(5,now.visit,a);
			now.visit+=5;
		}
		else tmp=swapArray(5,now.visit-5,a);

		if(!hash[tmp][now.visit])
		{
			now.state=tmp;			   
			q.push(now);
			hash[tmp][now.visit]=1;
		}	   

		//右移
		now.state=ori;
		now.visit=visit;
		if(now.visit<9)
		{
			now.visit++;
			if(!hash[now.state][now.visit]) q.push(now);
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	input(start>>end);
	toArray(end, v);
	print(bfs());
	return 0;
}
