//Result:2012-08-22 15:04:59	Accepted	4381	140MS	512K	1544 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define INF 1<<28

struct cmd
{
	int a,b,c;
	cmd(){}
	cmd(int ia,int ib,int ic)
	{
		a=ia;b=ib;c=ic;
	}
	friend bool operator < (const cmd &ca,const cmd &cb)
	{
		return ca.b<cb.b;
	}
};

int n,m;
int dpl[SIZE],dpr[SIZE];

void makeDP(int a,int x,int *dp)
{
	for(int i=a;i>=0;i--)
	{
		if(dp[i]<INF) 
		{
			if(i+x>a) continue;
			else
			{
				dp[i+x]=min(dp[i]+1,dp[i+x]);
			}
		}
	}
}

void slove()
{
	int minStep=INF,maxDis=-INF;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i+j<=n)
			{
				if(dpl[i]<INF && dpr[j]<INF && i+j>maxDis)
				{
					maxDis=i+j;
					minStep=dpl[i]+dpr[j];
				}
				else if(dpl[i]<INF && dpr[j]<INF && i+j>=maxDis)
				{
					minStep=min(minStep,dpl[i]+dpr[j]);
				}
					
			}
		}
	}
	printf("%d %d\n",maxDis,minStep);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cmd array[SIZE];
	int T,a,b,c,cas=1;
	input(T);
	while(T--)
	{
		printf("Case %d: ",cas++);
		input(n>>m);
		fill(dpl,dpl+SIZE,INF);
		fill(dpr,dpr+SIZE,INF);
		dpl[0]=dpr[0]=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a==2) b=n-b+1;
			array[i]=cmd(a,b,c);
		}
		sort(array,array+m);
		for(int i=0;i<m;i++)
		{
			if(array[i].a==1) makeDP(array[i].b,array[i].c,dpl);
			else makeDP(array[i].b,array[i].c,dpr);
		}
		slove();
	}
	return 0;
}
