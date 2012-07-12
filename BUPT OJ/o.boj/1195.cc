//Result:1195 	Accepted	643MS	12868K	G++	1467B	2011-12-07 14:22:22	Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100005
#define INF 1<<25

char in[SIZE];
int n;


int mini[SIZE][32];

int log2(int x)
{
	for(int i=31;i>=0;i--)
	{
		if(x&(1<<i)) return i;
	}
	return 0;
}
			

void initRMQ()
{
	int m=log2(n);
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			mini[j][i]=mini[j][i-1];
			if(j+(1<<(i-1))<=n) mini[j][i]=min(mini[j][i],mini[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l,int r)
{
	int m=log2(r-l+1);
	return min(mini[l][m],mini[r-(1<<m)+1][m]);
}



int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n) && n)
	{
		memset(in,0,sizeof(in));
		memset(mini,0,sizeof(mini));
		int tn=n;
		n<<=1;
		for(int i=1;i<=tn;i++)
		{
			scanf("%d%d",&a,&b);
			mini[i][0]=mini[i+tn][0]=a-b;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(i!=1) mini[i][0]+=mini[i-1][0];
		}
		initRMQ();
		
		int ans=0;		
		for(int i=1;i<=tn;i++)
		{
			int t=query(i,i+tn);
			//print(t);
			if(i!=1) t-=mini[i-1][0];
			
			if(t>=0)
			{
				in[i]=1;
				ans++;
			}
		}
		
		printf("%d\n",ans);
		bool flag=true;
		for(int i=1;i<=tn;i++)
		{
			if(in[i])
			{
				if(flag)
				{
					printf("%d",i);
					flag=false;
				}
				else printf(" %d",i);
			}
		}
		puts("");
	}
	return 0;
}
			

			
