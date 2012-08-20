//Result:	wizmann	2454	Accepted	240K	32MS	C++	1276B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

#define print(x) cout<<x<<endl

typedef struct node
{
	int val,nr,st;

	inline void setnode(int a,int b)
	{
		val=a;nr=b;
	}
	inline void setst(int s){st=s;}
	
	friend bool operator < (const node &a,const node &b)
	{
		return a.val<b.val;
	}
}node;

int n;


node array[600];
int sum[4];
char visit[600];

int main()
{
	freopen("input.txt","r",stdin);
	srand(time(NULL));
	int t;
	scanf("%d",&n);
	for(int i=0;i<3*n;i++)
	{
		scanf("%d",&t);
		array[i].setnode(t,i+1);
	}
	sort(array,array+3*n);
	for(int i=0;i<n;i++) print(array[i].nr);
	for(int i=0;i<(n>>4)+5500;i++)
	{
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++)
		{
			int t=rand()%(2*n)+n;
			if(!visit[t])
			{
				visit[t]=1;
				array[t].setst(1);
			}
			else i--;
		}
		t=0;
		for(int i=0;i<2;i++)
		{
			int sum=0;
			for(int j=n;j<3*n;j++)
			{
				if(visit[j]==i) sum+=array[j].val;
			}
			if(sum>500*n) t++;
		}
		if(t==2) break;
	}
	for(int i=0;i<2;i++)
	{
		t=0;
		for(int j=n;j<3*n;j++)
		{
			if(visit[j]==i)
			{
				print(array[j].nr);
				t+=array[j].val;
			}
		}
		print(t);
	}
	return 0;
}
	
	
