//Result:1911	Accepted	21MS	536K	G++	 1978B	2012-07-16 15:12:05	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20480
#define VERTEX 1024
#define INF 1<<30

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
};

struct gold
{
	int val,num;
	bool rich;
	gold(){}
	gold(int i_val,int i_num,bool i_rich)
	{
		val=i_val;num=i_num;rich=i_rich;
	}
	friend bool operator < (const gold &a,const gold &b)
	{
		if(a.val!=b.val) return a.val>b.val;
		else return a.rich;
	}
};

point polygen[VERTEX+5];
gold money[SIZE+5];
int nrich,npoor,n,sz;

int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	else if(b==0) return a;
	else if(a%b==0) return b;
	else return gcd(b,a%b);
}

int how_much_points_in_the_polygen()
{
	int edgePoint=0;
	int area=0;
	for(int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		area+=polygen[i].x*polygen[j].y-polygen[i].y*polygen[j].x;
		edgePoint+=gcd(abs(polygen[i].x-polygen[j].x),abs(polygen[i].y-polygen[j].y));
	}
	area=abs(area);
	return (area-edgePoint+2)/2;
}

int judge(int res)
{
	int car=0;
	for(int i=0;i<sz;i++)
	{
		car+=money[i].num;
		if(car>=res)
		{
			if(money[i].rich) return money[i].val+1;
			else return money[i].val;
		}
	}
	return 1;		
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,T;
	input(T);
	while(T--)
	{
		input(nrich>>npoor>>n);
		sz=nrich+npoor;
		for(int i=0;i<sz;i++)
		{
			scanf("%d%d",&a,&b);
			if(i<nrich) money[i]=gold(a,b,true);
			else money[i]=gold(a,b,false);
		}
		sort(money,money+sz);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			polygen[i]=point(a,b);
		}
		
		int res=how_much_points_in_the_polygen();
		//int left=1,right=maxval+1;
		//bool mark=false;
		if(res<=0) print(-1);
		else printf("%d\n",judge(res));
	}
	return 0;
}	
