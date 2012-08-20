//Result:wizmann	1456	Accepted	832K	641MS	G++	1138B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10100
#define INF 1<<25

struct node
{
	int day,val;

	node(){}
	node(int i_day,int i_val)
	{
		day=i_day;
		val=i_val;
	}
	
	friend bool operator < (const node& a,const node& b)
	{
		if(a.day!=b.day) return a.day>b.day;
		else return a.val>b.val;
	}
};

node array[SIZE];
int n;
char visit[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		memset(visit,0,sizeof(visit));
		int ans=0;
		int tt=-INF;
		int day,val;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&val,&day);
			array[i]=node(day,val);
			tt=max(tt,day);
		}
		int ind=0;
		sort(array,array+n);
		//print("DAY: "<<tt);
		for(int i=tt;i>=1;i--)
		{
			int maxval=-INF;
			int pos=-1;
			for(int j=ind;array[j].day>=i;j++)
			{
				if(!visit[j] && array[j].val>maxval)
				{
					maxval=array[j].val;
					pos=j;
				}
			}
			if(pos==-1) continue;
			ans+=maxval;
			visit[pos]=1;
		}
		print(ans);
	}
	return 0;
}
			

	
